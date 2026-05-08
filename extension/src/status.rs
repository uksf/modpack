use std::sync::Mutex;

static STATUS: Mutex<Option<String>> = Mutex::new(None);

/// Cache the latest server_status event data field as SQF-notation.
/// Called by sender before forwarding to API.
pub fn cache_status(sqf_data: &str) {
    if let Ok(mut guard) = STATUS.lock() {
        *guard = Some(sqf_data.to_string());
    }
}

/// Return the cached status SQF-notation body for GET /server.
/// Returns `None` if no status has been received yet.
pub fn get_status_sqf() -> Option<String> {
    STATUS.lock().ok()?.clone()
}

/// Clear cached status (called on stop).
pub fn clear() {
    if let Ok(mut guard) = STATUS.lock() {
        *guard = None;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_cache_and_get_status() {
        cache_status(r#"[["map","Altis"],["players",5],["uptime",48.5]]"#);
        let result = get_status_sqf();
        assert!(result.is_some());
        let sqf = result.unwrap();
        assert!(sqf.contains("Altis"));
        assert!(sqf.contains("uptime"));
    }

    #[test]
    fn test_no_status_returns_none() {
        clear();
        assert!(get_status_sqf().is_none());
    }
}
