use std::collections::VecDeque;
use std::sync::atomic::{AtomicUsize, Ordering};
use std::sync::mpsc::{self, RecvTimeoutError, Sender};
use std::sync::{Arc, Mutex};
use std::thread;
use std::time::{Duration, Instant};

use crate::config;

const MAX_QUEUE_SIZE: usize = 1000;

enum Message {
    Enqueue(String, String),
    Flush(Sender<()>),
}

struct PendingEvent {
    body: String,
    enqueue_at: String,
    next_attempt: Instant,
    backoff: Duration,
}

pub struct RetryQueue {
    url: String,
    capacity: usize,
    base_backoff: Duration,
    inbound: Mutex<Option<Sender<Message>>>,
    len: AtomicUsize,
}

impl RetryQueue {
    pub fn new(url: String, capacity: usize, base_backoff: Duration) -> Arc<Self> {
        Arc::new(Self {
            url,
            capacity,
            base_backoff,
            inbound: Mutex::new(None),
            len: AtomicUsize::new(0),
        })
    }

    pub fn start(self: &Arc<Self>) {
        let (sender, receiver) = mpsc::channel::<Message>();
        if let Ok(mut guard) = self.inbound.lock() {
            *guard = Some(sender);
        }

        let this = Arc::clone(self);
        let url = this.url.clone();
        let capacity = this.capacity;
        let base_backoff = this.base_backoff;

        thread::spawn(move || {
            let mut buffer: VecDeque<PendingEvent> = VecDeque::with_capacity(capacity);
            let mut pending_flush_acks: Vec<Sender<()>> = Vec::new();

            loop {
                let timeout = match buffer.front() {
                    Some(front) => front.next_attempt.saturating_duration_since(Instant::now()).max(Duration::from_millis(1)),
                    None => Duration::from_secs(1),
                };

                match receiver.recv_timeout(timeout) {
                    Ok(Message::Enqueue(body, enqueue_at)) => {
                        if buffer.len() >= capacity {
                            log::warn!("Retry queue full ({capacity}), dropping oldest event");
                            buffer.pop_front();
                        }
                        buffer.push_back(PendingEvent {
                            body,
                            enqueue_at,
                            next_attempt: Instant::now(),
                            backoff: base_backoff,
                        });
                        this.len.store(buffer.len(), Ordering::Relaxed);
                    }
                    Ok(Message::Flush(ack)) => {
                        pending_flush_acks.push(ack);
                    }
                    Err(RecvTimeoutError::Timeout) => {}
                    Err(RecvTimeoutError::Disconnected) => break,
                }

                while let Some(front) = buffer.front()
                    && front.next_attempt <= Instant::now()
                {
                    let Some(pending) = buffer.pop_front() else { break };
                    this.len.store(buffer.len(), Ordering::Relaxed);

                    if try_send(&url, &pending) {
                        continue;
                    }

                    let new_backoff = next_backoff(pending.backoff);
                    let requeued = PendingEvent {
                        body: pending.body,
                        enqueue_at: pending.enqueue_at,
                        next_attempt: Instant::now() + new_backoff,
                        backoff: new_backoff,
                    };
                    buffer.push_front(requeued);
                    this.len.store(buffer.len(), Ordering::Relaxed);
                    break;
                }

                if !pending_flush_acks.is_empty() && buffer.is_empty() {
                    for ack in pending_flush_acks.drain(..) {
                        let _ = ack.send(());
                    }
                }
            }
        });
    }

    pub fn enqueue(&self, body: String, enqueue_at: String) {
        if let Ok(guard) = self.inbound.lock()
            && let Some(sender) = guard.as_ref()
        {
            let _ = sender.send(Message::Enqueue(body, enqueue_at));
        }
    }

