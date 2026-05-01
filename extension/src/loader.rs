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

fn escape_json_string(input: &str) -> String {
    let mut escaped = String::with_capacity(input.len() + 16);
    for character in input.chars() {
        match character {
            '\\' => escaped.push_str("\\\\"),
            '"' => escaped.push_str("\\\""),
            '\n' => escaped.push_str("\\n"),
            '\r' => escaped.push_str("\\r"),
            '\t' => escaped.push_str("\\t"),
            c if c.is_control() => {
                escaped.push_str(&format!("\\u{:04x}", c as u32));
            }
            c => escaped.push(c),
        }
    }
    escaped
}

fn build_error_envelope_json(id: &str, error: &str) -> String {
    let escaped_id = escape_json_string(id);
    let escaped_error = escape_json_string(error);
    format!(
        r#"{{"type":"persistence_load","id":"{escaped_id}","index":0,"total":0,"data":"","error":"{escaped_error}"}}"#
    )
}

fn build_envelope_json(id: &str, index: usize, total: usize, data: &str) -> String {
    let escaped_id = escape_json_string(id);
    let escaped_data = escape_json_string(data);
    format!(
        r#"{{"type":"persistence_load","id":"{escaped_id}","index":{index},"total":{total},"data":"{escaped_data}"}}"#
    )
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
    fn test_build_envelope_json() {
        let json = build_envelope_json("save-123", 0, 3, "chunk_data");
        assert!(json.contains(r#""type":"persistence_load""#));
        assert!(json.contains(r#""id":"save-123""#));
        assert!(json.contains(r#""index":0"#));
        assert!(json.contains(r#""total":3"#));
        assert!(json.contains(r#""data":"chunk_data""#));
    }

    #[test]
    fn test_build_envelope_json_escapes_quotes() {
        let json = build_envelope_json("id", 0, 1, r#"{"key":"value"}"#);
        assert!(json.contains(r#""data":"{\"key\":\"value\"}""#));
    }

    #[test]
    fn test_build_envelope_json_escapes_newlines_and_tabs() {
        let json = build_envelope_json("id", 0, 1, "line1\nline2\ttab");
        assert!(json.contains(r#""data":"line1\nline2\ttab""#));
        // Verify no raw newlines in the output
        assert!(!json.contains('\n'));
        assert!(!json.contains('\t'));
    }

    #[test]
    fn test_build_envelope_json_escapes_id() {
        let json = build_envelope_json("key\"with\"quotes", 0, 1, "data");
        assert!(json.contains(r#""id":"key\"with\"quotes""#));
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
