use std::sync::OnceLock;
use std::sync::atomic::{AtomicU16, Ordering};

/// API base URL the extension POSTs game events + dev-run callbacks to.
/// Resolved at extension startup from the `-apiUrl=` launch arg the API passes when
/// spawning arma3server. Falls back to the production default if absent so existing
/// callers without the new flag (older API deployments, manual launches) keep working.
const DEFAULT_API_BASE_URL: &str = "http://localhost:5000";
static API_BASE_URL: OnceLock<String> = OnceLock::new();

pub fn api_base_url() -> &'static str {
    API_BASE_URL.get_or_init(|| find_api_base_url().unwrap_or_else(|| DEFAULT_API_BASE_URL.to_string())).as_str()
}

fn find_api_base_url() -> Option<String> {
    std::env::args().find_map(|arg| {
        let stripped = arg
            .strip_prefix("-apiUrl=")
            .or_else(|| arg.strip_prefix("-apiUrl=\""))
            .map(|s| s.trim_matches('"').to_string())?;
        if stripped.is_empty() {
            None
        } else {
            Some(stripped)
        }
    })
}

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
    fn test_default_api_base_url_starts_with_http() {
        assert!(DEFAULT_API_BASE_URL.starts_with("http"));
    }

    #[test]
    fn test_store_and_get_api_port() {
        store_api_port(2303);
        assert_eq!(get_api_port(), 2303);
        store_api_port(0);
    }
}
