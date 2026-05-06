use std::thread;

use crate::config;
use crate::bridge;

// Per-callback byte cap is not documented by Bohemia; the only documented
// callback constraint is 100 slots/frame, which arma-rs auto-retries on
// (see arma-rs/src/lib.rs ~L229). Listener forwards 64 KB POST bodies via the
// same callback path without issue, so 64 KB is empirically safe.
const CHUNK_SIZE: usize = 65536;

pub fn load(key: &str) {
    let key = key.to_string();
    let url = format!("{}/persistence/{}", config::api_base_url(), key);

    thread::spawn(move || {
        log::info!("Fetching persistence data from {url}");
        let body = match fetch_persistence_data(&url) {
            Ok(data) => {
                log::info!("Loaded persistence for '{key}': {} bytes", data.len());
                data
            }
            Err(error) => {
                log::error!("Failed to load persistence for key '{key}': {error}");
                let envelope = build_error_envelope_json(&key, &error);
                bridge::fire_callback("command", &envelope);
                return;
            }
        };

        let chunks = chunk_data(&body, CHUNK_SIZE);
        let total = chunks.len();
        log::info!("Sending persistence '{key}' in {total} chunk(s)");

        for (index, chunk) in chunks.iter().enumerate() {
            let envelope = build_envelope_json(&key, index, total, chunk);
            bridge::fire_callback("command", &envelope);
        }
        log::info!("Finished sending persistence '{key}'");
    });
}

fn fetch_persistence_data(url: &str) -> Result<String, String> {
    let response = ureq::get(url)
        .timeout(std::time::Duration::from_secs(30))
        .call()
        .map_err(|error| format!("{error}"))?;

    response
        .into_string()
        .map_err(|error| format!("failed to read response: {error}"))
}

fn chunk_data(data: &str, chunk_size: usize) -> Vec<&str> {
    if data.is_empty() {
        return vec![""];
    }

    assert!(chunk_size > 0, "chunk_size must be greater than 0");

    let mut chunks = Vec::new();
    let mut start = 0;
    while start < data.len() {
        let mut end = (start + chunk_size).min(data.len());
        // Ensure we don't split in the middle of a multi-byte UTF-8 character.
        // Walk back to the nearest char boundary.
        while end > start && !data.is_char_boundary(end) {
            end -= 1;
        }
        // If chunk_size is smaller than a multi-byte character, advance forward instead
        if end == start {
            end = start + 1;
            while end < data.len() && !data.is_char_boundary(end) {
                end += 1;
            }
        }
        chunks.push(&data[start..end]);
        start = end;
    }
    chunks
}

/// SQF string literals double internal quotes; backslashes are literal.
fn escape_sqf_string(input: &str) -> String {
    let mut escaped = String::with_capacity(input.len() + 16);
    for character in input.chars() {
        if character == '"' {
            escaped.push_str("\"\"");
        } else {
            escaped.push(character);
        }
    }
    escaped
}

/// Persistence chunk envelope as an SQF array literal:
///   ["persistence_load", "<id>", <index>, <total>, "<data>", "<error>"]
/// The game side runs parseSimpleArray on this, dropping CBA_fnc_parseJSON
/// from the per-chunk hot path. parseSimpleArray accepts any-depth arrays
/// and respects the SQF doubled-quote string convention.
fn build_envelope_sqf(id: &str, index: usize, total: usize, data: &str, error: &str) -> String {
    format!(
        "[\"persistence_load\",\"{}\",{},{},\"{}\",\"{}\"]",
        escape_sqf_string(id),
        index,
        total,
        escape_sqf_string(data),
        escape_sqf_string(error)
    )
}

fn build_error_envelope_json(id: &str, error: &str) -> String {
    build_envelope_sqf(id, 0, 0, "", error)
}

