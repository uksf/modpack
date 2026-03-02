/// Hardcoded API base URL
pub const API_BASE_URL: &str = "http://localhost:5000";

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
}
