use super::tests::{test_server, wait_for};
use super::*;
use crate::delivery::{forget_old_outcomes, next_seq, outcome};
use std::sync::atomic::{AtomicBool, Ordering as AtomicOrdering};

fn body_server(status_for_body: impl Fn(&str) -> u16 + Send + 'static) -> (String, Arc<Mutex<Vec<String>>>, Arc<AtomicBool>) {
    let server = tiny_http::Server::http("127.0.0.1:0").unwrap();
    let port = server.server_addr().to_ip().unwrap().port();
    let seen = Arc::new(Mutex::new(Vec::new()));
    let stop = Arc::new(AtomicBool::new(false));
    let (seen_clone, stop_clone) = (Arc::clone(&seen), Arc::clone(&stop));
    thread::spawn(move || {
        while !stop_clone.load(AtomicOrdering::SeqCst) {
            if let Ok(Some(mut request)) = server.recv_timeout(Duration::from_millis(20)) {
                let mut body = String::new();
                let _ = request.as_reader().read_to_string(&mut body);
                let status = status_for_body(&body);
                seen_clone.lock().unwrap().push(body);
                let _ = request.respond(tiny_http::Response::empty(status));
            }
        }
    });
    (format!("http://127.0.0.1:{port}/gameservers/events"), seen, stop)
}

#[test]
fn test_a_failing_shutdown_event_does_not_hold_back_the_save() {
    let (url, _seen, stop) = body_server(|body| if body.contains("shutdown_ending") { 503 } else { 200 });
    let queue = RetryQueue::acknowledged(url, 10, Duration::from_millis(500), Duration::from_secs(120));
    queue.start();
    let ending = next_seq();
    queue.enqueue(ending, r#"["shutdown_ending",[]]"#.to_string(), "ts".to_string());
    let save = next_seq();
    queue.enqueue(save, r#"["persistence_save",[["key","k"]]]"#.to_string(), "ts".to_string());

    assert!(wait_for(|| outcome(save) == Some(Outcome::Delivered), Duration::from_secs(3)));
    assert_eq!(outcome(ending), Some(Outcome::Pending));
    queue.stop();
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_lifetime_counts_from_enqueue_not_from_when_the_worker_picks_the_event_up() {
    let (url, _count, stop) = test_server(|_| (200, 3000));
    let queue = RetryQueue::acknowledged(url, 10, Duration::from_millis(50), Duration::from_secs(4));
    queue.start();
    let first = next_seq();
    queue.enqueue(first, r#"["shutdown_ending",[]]"#.to_string(), "ts".to_string());
    thread::sleep(Duration::from_millis(100));
    let second = next_seq();
    queue.enqueue(second, r#"["persistence_save",[["key","k"]]]"#.to_string(), "ts".to_string());

    assert!(wait_for(|| outcome(first) == Some(Outcome::Delivered), Duration::from_secs(5)));
    assert!(wait_for(|| outcome(second) != Some(Outcome::Pending), Duration::from_secs(5)));
    assert_eq!(outcome(second), Some(Outcome::Lost));
    queue.stop();
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_an_acknowledged_event_queued_at_stop_is_still_delivered_within_the_drain() {
    let (url, count, stop) = test_server(|_| (200, 300));
    let queue = RetryQueue::acknowledged(url, 10, Duration::from_millis(50), Duration::from_secs(120));
    queue.start();
    queue.enqueue(next_seq(), r#"["mission_stats",[]]"#.to_string(), "ts".to_string());
    let mission_ended = next_seq();
    queue.enqueue(mission_ended, r#"["mission_ended",[]]"#.to_string(), "ts".to_string());

    queue.stop();
    assert!(wait_for(|| outcome(mission_ended) == Some(Outcome::Delivered), Duration::from_secs(3)));
    assert_eq!(count.load(AtomicOrdering::SeqCst), 2);
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_acknowledged_drain_after_stop_ends_at_its_deadline_and_loses_the_rest() {
    let (url, count, stop) = test_server(|_| (503, 0));
    let queue = RetryQueue::draining_for(url, 10, Duration::from_millis(50), Some(Duration::from_secs(120)), Duration::from_secs(3));
    queue.start();
    let seq = next_seq();
    queue.enqueue(seq, r#"["mission_ended",[]]"#.to_string(), "ts".to_string());

    queue.stop();
    assert!(wait_for(|| outcome(seq) == Some(Outcome::Lost), Duration::from_secs(5)));
    let posted = count.load(AtomicOrdering::SeqCst);
    thread::sleep(Duration::from_millis(500));
    assert_eq!(posted, 2, "a 3 s drain with a 2 s backoff allows two attempts");
    assert_eq!(count.load(AtomicOrdering::SeqCst), posted);
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_enqueue_after_stop_is_lost_at_once() {
    let (url, _count, stop) = test_server(|_| (200, 0));
    let queue = RetryQueue::acknowledged(url, 10, Duration::from_millis(50), Duration::from_secs(120));
    queue.start();
    queue.stop();
    let seq = next_seq();
    queue.enqueue(seq, r#"["persistence_save",[["key","k"]]]"#.to_string(), "ts".to_string());

    assert_eq!(outcome(seq), Some(Outcome::Lost));
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_ordinary_events_still_deliver_after_stop_without_a_blocking_flush() {
    let (url, count, stop) = test_server(|n| (if n == 0 { 503 } else { 200 }, 0));
    let queue = RetryQueue::new(url, 10, Duration::from_millis(50));
    queue.start();
    queue.enqueue(next_seq(), r#"["mission_stats",[]]"#.to_string(), "ts".to_string());
    assert!(wait_for(|| count.load(AtomicOrdering::SeqCst) == 1, Duration::from_secs(2)));

    queue.stop();
    assert!(wait_for(|| count.load(AtomicOrdering::SeqCst) == 2, Duration::from_secs(5)));
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_ordinary_drain_after_stop_ends_at_its_deadline_even_with_a_backlog() {
    let (url, count, stop) = test_server(|_| (200, 300));
    let queue = RetryQueue::draining_for(url, 100, Duration::from_millis(50), None, Duration::from_secs(1));
    queue.start();
    for i in 0..20 {
        queue.enqueue(next_seq(), format!(r#"["mission_stats",[["i",{i}]]]"#), "ts".to_string());
    }
    queue.stop();

    thread::sleep(Duration::from_secs(3));
    let posted = count.load(AtomicOrdering::SeqCst);
    assert!((1..=5).contains(&posted), "posted {posted} events after a 1 s drain at 300 ms each");
    stop.store(true, AtomicOrdering::SeqCst);
}

#[test]
fn test_old_terminal_outcomes_are_forgotten_but_pending_ones_are_kept() {
    let mut outcomes: std::collections::HashMap<u64, Outcome> = (1..=10).map(|seq| (seq, Outcome::Delivered)).collect();
    outcomes.insert(2, Outcome::Pending);

    forget_old_outcomes(&mut outcomes, 10, 4);

    let mut kept: Vec<u64> = outcomes.keys().copied().collect();
    kept.sort();
    assert_eq!(kept, vec![2, 7, 8, 9, 10]);
}
