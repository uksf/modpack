use std::collections::VecDeque;
use std::sync::atomic::{AtomicUsize, Ordering};
use std::sync::mpsc::{self, Receiver, RecvTimeoutError, Sender};
use std::sync::{Arc, Mutex, OnceLock};
use std::thread;
use std::time::{Duration, Instant};

use crate::delivery::{event_type, set_outcome, Outcome};
use crate::transport::{try_send, SendResult, ACKNOWLEDGED_REQUEST_TIMEOUT, ORDINARY_REQUEST_TIMEOUT};

pub use crate::lanes::{flush, queue_event, start, stop};

pub const MAX_QUEUE_SIZE: usize = 1000;
pub const ACKNOWLEDGED_GIVE_UP_AFTER: Duration = Duration::from_secs(120);
pub const FLUSH_TIMEOUT: Duration = Duration::from_secs(10);
const ACKNOWLEDGED_MAX_BACKOFF: Duration = Duration::from_secs(5);
const ORDINARY_DRAIN_AFTER_STOP: Duration = Duration::from_secs(10);

enum Message {
    Enqueue(PendingEvent),
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

type StoppedAt = Arc<OnceLock<Instant>>;

struct Worker {
    inbound: Sender<Message>,
    stopped_at: StoppedAt,
}

pub struct RetryQueue {
    url: String,
    capacity: usize,
    base_backoff: Duration,
    give_up_after: Option<Duration>,
    drain_after_stop: Duration,
    worker: Mutex<Option<Worker>>,
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
            drain_after_stop: ORDINARY_DRAIN_AFTER_STOP,
            worker: Mutex::new(None),
            len: AtomicUsize::new(0),
        })
    }

    #[cfg(test)]
    pub fn draining_for(url: String, capacity: usize, base_backoff: Duration, drain_after_stop: Duration) -> Arc<Self> {
        let mut queue = Self::build(url, capacity, base_backoff, None);
        Arc::get_mut(&mut queue).expect("fresh queue").drain_after_stop = drain_after_stop;
        queue
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
        let (inbound, receiver) = mpsc::channel::<Message>();
        let stopped_at: StoppedAt = Arc::new(OnceLock::new());
        if let Ok(mut guard) = self.worker.lock() {
            *guard = Some(Worker { inbound, stopped_at: Arc::clone(&stopped_at) });
        }
        let this = Arc::clone(self);
        thread::spawn(move || this.run(receiver, &stopped_at));
    }

    fn run(&self, receiver: Receiver<Message>, stopped_at: &OnceLock<Instant>) {
        let mut buffer: VecDeque<PendingEvent> = VecDeque::with_capacity(self.capacity);
        let mut pending_flush_acks: Vec<Sender<()>> = Vec::new();

        loop {
            let timeout = self.next_wake(&buffer).map_or(Duration::from_secs(1), |at| at.saturating_duration_since(Instant::now()).max(Duration::from_millis(1)));
            match receiver.recv_timeout(timeout) {
                Ok(Message::Enqueue(pending)) => {
                    if buffer.len() >= self.capacity {
                        log::warn!("Retry queue full ({}), dropping oldest event", self.capacity);
                        if let Some(dropped) = buffer.pop_front() {
                            self.finish(&dropped, Outcome::Lost);
                        }
                    }
                    buffer.push_back(pending);
                    self.len.store(buffer.len(), Ordering::Relaxed);
                }
                Ok(Message::Flush(ack)) => pending_flush_acks.push(ack),
                Err(RecvTimeoutError::Timeout) => {}
                Err(RecvTimeoutError::Disconnected) => break,
            }

            self.send_due(&mut buffer, stopped_at);

            if !pending_flush_acks.is_empty() && buffer.is_empty() {
                for ack in pending_flush_acks.drain(..) {
                    let _ = ack.send(());
                }
            }
        }

        if !self.tracked() {
            self.drain_after_stop(&mut buffer, stopped_at);
        }
        for pending in buffer.drain(..) {
            self.finish(&pending, Outcome::Lost);
        }
        self.len.store(0, Ordering::Relaxed);
    }

    fn drain_after_stop(&self, buffer: &mut VecDeque<PendingEvent>, stopped_at: &OnceLock<Instant>) {
        let deadline = *stopped_at.get_or_init(Instant::now) + self.drain_after_stop;
        while let Some(wake) = self.next_wake(buffer)
            && Instant::now() < deadline
        {
            thread::sleep(wake.min(deadline).saturating_duration_since(Instant::now()));
            self.send_due(buffer, stopped_at);
        }
        if !buffer.is_empty() {
            log::warn!("Dropping {} undelivered events {} s after stop", buffer.len(), self.drain_after_stop.as_secs());
        }
    }

    fn send_due(&self, buffer: &mut VecDeque<PendingEvent>, stopped_at: &OnceLock<Instant>) {
        let drain_deadline = stopped_at.get().map(|stopped| *stopped + self.drain_after_stop);
        for _ in 0..buffer.len() {
            let now = Instant::now();
            if !self.tracked() && drain_deadline.is_some_and(|deadline| now >= deadline) {
                break;
            }
            let Some(pending) = buffer.pop_front() else { break };
            let deadline = self.give_up_after.map(|limit| pending.queued_at + limit);
            if self.tracked() && (stopped_at.get().is_some() || deadline.is_some_and(|deadline| now >= deadline)) {
                self.finish(&pending, Outcome::Lost);
                continue;
            }
            if pending.next_attempt > now {
                if self.tracked() {
                    buffer.push_back(pending);
                    continue;
                }
                buffer.push_front(pending);
                break;
            }
            self.len.store(buffer.len(), Ordering::Relaxed);

            let timeout = match (deadline, drain_deadline) {
                (Some(deadline), _) => deadline.saturating_duration_since(now).min(ACKNOWLEDGED_REQUEST_TIMEOUT),
                (None, Some(drain)) => drain.saturating_duration_since(now).min(ORDINARY_REQUEST_TIMEOUT),
                (None, None) => ORDINARY_REQUEST_TIMEOUT,
            };
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
            let retry = PendingEvent { next_attempt, backoff, ..pending };
            if self.tracked() {
                buffer.push_back(retry);
                continue;
            }
            buffer.push_front(retry);
            break;
        }
        self.len.store(buffer.len(), Ordering::Relaxed);
    }

    pub fn enqueue(&self, seq: u64, body: String, enqueue_at: String) {
        if self.tracked() {
            set_outcome(seq, Outcome::Pending);
        }
        let now = Instant::now();
        let pending = PendingEvent { seq, body, enqueue_at, queued_at: now, next_attempt: now, backoff: self.base_backoff };
        let sent = self.worker.lock().ok().and_then(|guard| guard.as_ref().map(|worker| worker.inbound.send(Message::Enqueue(pending)).is_ok()));
        if self.tracked() && sent != Some(true) {
            set_outcome(seq, Outcome::Lost);
        }
    }

    pub fn flush(&self, timeout: Duration) -> bool {
        let (ack_tx, ack_rx) = mpsc::channel();
        let sent = self
            .worker
            .lock()
            .ok()
            .and_then(|guard| guard.as_ref().map(|worker| worker.inbound.send(Message::Flush(ack_tx)).is_ok()))
            .unwrap_or(false);
        sent && ack_rx.recv_timeout(timeout).is_ok()
    }

    pub fn stop(&self) {
        if let Ok(mut guard) = self.worker.lock()
            && let Some(worker) = guard.take()
        {
            let _ = worker.stopped_at.set(Instant::now());
        }
    }

    fn next_wake(&self, buffer: &VecDeque<PendingEvent>) -> Option<Instant> {
        if self.tracked() {
            return buffer.iter().map(|pending| pending.next_attempt).min();
        }
        buffer.front().map(|pending| pending.next_attempt)
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

#[cfg(test)]
#[path = "sender_tests.rs"]
mod tests;

#[cfg(test)]
#[path = "sender_lifecycle_tests.rs"]
mod lifecycle_tests;
