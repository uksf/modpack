use std::collections::VecDeque;
use std::sync::atomic::{AtomicUsize, Ordering};
use std::sync::mpsc::{self, RecvTimeoutError, Sender};
use std::sync::{Arc, Mutex};
use std::thread;
use std::time::{Duration, Instant};

use crate::config;
use crate::transport::{try_send, SendResult, ACKNOWLEDGED_REQUEST_TIMEOUT, ORDINARY_REQUEST_TIMEOUT};
use crate::delivery::{event_type, is_acknowledged_type, next_seq, set_outcome, Outcome};

const MAX_QUEUE_SIZE: usize = 1000;
pub const ACKNOWLEDGED_GIVE_UP_AFTER: Duration = Duration::from_secs(120);
const FLUSH_TIMEOUT: Duration = Duration::from_secs(10);
const ACKNOWLEDGED_MAX_BACKOFF: Duration = Duration::from_secs(5);

enum Message {
    Enqueue(u64, String, String),
    Flush(Sender<()>),
}

struct PendingEvent {
    seq: u64,
    body: String,
    enqueue_at: String,
    queued_at: Instant,
    next_attempt: Instant,
    backoff: Duration,
}

pub struct RetryQueue {
    url: String,
    capacity: usize,
    base_backoff: Duration,
    give_up_after: Option<Duration>,
    inbound: Mutex<Option<Sender<Message>>>,
    len: AtomicUsize,
}

impl RetryQueue {
    pub fn new(url: String, capacity: usize, base_backoff: Duration) -> Arc<Self> {
        Self::build(url, capacity, base_backoff, None)
    }

    pub fn acknowledged(url: String, capacity: usize, base_backoff: Duration, give_up_after: Duration) -> Arc<Self> {
        Self::build(url, capacity, base_backoff, Some(give_up_after))
    }

    fn build(url: String, capacity: usize, base_backoff: Duration, give_up_after: Option<Duration>) -> Arc<Self> {
        Arc::new(Self {
            url,
            capacity,
            base_backoff,
            give_up_after,
            inbound: Mutex::new(None),
            len: AtomicUsize::new(0),
        })
    }

    fn tracked(&self) -> bool {
        self.give_up_after.is_some()
    }

    fn finish(&self, pending: &PendingEvent, outcome: Outcome) {
        if !self.tracked() {
            return;
        }
        set_outcome(pending.seq, outcome);
        match outcome {
            Outcome::Lost => log::error!(
                "{} lost after {} s: seq {}, enqueued {}",
                event_type(&pending.body),
                pending.queued_at.elapsed().as_secs(),
                pending.seq,
                pending.enqueue_at
            ),
            Outcome::Rejected => log::error!("{} rejected by the API: seq {}", event_type(&pending.body), pending.seq),
            _ => {}
        }
    }

    pub fn start(self: &Arc<Self>) {
        let (sender, receiver) = mpsc::channel::<Message>();
        if let Ok(mut guard) = self.inbound.lock() {
            *guard = Some(sender);
        }

        let this = Arc::clone(self);
        thread::spawn(move || {
            let mut buffer: VecDeque<PendingEvent> = VecDeque::with_capacity(this.capacity);
            let mut pending_flush_acks: Vec<Sender<()>> = Vec::new();

            loop {
                let timeout = match buffer.front() {
                    Some(front) => front.next_attempt.saturating_duration_since(Instant::now()).max(Duration::from_millis(1)),
                    None => Duration::from_secs(1),
                };

                match receiver.recv_timeout(timeout) {
                    Ok(Message::Enqueue(seq, body, enqueue_at)) => {
                        if buffer.len() >= this.capacity {
                            log::warn!("Retry queue full ({}), dropping oldest event", this.capacity);
                            if let Some(dropped) = buffer.pop_front() {
                                this.finish(&dropped, Outcome::Lost);
                            }
                        }
                        let now = Instant::now();
                        buffer.push_back(PendingEvent { seq, body, enqueue_at, queued_at: now, next_attempt: now, backoff: this.base_backoff });
                        this.len.store(buffer.len(), Ordering::Relaxed);
                    }
                    Ok(Message::Flush(ack)) => pending_flush_acks.push(ack),
                    Err(RecvTimeoutError::Timeout) => {}
                    Err(RecvTimeoutError::Disconnected) => {
                        for pending in buffer.drain(..) {
                            this.finish(&pending, Outcome::Lost);
                        }
                        this.len.store(0, Ordering::Relaxed);
                        break;
                    }
                }

                this.send_due(&mut buffer);

                if !pending_flush_acks.is_empty() && buffer.is_empty() {
                    for ack in pending_flush_acks.drain(..) {
                        let _ = ack.send(());
                    }
                }
            }
        });
    }

