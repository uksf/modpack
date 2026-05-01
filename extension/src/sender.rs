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
    json: String,
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
                    Ok(Message::Enqueue(json, enqueue_at)) => {
                        if buffer.len() >= capacity {
                            log::warn!("Retry queue full ({capacity}), dropping oldest event");
                            buffer.pop_front();
                        }
                        buffer.push_back(PendingEvent {
                            json,
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
                        json: pending.json,
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

    pub fn enqueue(&self, json: String, enqueue_at: String) {
        if let Ok(guard) = self.inbound.lock()
            && let Some(sender) = guard.as_ref()
        {
            let _ = sender.send(Message::Enqueue(json, enqueue_at));
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
    let body = inject_enqueue_at(&inject_api_port(&pending.json, api_port), &pending.enqueue_at);
    match ureq::post(url)
        .timeout(Duration::from_secs(5))
        .set("Content-Type", "application/json")
        .send_string(&body)
    {
        Ok(_) => true,
        Err(error) => {
            log::error!("Failed to send event (will retry): {error}");
            false
        }
    }
}

fn inject_enqueue_at(json: &str, timestamp: &str) -> String {
    // Insert "enqueueAt":"..." into the inner "data" object so the API can
    // distinguish original send time from re-receive time.
    let (data_pos, prefix_len) = if let Some(p) = json.find(r#""data":{"#) {
        (p, r#""data":{"#.len())
    } else if let Some(p) = json.find(r#""data": {"#) {
        (p, r#""data": {"#.len())
    } else {
        return json.to_string();
    };

    let insert_at = data_pos + prefix_len;
    if json.as_bytes().get(insert_at) == Some(&b'}') {
        format!(
            r#"{}"enqueueAt":"{}"{}"#,
            &json[..insert_at],
            timestamp,
            &json[insert_at..]
        )
    } else {
        format!(
            r#"{}"enqueueAt":"{}",{}"#,
            &json[..insert_at],
            timestamp,
            &json[insert_at..]
        )
    }
}

fn extract_event_data(json: &str, event_type: &str) -> Option<String> {
    let has_type = json.contains(&format!(r#""type":"{event_type}""#))
        || json.contains(&format!(r#""type": "{event_type}""#));
    if !has_type {
        return None;
    }

    let type_pos = json.find(r#""type""#).unwrap_or(0);
    let data_start = json[type_pos..]
        .find(r#""data":"#)
        .or_else(|| json[type_pos..].find(r#""data": "#))
        .map(|offset| type_pos + offset)?;
    let after_key = &json[data_start..];
    let colon_offset = after_key.find(':')?;
    let after_colon = &after_key[colon_offset + 1..];
    let brace_offset = after_colon.find('{')?;

    if !after_colon[..brace_offset].chars().all(|c| c.is_ascii_whitespace()) {
        return None;
    }

    let value_start = data_start + colon_offset + 1 + brace_offset;
    let bytes = json.as_bytes();

    let mut depth = 0;
    for (i, &byte) in bytes[value_start..].iter().enumerate() {
        match byte {
            b'{' => depth += 1,
            b'}' => {
                depth -= 1;
                if depth == 0 {
                    return Some(json[value_start..value_start + i + 1].to_string());
                }
            }
            _ => {}
        }
    }
    None
}

fn inject_api_port(json: &str, api_port: u16) -> String {
    if json.is_empty() {
        return String::new();
    }
    format!("{{\"apiPort\":{api_port},{}", &json[1..])
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

pub fn queue_event(json: &str) {
    if let Some(data_json) = extract_event_data(json, "server_status") {
        crate::status::cache_status(&data_json);
    }

    let enqueue_at = chrono::Utc::now().format("%Y-%m-%dT%H:%M:%S%.3fZ").to_string();

    if let Ok(guard) = QUEUE.lock()
        && let Some(queue) = guard.as_ref()
    {
        queue.enqueue(json.to_string(), enqueue_at);
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
    fn test_inject_enqueue_at_into_data_object() {
        let json = r#"{"type":"server_status","data":{"map":"Altis","players":5}}"#;
        let result = inject_enqueue_at(json, "2026-04-28T12:34:56.789Z");
        assert_eq!(
            result,
            r#"{"type":"server_status","data":{"enqueueAt":"2026-04-28T12:34:56.789Z","map":"Altis","players":5}}"#
        );
    }

    #[test]
    fn test_inject_enqueue_at_into_empty_data() {
        let json = r#"{"type":"shutdown_complete","data":{}}"#;
        let result = inject_enqueue_at(json, "2026-04-28T12:34:56.789Z");
        assert_eq!(
            result,
            r#"{"type":"shutdown_complete","data":{"enqueueAt":"2026-04-28T12:34:56.789Z"}}"#
        );
    }

    #[test]
    fn test_inject_enqueue_at_handles_spaced_data_object() {
        let json = r#"{"type":"mission_stats","data": {"sessionId":"abc","events":[]}}"#;
        let stamped = inject_enqueue_at(json, "2026-04-29T12:00:00.000Z");
        assert!(stamped.contains(r#""enqueueAt":"2026-04-29T12:00:00.000Z""#));
    }

    #[test]
    fn test_inject_enqueue_at_handles_spaced_empty_data() {
        let json = r#"{"type":"mission_stats","data": {}}"#;
        let stamped = inject_enqueue_at(json, "2026-04-29T12:00:00.000Z");
        assert!(stamped.contains(r#""enqueueAt":"2026-04-29T12:00:00.000Z""#));
    }

    #[test]
    fn test_inject_api_port_empty_string_does_not_panic() {
        let result = inject_api_port("", 2303);
        assert_eq!(result, "");
    }

    #[test]
    fn test_inject_enqueue_at_no_data_field_returns_unchanged() {
        let json = r#"{"type":"server_status"}"#;
        let result = inject_enqueue_at(json, "2026-04-28T12:34:56.789Z");
        assert_eq!(result, json);
    }

    #[test]
    fn test_inject_api_port() {
        let json = "{\"type\":\"shutdown_complete\",\"data\":{}}";
        let result = inject_api_port(json, 2303);
        assert_eq!(result, "{\"apiPort\":2303,\"type\":\"shutdown_complete\",\"data\":{}}");
    }

    #[test]
    fn test_inject_api_port_with_real_event() {
        let json = r#"{"type":"server_status","data":{"map":"Altis"}}"#;
        let result = inject_api_port(json, 2303);
        assert_eq!(
            result,
            r#"{"apiPort":2303,"type":"server_status","data":{"map":"Altis"}}"#
        );
    }

    #[test]
    fn test_extract_event_data_status() {
        let json = r#"{"type":"server_status","data":{"map":"Altis","players":5}}"#;
        let result = extract_event_data(json, "server_status");
        assert_eq!(result, Some(r#"{"map":"Altis","players":5}"#.to_string()));
    }

    #[test]
    fn test_extract_event_data_status_spaced() {
        let json = r#"{"type": "server_status", "data": {"map": "Altis", "players": ["uid1", "uid2"]}}"#;
        let result = extract_event_data(json, "server_status");
        assert_eq!(
            result,
            Some(r#"{"map": "Altis", "players": ["uid1", "uid2"]}"#.to_string())
        );
    }

    #[test]
    fn test_extract_event_data_wrong_type() {
        let json = r#"{"type":"persistence_save","data":{"key":"test"}}"#;
        let result = extract_event_data(json, "server_status");
        assert!(result.is_none());
    }

    #[test]
    fn test_extract_event_data_wrong_type_spaced() {
        let json = r#"{"type": "persistence_save", "data": {"key": "test"}}"#;
        let result = extract_event_data(json, "server_status");
        assert!(result.is_none());
    }

    #[test]
    fn test_extract_event_data_nested_braces() {
        let json = r#"{"type":"server_status","data":{"map":"Altis","nested":{"a":1}}}"#;
        let result = extract_event_data(json, "server_status");
        assert_eq!(result, Some(r#"{"map":"Altis","nested":{"a":1}}"#.to_string()));
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
            r#"{"type":"test","data":{"k":1}}"#.to_string(),
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

        queue.enqueue(r#"{"type":"a","data":{}}"#.to_string(), "ts".to_string());
        queue.enqueue(r#"{"type":"b","data":{}}"#.to_string(), "ts".to_string());
        queue.enqueue(r#"{"type":"c","data":{}}"#.to_string(), "ts".to_string());
        queue.enqueue(r#"{"type":"d","data":{}}"#.to_string(), "ts".to_string());

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
                format!(r#"{{"type":"mission_stats","data":{{"i":{i}}}}}"#),
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
    fn test_retry_queue_preserves_fifo_on_eventual_success() {
        config::store_api_port(2303);

        let server = tiny_http::Server::http("127.0.0.1:0").unwrap();
        let port = server.server_addr().to_ip().unwrap().port();
        let url = format!("http://127.0.0.1:{port}/gameservers/events");

        let bodies = Arc::new(Mutex::new(Vec::<String>::new()));
        let bodies_clone = Arc::clone(&bodies);

        let server_thread = thread::spawn(move || {
            let mut count = 0;
            while count < 4 {
                let Ok(Some(mut request)) = server.recv_timeout(Duration::from_secs(5)) else {
                    return;
                };
                let mut body = String::new();
                let _ = request.as_reader().read_to_string(&mut body);
                if let Ok(mut guard) = bodies_clone.lock() {
                    guard.push(body);
                }
                let status = if count == 0 { 500 } else { 200 };
                let _ = request.respond(tiny_http::Response::empty(status));
                count += 1;
            }
        });

        let queue = RetryQueue::new(url, 1000, Duration::from_millis(50));
        queue.start();
        queue.enqueue(
            r#"{"type":"e1","data":{"n":1}}"#.to_string(),
            "ts1".to_string(),
        );
        queue.enqueue(
            r#"{"type":"e2","data":{"n":2}}"#.to_string(),
            "ts2".to_string(),
        );
        queue.enqueue(
            r#"{"type":"e3","data":{"n":3}}"#.to_string(),
            "ts3".to_string(),
        );

        let _ = server_thread.join();
        queue.stop();

        let captured = bodies.lock().unwrap().clone();
        assert_eq!(captured.len(), 4);
        assert!(captured[0].contains(r#""type":"e1""#));
        assert!(captured[1].contains(r#""type":"e1""#));
        assert!(captured[2].contains(r#""type":"e2""#));
        assert!(captured[3].contains(r#""type":"e3""#));
    }
}