fn build_envelope_json(id: &str, index: usize, total: usize, data: &str) -> String {
    build_envelope_sqf(id, index, total, data, "")
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_chunk_empty_data() {
        let chunks = chunk_data("", 1000);
        assert_eq!(chunks.len(), 1);
        assert_eq!(chunks[0], "");
    }

    #[test]
    fn test_chunk_data_fits_in_one() {
        let data = "hello world";
        let chunks = chunk_data(data, 1000);
        assert_eq!(chunks.len(), 1);
        assert_eq!(chunks[0], "hello world");
    }

    #[test]
    fn test_chunk_data_splits_correctly() {
        let data = "abcdefghij"; // 10 chars
        let chunks = chunk_data(data, 3);
        assert_eq!(chunks.len(), 4); // 3+3+3+1
        assert_eq!(chunks[0], "abc");
        assert_eq!(chunks[1], "def");
        assert_eq!(chunks[2], "ghi");
        assert_eq!(chunks[3], "j");
    }

    #[test]
    fn test_chunk_data_exact_boundary() {
        let data = "abcdef"; // 6 chars
        let chunks = chunk_data(data, 3);
        assert_eq!(chunks.len(), 2);
        assert_eq!(chunks[0], "abc");
        assert_eq!(chunks[1], "def");
    }

    #[test]
    fn test_chunk_data_reassembles_to_original() {
        let data = r#"{"objects":[{"id":"test_1","type":"B_MRAP_01_F"}],"players":{}}"#;
        let chunks = chunk_data(data, 20);
        let reassembled: String = chunks.into_iter().collect();
        assert_eq!(reassembled, data);
    }

    #[test]
    fn test_chunk_data_multibyte_utf8() {
        // Each emoji is 4 bytes. "🎮🎮🎮" = 12 bytes
        let data = "🎮🎮🎮";
        // Chunk at 5 bytes — would land mid-character without boundary check
        let chunks = chunk_data(data, 5);
        let reassembled: String = chunks.into_iter().collect();
        assert_eq!(reassembled, data);
    }

    #[test]
    fn test_chunk_data_tiny_chunk_size_with_multibyte() {
        // 4-byte emoji with chunk_size=1 — must not infinite loop
        let data = "🎮";
        let chunks = chunk_data(data, 1);
        let reassembled: String = chunks.into_iter().collect();
        assert_eq!(reassembled, data);
    }

    #[test]
    #[should_panic(expected = "chunk_size must be greater than 0")]
    fn test_chunk_data_zero_chunk_size_panics() {
        chunk_data("hello", 0);
    }

    #[test]
    fn test_build_envelope_sqf_basic() {
        let sqf = build_envelope_sqf("save-123", 0, 3, "chunk_data", "");
        assert_eq!(sqf, "[\"persistence_load\",\"save-123\",0,3,\"chunk_data\",\"\"]");
    }

    #[test]
    fn test_build_envelope_sqf_doubles_quotes_in_data() {
        // SQF string escape: " → "" (doubled). Backslashes stay literal.
        let sqf = build_envelope_sqf("id", 0, 1, r#"[["k","v"]]"#, "");
        assert_eq!(sqf, "[\"persistence_load\",\"id\",0,1,\"[[\"\"k\"\",\"\"v\"\"]]\",\"\"]");
    }

    #[test]
    fn test_build_envelope_sqf_passes_newlines_through() {
        // Multi-byte / control chars survive verbatim — parseSimpleArray accepts them.
        let sqf = build_envelope_sqf("id", 0, 1, "line1\nline2", "");
        assert!(sqf.contains("line1\nline2"));
    }

    #[test]
    fn test_build_envelope_sqf_escapes_id_quotes() {
        let sqf = build_envelope_sqf(r#"key"with"quotes"#, 0, 1, "data", "");
        assert!(sqf.contains(r#""key""with""quotes""#));
    }

    #[test]
    fn test_build_error_envelope_uses_sqf_format() {
        let sqf = build_error_envelope_json("missing", "not found");
        assert_eq!(sqf, "[\"persistence_load\",\"missing\",0,0,\"\",\"not found\"]");
    }

    #[test]
    fn test_load_from_test_server_success() {
        let server = tiny_http::Server::http("127.0.0.1:0").unwrap();
        let port = server.server_addr().to_ip().unwrap().port();

        let server_thread = std::thread::spawn(move || {
            let request = server
                .recv_timeout(std::time::Duration::from_secs(5))
                .unwrap()
                .unwrap();
            assert!(request.url().contains("/persistence/"));
            let response = tiny_http::Response::from_string(r#"{"objects":[]}"#);
            let _ = request.respond(response);
        });

        let url = format!("http://127.0.0.1:{port}/persistence/test_key");
        let result = fetch_persistence_data(&url);
        assert!(result.is_ok());
        assert_eq!(result.unwrap(), r#"{"objects":[]}"#);

        server_thread.join().unwrap();
    }

    #[test]
    fn test_load_from_test_server_not_found() {
        let server = tiny_http::Server::http("127.0.0.1:0").unwrap();
        let port = server.server_addr().to_ip().unwrap().port();

        let server_thread = std::thread::spawn(move || {
            let request = server
                .recv_timeout(std::time::Duration::from_secs(5))
                .unwrap()
                .unwrap();
            let response = tiny_http::Response::from_string("not found")
                .with_status_code(404);
            let _ = request.respond(response);
        });

        let url = format!("http://127.0.0.1:{port}/persistence/missing_key");
        let result = fetch_persistence_data(&url);
        // ureq treats 4xx as errors
        assert!(result.is_err());

        server_thread.join().unwrap();
    }
}
