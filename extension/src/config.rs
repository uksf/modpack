use std::sync::atomic::{AtomicU16, Ordering};

/// Hardcoded API base URL
pub const API_BASE_URL: &str = "http://localhost:5000";

static API_PORT: AtomicU16 = AtomicU16::new(0);

/// Store the parsed API port for use in outgoing HTTP headers
pub fn store_api_port(port: u16) {
    API_PORT.store(port, Ordering::SeqCst);
}

/// Get the stored API port
pub fn get_api_port() -> u16 {
    API_PORT.load(Ordering::SeqCst)
}

/// Parse -apiport=N from process command line arguments
pub fn find_api_port() -> Option<u16> {
    std::env::args().find_map(|arg| {
        let stripped = arg
            .strip_prefix("-apiport=")
            .or_else(|| arg.strip_prefix("-apiport=\""))
            .map(|s| s.trim_matches('"'));
        stripped.and_then(|s| s.parse().ok())
    })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_api_base_url_is_set() {
        assert!(!API_BASE_URL.is_empty());
        assert!(API_BASE_URL.starts_with("http"));
    }

    #[test]
    fn test_store_and_get_api_port() {
        store_api_port(2303);
        assert_eq!(get_api_port(), 2303);
        store_api_port(0);
    }
}