    pub fn flush(&self) -> bool {
        let (ack_tx, ack_rx) = mpsc::channel();
        if let Ok(guard) = self.inbound.lock() {
            if let Some(sender) = guard.as_ref() {
                if sender.send(Message::Flush(ack_tx)).is_err() {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
        ack_rx.recv_timeout(Duration::from_secs(10)).is_ok()
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
    if current < Duration::from_secs(2) {
        Duration::from_secs(2)
    } else if current < Duration::from_secs(5) {
        Duration::from_secs(5)
    } else if current < Duration::from_secs(10) {
        Duration::from_secs(10)
    } else if current < Duration::from_secs(30) {
        Duration::from_secs(30)
    } else {
        Duration::from_secs(60)
    }
}

fn try_send(url: &str, pending: &PendingEvent) -> bool {
    let api_port = config::get_api_port();
    match ureq::post(url)
        .timeout(Duration::from_secs(5))
        .set("Content-Type", "text/plain; charset=utf-8")
        .set("X-Api-Port", &api_port.to_string())
        .set("X-Enqueued-At", &pending.enqueue_at)
        .send_string(&pending.body)
    {
        Ok(_) => true,
        Err(error) => {
            log::error!("Failed to send event (will retry): {error}");
            false
        }
    }
}

/// Top-level SQF event body is `[<type>,<data>]` per `str []`.
/// Detect a server_status event by matching the leading `["server_status",`
/// prefix and return the data substring (including trailing `]`).
fn extract_server_status_data(body: &str) -> Option<&str> {
    const PREFIX: &str = "[\"server_status\",";
    let trimmed = body.trim_start();
    if !trimmed.starts_with(PREFIX) {
        return None;
    }
    let after_prefix = &trimmed[PREFIX.len()..];
    // Strip the trailing `]` of the outer array.
    let end = after_prefix.rfind(']')?;
    let inner = after_prefix[..end].trim();
    Some(inner)
}

static QUEUE: Mutex<Option<Arc<RetryQueue>>> = Mutex::new(None);

pub fn start() {
    let url = format!("{}/gameservers/events", config::api_base_url());
    log::info!("Sender starting, posting to {url}");
    let queue = RetryQueue::new(url, MAX_QUEUE_SIZE, Duration::from_secs(1));
    queue.start();
    if let Ok(mut guard) = QUEUE.lock() {
        *guard = Some(queue);
    }
}

pub fn stop() {
    if let Ok(mut guard) = QUEUE.lock()
        && let Some(queue) = guard.take()
    {
        queue.stop();
    }
}

pub fn queue_event(body: &str) {
    if let Some(data_sqf) = extract_server_status_data(body) {
        crate::status::cache_status(data_sqf);
    }

    let enqueue_at = chrono::Utc::now().format("%Y-%m-%dT%H:%M:%S%.3fZ").to_string();

    if let Ok(guard) = QUEUE.lock()
        && let Some(queue) = guard.as_ref()
    {
        queue.enqueue(body.to_string(), enqueue_at);
    }
}

pub fn flush() -> bool {
    if let Ok(guard) = QUEUE.lock()
        && let Some(queue) = guard.as_ref()
    {
        return queue.flush();
    }
    false
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::sync::atomic::{AtomicU32, Ordering as AtomicOrdering};

    #[test]
    fn test_extract_server_status_data() {
        let body = r#"["server_status",[["map","Altis"],["players",5]]]"#;
        let result = extract_server_status_data(body);
        assert_eq!(result, Some(r#"[["map","Altis"],["players",5]]"#));
    }

    #[test]
    fn test_extract_server_status_data_with_whitespace() {
        let body = r#"  ["server_status", [["map","Altis"]]]  "#;
        let result = extract_server_status_data(body);
        assert_eq!(result, Some(r#"[["map","Altis"]]"#));
    }

    #[test]
    fn test_extract_server_status_data_wrong_type() {
        let body = r#"["mission_started",[["map","Altis"]]]"#;
        assert!(extract_server_status_data(body).is_none());
    }

    #[test]
    fn test_extract_server_status_data_malformed() {
        // No outer closing bracket — return None rather than panic.
        let body = r#"["server_status","incomplete"#;
        assert!(extract_server_status_data(body).is_none());
    }

    #[test]
    fn test_next_backoff_ramp() {
        assert_eq!(next_backoff(Duration::from_secs(1)), Duration::from_secs(2));
        assert_eq!(next_backoff(Duration::from_secs(2)), Duration::from_secs(5));
        assert_eq!(next_backoff(Duration::from_secs(5)), Duration::from_secs(10));
        assert_eq!(next_backoff(Duration::from_secs(10)), Duration::from_secs(30));
        assert_eq!(next_backoff(Duration::from_secs(30)), Duration::from_secs(60));
        assert_eq!(next_backoff(Duration::from_secs(60)), Duration::from_secs(60));
    }

    #[test]
    fn test_flush_when_not_started() {
        if let Ok(mut guard) = QUEUE.lock() {
            *guard = None;
        }
        assert!(!flush());
    }

    #[test]
    fn test_retry_queue_recovers_after_transient_failures() {
        config::store_api_port(2303);

        let server = tiny_http::Server::http("127.0.0.1:0").unwrap();
        let port = server.server_addr().to_ip().unwrap().port();
        let url = format!("http://127.0.0.1:{port}/gameservers/events");

        let counter = Arc::new(AtomicU32::new(0));
        let counter_clone = Arc::clone(&counter);

        let server_thread = thread::spawn(move || {
            for _ in 0..3 {
                let Ok(Some(request)) = server.recv_timeout(Duration::from_secs(15)) else {
                    return;
                };
                let n = counter_clone.fetch_add(1, AtomicOrdering::SeqCst);
                let status = if n < 2 { 500 } else { 200 };
                let _ = request.respond(tiny_http::Response::empty(status));
            }
        });

        let queue = RetryQueue::new(url, 1000, Duration::from_millis(50));
        queue.start();
        queue.enqueue(
            r#"["test",[["k",1]]]"#.to_string(),
            "2026-04-28T00:00:00.000Z".to_string(),
        );

        let deadline = Instant::now() + Duration::from_secs(20);
        while Instant::now() < deadline && counter.load(AtomicOrdering::SeqCst) < 3 {
            thread::sleep(Duration::from_millis(50));
        }

        let _ = server_thread.join();
        queue.stop();

        assert_eq!(counter.load(AtomicOrdering::SeqCst), 3);
    }

    #[test]
    fn test_retry_queue_overflow_drops_oldest() {
        let server = tiny_http::Server::http("127.0.0.1:0").unwrap();
        let port = server.server_addr().to_ip().unwrap().port();
        let stop = Arc::new(std::sync::atomic::AtomicBool::new(false));
        let stop_clone = Arc::clone(&stop);
        let server_thread = thread::spawn(move || {
            while !stop_clone.load(AtomicOrdering::SeqCst) {
                if let Ok(Some(request)) = server.recv_timeout(Duration::from_millis(50)) {
                    let _ = request.respond(tiny_http::Response::empty(500));
                }
            }
        });

        let url = format!("http://127.0.0.1:{port}/gameservers/events");
        let queue = RetryQueue::new(url, 3, Duration::from_secs(3600));
        queue.start();

        queue.enqueue(r#"["a",[]]"#.to_string(), "ts".to_string());
        queue.enqueue(r#"["b",[]]"#.to_string(), "ts".to_string());
        queue.enqueue(r#"["c",[]]"#.to_string(), "ts".to_string());
        queue.enqueue(r#"["d",[]]"#.to_string(), "ts".to_string());

        let deadline = Instant::now() + Duration::from_secs(5);
        while Instant::now() < deadline && queue.buffer_len() != 3 {
            thread::sleep(Duration::from_millis(50));
        }
        assert_eq!(queue.buffer_len(), 3);

        queue.stop();
        stop.store(true, AtomicOrdering::SeqCst);
        let _ = server_thread.join();
    }

    #[test]
    fn test_flush_returns_true_only_after_buffer_drains() {
        config::store_api_port(2303);
        let server = tiny_http::Server::http("127.0.0.1:0").unwrap();
        let port = server.server_addr().to_ip().unwrap().port();
        let url = format!("http://127.0.0.1:{port}/gameservers/events");

        thread::spawn(move || {
            for request in server.incoming_requests() {
                std::thread::sleep(std::time::Duration::from_millis(200));
                let _ = request.respond(tiny_http::Response::empty(200));
            }
        });

        let queue = RetryQueue::new(url, 1000, std::time::Duration::from_millis(50));
        queue.start();

        for i in 0..3 {
            queue.enqueue(
                format!(r#"["mission_stats",[["i",{i}]]]"#),
                "2026-04-29T12:00:00.000Z".to_string(),
            );
        }

        let start = std::time::Instant::now();
        assert!(queue.flush(), "flush should succeed");
        let elapsed = start.elapsed();

        assert!(elapsed >= std::time::Duration::from_millis(550),
            "flush returned in {elapsed:?}, expected >= 550ms (3 sequential 200ms responses)");
        assert_eq!(queue.buffer_len(), 0);
        queue.stop();
    }

    #[test]
    fn test_retry_queue_sets_headers_and_text_plain_body() {
        config::store_api_port(7777);

        let server = tiny_http::Server::http("127.0.0.1:0").unwrap();
        let port = server.server_addr().to_ip().unwrap().port();
        let url = format!("http://127.0.0.1:{port}/gameservers/events");

        let captured = Arc::new(Mutex::new(Vec::<(String, String, String, String)>::new()));
        let captured_clone = Arc::clone(&captured);

        let server_thread = thread::spawn(move || {
            let Ok(Some(mut request)) = server.recv_timeout(Duration::from_secs(5)) else {
                return;
            };
            let content_type = request
                .headers()
                .iter()
                .find(|h| h.field.as_str().as_str().eq_ignore_ascii_case("content-type"))
                .map(|h| h.value.as_str().to_string())
                .unwrap_or_default();
            let api_port = request
                .headers()
                .iter()
                .find(|h| h.field.as_str().as_str().eq_ignore_ascii_case("x-api-port"))
                .map(|h| h.value.as_str().to_string())
                .unwrap_or_default();
            let enqueued_at = request
                .headers()
                .iter()
                .find(|h| h.field.as_str().as_str().eq_ignore_ascii_case("x-enqueued-at"))
                .map(|h| h.value.as_str().to_string())
                .unwrap_or_default();
            let mut body = String::new();
            let _ = request.as_reader().read_to_string(&mut body);
            if let Ok(mut guard) = captured_clone.lock() {
                guard.push((content_type, api_port, enqueued_at, body));
            }
            let _ = request.respond(tiny_http::Response::empty(200));
        });

        let queue = RetryQueue::new(url, 10, Duration::from_millis(50));
        queue.start();
        queue.enqueue(
            r#"["mission_started",[["sessionId","abc"]]]"#.to_string(),
            "2026-05-06T12:00:00.000Z".to_string(),
        );

        let _ = server_thread.join();
        queue.stop();

        let captured = captured.lock().unwrap().clone();
        assert_eq!(captured.len(), 1);
        let (content_type, api_port, enqueued_at, body) = &captured[0];
        assert!(content_type.starts_with("text/plain"), "content-type was {content_type}");
        assert_eq!(api_port, "7777");
        assert_eq!(enqueued_at, "2026-05-06T12:00:00.000Z");
        assert_eq!(body, r#"["mission_started",[["sessionId","abc"]]]"#);
    }
}
