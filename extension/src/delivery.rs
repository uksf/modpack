use std::collections::HashMap;
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::Mutex;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Outcome {
    Pending,
    Delivered,
    Rejected,
    Lost,
}

impl Outcome {
    pub fn as_str(self) -> &'static str {
        match self {
            Outcome::Pending => "pending",
            Outcome::Delivered => "delivered",
            Outcome::Rejected => "rejected",
            Outcome::Lost => "lost",
        }
    }
}

static NEXT_SEQ: AtomicU64 = AtomicU64::new(1);
static OUTCOMES: Mutex<Option<HashMap<u64, Outcome>>> = Mutex::new(None);

const OUTCOME_RETENTION: u64 = 4096;

pub fn set_outcome(seq: u64, outcome: Outcome) {
    if let Ok(mut guard) = OUTCOMES.lock() {
        let outcomes = guard.get_or_insert_with(HashMap::new);
        outcomes.insert(seq, outcome);
        forget_old_outcomes(outcomes, NEXT_SEQ.load(Ordering::Relaxed).saturating_sub(1).max(seq), OUTCOME_RETENTION);
    }
}

pub fn forget_old_outcomes(outcomes: &mut HashMap<u64, Outcome>, latest: u64, retention: u64) {
    if outcomes.len() as u64 > retention {
        let oldest_kept = latest.saturating_sub(retention);
        outcomes.retain(|seq, outcome| *outcome == Outcome::Pending || *seq > oldest_kept);
    }
}

pub fn outcome(seq: u64) -> Option<Outcome> {
    OUTCOMES.lock().ok()?.as_ref()?.get(&seq).copied()
}

pub fn next_seq() -> u64 {
    NEXT_SEQ.fetch_add(1, Ordering::Relaxed)
}

pub fn event_type(body: &str) -> &str {
    body.trim().strip_prefix("[\"").and_then(|rest| rest.split('"').next()).unwrap_or("event")
}

pub fn is_acknowledged_type(event_type: &str) -> bool {
    event_type == "persistence_save" || event_type == "mission_ended" || event_type.starts_with("shutdown_")
}
