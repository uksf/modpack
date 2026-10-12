use super::*;
use crate::lanes::extract_server_status_data;
use crate::config;
use crate::delivery::{is_acknowledged_type, next_seq, outcome};
use std::sync::atomic::{AtomicBool, AtomicU32, Ordering as AtomicOrdering};

pub(super) fn test_server(status_for_request: impl Fn(u32) -> (u16, u64) + Send + 'static) -> (String, Arc<AtomicU32>, Arc<AtomicBool>) {
    let server = tiny_http::Server::http("127.0.0.1:0").unwrap();
    let port = server.server_addr().to_ip().unwrap().port();
    let count = Arc::new(AtomicU32::new(0));
    let stop = Arc::new(AtomicBool::new(false));
    let (count_clone, stop_clone) = (Arc::clone(&count), Arc::clone(&stop));
    thread::spawn(move || {
        while !stop_clone.load(AtomicOrdering::SeqCst) {
            if let Ok(Some(request)) = server.recv_timeout(Duration::from_millis(20)) {
                let (status, delay_ms) = status_for_request(count_clone.fetch_add(1, AtomicOrdering::SeqCst));
                thread::sleep(Duration::from_millis(delay_ms));
                let _ = request.respond(tiny_http::Response::empty(status));
            }
        }
    });
    (format!("http://127.0.0.1:{port}/gameservers/events"), count, stop)
}

pub(super) fn wait_for(condition: impl Fn() -> bool, limit: Duration) -> bool {
    let deadline = Instant::now() + limit;
    while Instant::now() < deadline {
        if condition() {
            return true;
        }
        thread::sleep(Duration::from_millis(10));
    }
    condition()
}