    fn send_due(&self, buffer: &mut VecDeque<PendingEvent>) {
        while let Some(front) = buffer.front()
            && front.next_attempt <= Instant::now()
        {
            let Some(pending) = buffer.pop_front() else { break };
            self.len.store(buffer.len(), Ordering::Relaxed);

            let deadline = self.give_up_after.map(|limit| pending.queued_at + limit);
            if deadline.is_some_and(|deadline| Instant::now() >= deadline) {
                self.finish(&pending, Outcome::Lost);
                continue;
            }

            let timeout = deadline.map_or(ORDINARY_REQUEST_TIMEOUT, |deadline| {
                deadline.saturating_duration_since(Instant::now()).clamp(Duration::from_secs(1), ACKNOWLEDGED_REQUEST_TIMEOUT)
            });
            match try_send(&self.url, &pending.body, &pending.enqueue_at, timeout) {
                SendResult::Delivered => {
                    self.finish(&pending, Outcome::Delivered);
                    continue;
                }
                SendResult::Rejected => {
                    self.finish(&pending, Outcome::Rejected);
                    continue;
                }
                SendResult::Failed => {}
            }

            let backoff = if self.tracked() { next_backoff(pending.backoff).min(ACKNOWLEDGED_MAX_BACKOFF) } else { next_backoff(pending.backoff) };
            let retry_at = Instant::now() + backoff;
            let next_attempt = deadline.map_or(retry_at, |deadline| retry_at.min(deadline));
            buffer.push_front(PendingEvent { next_attempt, backoff, ..pending });
            self.len.store(buffer.len(), Ordering::Relaxed);
            break;
        }
    }

    pub fn enqueue(&self, seq: u64, body: String, enqueue_at: String) {
        if self.tracked() {
            set_outcome(seq, Outcome::Pending);
        }
        if let Ok(guard) = self.inbound.lock()
            && let Some(sender) = guard.as_ref()
        {
            let _ = sender.send(Message::Enqueue(seq, body, enqueue_at));
        }
    }

    pub fn flush(&self, timeout: Duration) -> bool {
        let (ack_tx, ack_rx) = mpsc::channel();
        let sent = self
            .inbound
            .lock()
            .ok()
            .and_then(|guard| guard.as_ref().map(|sender| sender.send(Message::Flush(ack_tx)).is_ok()))
            .unwrap_or(false);
        sent && ack_rx.recv_timeout(timeout).is_ok()
    }

    pub fn stop(&self) {
        if let Ok(mut guard) = self.inbound.lock() {
            *guard = None;
        }
    }

    #[cfg(test)]
    pub fn buffer_len(&self) -> usize {
        self.len.load(Ordering::Relaxed)
    }
}

fn next_backoff(current: Duration) -> Duration {
    [2, 5, 10, 30, 60]
        .into_iter()
        .map(Duration::from_secs)
        .find(|step| current < *step)
        .unwrap_or(Duration::from_secs(60))
}

fn extract_server_status_data(body: &str) -> Option<&str> {
    const PREFIX: &str = "[\"server_status\",";
    let inner = body.trim().strip_prefix(PREFIX)?.strip_suffix(']')?;
    Some(inner.trim())
}

struct Lanes {
    ordinary: Arc<RetryQueue>,
    acknowledged: Arc<RetryQueue>,
}

static LANES: Mutex<Option<Lanes>> = Mutex::new(None);

pub fn start() {
    let url = format!("{}/gameservers/events", config::api_base_url());
    log::info!("Sender starting, posting to {url}");
    let ordinary = RetryQueue::new(url.clone(), MAX_QUEUE_SIZE, Duration::from_secs(1));
    let acknowledged = RetryQueue::acknowledged(url, MAX_QUEUE_SIZE, Duration::from_secs(1), ACKNOWLEDGED_GIVE_UP_AFTER);
    ordinary.start();
    acknowledged.start();
    if let Ok(mut guard) = LANES.lock() {
        *guard = Some(Lanes { ordinary, acknowledged });
    }
}

pub fn stop() {
    if let Ok(mut guard) = LANES.lock()
        && let Some(lanes) = guard.take()
    {
        lanes.ordinary.stop();
        lanes.acknowledged.stop();
    }
}

pub fn queue_event(body: &str) -> u64 {
    if let Some(data_sqf) = extract_server_status_data(body) {
        crate::status::cache_status(data_sqf);
    }

    let seq = next_seq();
    let enqueue_at = chrono::Utc::now().format("%Y-%m-%dT%H:%M:%S%.3fZ").to_string();

    if let Ok(guard) = LANES.lock()
        && let Some(lanes) = guard.as_ref()
    {
        let lane = if is_acknowledged_type(event_type(body)) { &lanes.acknowledged } else { &lanes.ordinary };
        lane.enqueue(seq, body.to_string(), enqueue_at);
    }
    seq
}

pub fn flush() -> bool {
    let Some((ordinary, acknowledged)) = LANES
        .lock()
        .ok()
        .and_then(|guard| guard.as_ref().map(|lanes| (Arc::clone(&lanes.ordinary), Arc::clone(&lanes.acknowledged))))
    else {
        return false;
    };
    let deadline = Instant::now() + FLUSH_TIMEOUT;
    acknowledged.flush(FLUSH_TIMEOUT) && ordinary.flush(deadline.saturating_duration_since(Instant::now()))
}

#[cfg(test)]
#[path = "sender_tests.rs"]
mod tests;
