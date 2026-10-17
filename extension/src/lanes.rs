use std::sync::{Arc, Mutex};
use std::time::{Duration, Instant};

use crate::config;
use crate::delivery::{event_type, is_acknowledged_type, next_seq};
use crate::sender::{RetryQueue, ACKNOWLEDGED_GIVE_UP_AFTER, FLUSH_TIMEOUT, MAX_QUEUE_SIZE};

pub fn extract_server_status_data(body: &str) -> Option<&str> {
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

