use std::sync::Mutex;

static STATUS: Mutex<Option<String>> = Mutex::new(None);

/// Cache the latest server_status event JSON.
/// Called by sender before forwarding to API.
pub fn cache_status(json: &str) {
    if let Ok(mut guard) = STATUS.lock() {
        *guard = Some(json.to_string());
    }
}

/// Return the cached status JSON for the GET /server endpoint.
/// Returns `None` if no status has been received yet.
pub fn get_status_json() -> Option<String> {
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
        cache_status(r#"{"map":"Altis","players":5,"fps":48.5}"#);
        let result = get_status_json();
        assert!(result.is_some());
        let json = result.unwrap();
        assert!(json.contains("Altis"));
        assert!(json.contains("fps"));
    }

    #[test]
    fn test_no_status_returns_none() {
        clear();
        assert!(get_status_json().is_none());
    }
}