#[test]
fn test_extract_server_status_data() {
    let body = r#"["server_status",[["map","Altis"],["players",5]]]"#;
    assert_eq!(extract_server_status_data(body), Some(r#"[["map","Altis"],["players",5]]"#));
    assert_eq!(extract_server_status_data(r#"  ["server_status", [["map","Altis"]]]  "#), Some(r#"[["map","Altis"]]"#));
    assert!(extract_server_status_data(r#"["mission_started",[["map","Altis"]]]"#).is_none());
    assert!(extract_server_status_data(r#"["server_status","incomplete"#).is_none());
}

#[test]
fn test_next_backoff_ramp() {
    let ramp: Vec<u64> = [1, 2, 5, 10, 30, 60].into_iter().map(|s| next_backoff(Duration::from_secs(s)).as_secs()).collect();
    assert_eq!(ramp, vec![2, 5, 10, 30, 60, 60]);
}

#[test]
fn test_save_and_shutdown_events_take_the_acknowledged_lane() {
    let lane = |body: &str| is_acknowledged_type(event_type(body));
    assert!(lane(r#"["persistence_save",[["key","k"]]]"#));
    assert!(lane(r#"["shutdown_ending",[]]"#));
    assert!(lane(r#"["shutdown_stopping",[["outcome","lost"]]]"#));
    assert!(lane(r#"["mission_ended",[["saved",true]]]"#));
    assert!(!lane(r#"["mission_stats",[]]"#));
    assert!(!lane(r#"["server_status",[]]"#));
    assert!(!lane("garbage"));
}

#[test]
fn test_flush_when_not_started() {
    stop();
    assert!(!flush());
}

#[test]
fn test_retry_queue_recovers_after_transient_failures() {
    let (url, count, stop) = test_server(|n| (if n < 2 { 500 } else { 200 }, 0));
    let queue = RetryQueue::new(url, 1000, Duration::from_millis(50));
    queue.start();
    queue.enqueue(next_seq(), r#"["test",[["k",1]]]"#.to_string(), "2026-04-28T00:00:00.000Z".to_string());

    assert!(wait_for(|| count.load(AtomicOrdering::SeqCst) >= 3, Duration::from_secs(20)));
    queue.stop();
    stop.store(true, AtomicOrdering::SeqCst);
    assert_eq!(count.load(AtomicOrdering::SeqCst), 3);
}

#[test]
fn test_retry_queue_overflow_drops_oldest() {
    let (url, _count, stop) = test_server(|_| (500, 0));
    let queue = RetryQueue::new(url, 3, Duration::from_secs(3600));
    queue.start();
    for name in ["a", "b", "c", "d"] {
        queue.enqueue(next_seq(), format!(r#"["{name}",[]]"#), "ts".to_string());
    }

    assert!(wait_for(|| queue.buffer_len() == 3, Duration::from_secs(5)));
    queue.stop();
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_flush_returns_true_only_after_buffer_drains() {
    let (url, _count, stop) = test_server(|_| (200, 200));
    let queue = RetryQueue::new(url, 1000, Duration::from_millis(50));
    queue.start();
    for i in 0..3 {
        queue.enqueue(next_seq(), format!(r#"["mission_stats",[["i",{i}]]]"#), "2026-04-29T12:00:00.000Z".to_string());
    }

    let start = Instant::now();
    assert!(queue.flush(Duration::from_secs(10)), "flush should succeed");
    assert!(start.elapsed() >= Duration::from_millis(550), "flush returned in {:?}", start.elapsed());
    assert_eq!(queue.buffer_len(), 0);
    queue.stop();
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_acknowledged_event_reports_pending_while_in_flight_then_delivered() {
    let (url, _count, stop) = test_server(|_| (200, 400));
    let queue = RetryQueue::acknowledged(url, 10, Duration::from_millis(50), Duration::from_secs(120));
    queue.start();
    let seq = next_seq();
    queue.enqueue(seq, r#"["persistence_save",[["key","k"]]]"#.to_string(), "ts".to_string());

    assert_eq!(outcome(seq), Some(Outcome::Pending));
    thread::sleep(Duration::from_millis(150));
    let asked = Instant::now();
    assert_eq!(outcome(seq), Some(Outcome::Pending));
    assert!(asked.elapsed() < Duration::from_millis(20), "outcome lookup blocked for {:?}", asked.elapsed());
    assert!(wait_for(|| outcome(seq) == Some(Outcome::Delivered), Duration::from_secs(5)));
    queue.stop();
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_unprocessable_answer_is_rejected_once_without_retry() {
    let (url, count, stop) = test_server(|_| (422, 0));
    let queue = RetryQueue::acknowledged(url, 10, Duration::from_millis(50), Duration::from_secs(120));
    queue.start();
    let seq = next_seq();
    queue.enqueue(seq, r#"["persistence_save",[]]"#.to_string(), "ts".to_string());

    assert!(wait_for(|| outcome(seq) == Some(Outcome::Rejected), Duration::from_secs(5)));
    thread::sleep(Duration::from_millis(300));
    assert_eq!(count.load(AtomicOrdering::SeqCst), 1);
    queue.stop();
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_acknowledged_event_is_lost_at_the_give_up_deadline_not_the_next_backoff() {
    let (url, count, stop) = test_server(|_| (500, 0));
    let queue = RetryQueue::acknowledged(url, 10, Duration::from_millis(50), Duration::from_millis(400));
    queue.start();
    let seq = next_seq();
    let started = Instant::now();
    queue.enqueue(seq, r#"["persistence_save",[]]"#.to_string(), "ts".to_string());

    assert!(wait_for(|| outcome(seq) == Some(Outcome::Lost), Duration::from_secs(2)));
    assert!(started.elapsed() < Duration::from_millis(1500), "lost after {:?}", started.elapsed());
    let attempts = count.load(AtomicOrdering::SeqCst);
    thread::sleep(Duration::from_millis(300));
    assert_eq!(count.load(AtomicOrdering::SeqCst), attempts, "lost event was retried");
    queue.stop();
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_stop_marks_undelivered_acknowledged_events_lost() {
    let (url, _count, stop) = test_server(|_| (500, 0));
    let queue = RetryQueue::draining_for(url, 10, Duration::from_secs(3600), Some(Duration::from_secs(120)), Duration::from_secs(1));
    queue.start();
    let seq = next_seq();
    queue.enqueue(seq, r#"["shutdown_stopping",[]]"#.to_string(), "ts".to_string());
    assert!(wait_for(|| queue.buffer_len() == 1, Duration::from_secs(5)));

    queue.stop();
    assert!(wait_for(|| outcome(seq) == Some(Outcome::Lost), Duration::from_secs(3)));
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_ordinary_events_are_not_tracked() {
    let (url, _count, stop) = test_server(|_| (200, 0));
    let queue = RetryQueue::new(url, 10, Duration::from_millis(50));
    queue.start();
    let seq = next_seq();
    queue.enqueue(seq, r#"["mission_stats",[]]"#.to_string(), "ts".to_string());

    assert!(queue.flush(Duration::from_secs(5)));
    assert_eq!(outcome(seq), None);
    queue.stop();
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_retry_queue_sets_headers_and_text_plain_body() {
    config::store_api_port(7777);
    let server = tiny_http::Server::http("127.0.0.1:0").unwrap();
    let port = server.server_addr().to_ip().unwrap().port();
    let url = format!("http://127.0.0.1:{port}/gameservers/events");
    let captured = Arc::new(Mutex::new(Vec::<(Vec<(String, String)>, String)>::new()));
    let captured_clone = Arc::clone(&captured);

    let server_thread = thread::spawn(move || {
        let Ok(Some(mut request)) = server.recv_timeout(Duration::from_secs(5)) else {
            return;
        };
        let headers = request.headers().iter().map(|h| (h.field.as_str().as_str().to_ascii_lowercase(), h.value.as_str().to_string())).collect();
        let mut body = String::new();
        let _ = request.as_reader().read_to_string(&mut body);
        captured_clone.lock().unwrap().push((headers, body));
        let _ = request.respond(tiny_http::Response::empty(200));
    });

    let queue = RetryQueue::new(url, 10, Duration::from_millis(50));
    queue.start();
    queue.enqueue(next_seq(), r#"["mission_started",[["sessionId","abc"]]]"#.to_string(), "2026-05-06T12:00:00.000Z".to_string());
    let _ = server_thread.join();
    queue.stop();

    let captured = captured.lock().unwrap().clone();
    assert_eq!(captured.len(), 1);
    let (headers, body) = &captured[0];
    let header = |name: &str| headers.iter().find(|(k, _)| k == name).map(|(_, v)| v.as_str()).unwrap_or_default();
    assert!(header("content-type").starts_with("text/plain"), "content-type was {}", header("content-type"));
    assert_eq!(header("x-api-port"), "7777");
    assert_eq!(header("x-enqueued-at"), "2026-05-06T12:00:00.000Z");
    assert_eq!(header("x-uksf-protocol"), "2");
    assert_eq!(body, r#"["mission_started",[["sessionId","abc"]]]"#);
}

#[test]
fn test_acknowledged_event_waits_past_the_ordinary_timeout_and_is_sent_once() {
    let (url, count, stop) = test_server(|_| (200, 6000));
    let queue = RetryQueue::acknowledged(url, 10, Duration::from_millis(50), Duration::from_secs(120));
    queue.start();
    let seq = next_seq();
    queue.enqueue(seq, r#"["persistence_save",[["key","k"]]]"#.to_string(), "ts".to_string());

    assert!(wait_for(|| outcome(seq) == Some(Outcome::Delivered), Duration::from_secs(10)));
    assert_eq!(count.load(AtomicOrdering::SeqCst), 1);
    queue.stop();
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_acknowledged_lane_retries_within_five_seconds_after_a_long_outage() {
    let (url, count, stop) = test_server(|n| (if n < 6 { 503 } else { 200 }, 0));
    let queue = RetryQueue::acknowledged(url, 10, Duration::from_secs(1), Duration::from_secs(120));
    queue.start();
    let seq = next_seq();
    queue.enqueue(seq, r#"["persistence_save",[["key","k"]]]"#.to_string(), "ts".to_string());

    assert!(wait_for(|| outcome(seq) == Some(Outcome::Delivered), Duration::from_secs(40)));
    assert_eq!(count.load(AtomicOrdering::SeqCst), 7);
    queue.stop();
    stop.store(true, AtomicOrdering::SeqCst);
}
