use std::sync::Mutex;

static STATUS: Mutex<Option<String>> = Mutex::new(None);
static PERFORMANCE: Mutex<Option<String>> = Mutex::new(None);

/// Cache the latest server_status event JSON.
/// Called by sender before forwarding to API.
pub fn cache_status(json: &str) {
    if let Ok(mut guard) = STATUS.lock() {
        *guard = Some(json.to_string());
    }
}

/// Cache the latest performance event JSON.
pub fn cache_performance(json: &str) {
    if let Ok(mut guard) = PERFORMANCE.lock() {
        *guard = Some(json.to_string());
    }
}

/// Build a merged JSON response from cached status + performance data.
/// Returns `None` if no status has been received yet.
pub fn get_status_json() -> Option<String> {
    let status = STATUS.lock().ok()?.clone()?;
    let performance = PERFORMANCE.lock().ok().and_then(|g| g.clone());

    // Both are JSON objects from SQF — merge them by combining fields.
    // Status: {"map":"...","mission":"...","playerCount":N,"uptime":N,"processId":N}
    // Performance: {"fps":N,"entityCount":N,"aiCount":N,"headlessClientCount":N}
    match performance {
        Some(perf) if perf.len() > 2 => {
            let status_trimmed = status.trim_end().trim_end_matches('}');
            let perf_fields = perf.trim_start().trim_start_matches('{');
            Some(format!("{status_trimmed},{perf_fields}"))
        }
        _ => Some(status),
    }
}

/// Clear cached status (called on stop).
pub fn clear() {
    if let Ok(mut guard) = STATUS.lock() {
        *guard = None;
    }
    if let Ok(mut guard) = PERFORMANCE.lock() {
        *guard = None;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_cache_and_get_status() {
        cache_status(r#"{"map":"Altis","playerCount":5}"#);
        let result = get_status_json();
        assert!(result.is_some());
        assert!(result.unwrap().contains("Altis"));
    }

    #[test]
    fn test_merged_status_and_performance() {
        cache_status(r#"{"map":"Altis","playerCount":5}"#);
        cache_performance(r#"{"fps":50.0,"entityCount":200}"#);
        let result = get_status_json().unwrap();
        assert!(result.contains("Altis"));
        assert!(result.contains("fps"));
        assert!(result.contains("entityCount"));
    }

    #[test]
    fn test_no_status_returns_none() {
        clear();
        assert!(get_status_json().is_none());
    }
}
