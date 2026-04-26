use std::sync::mpsc::{self, Sender};
use std::sync::Mutex;
use std::thread;

use crate::config;

enum Message {
    Event(String),
    Flush(Sender<()>),
}

static CHANNEL: Mutex<Option<Sender<Message>>> = Mutex::new(None);

pub fn start() {
    let (sender, receiver) = mpsc::channel::<Message>();

    if let Ok(mut channel) = CHANNEL.lock() {
        *channel = Some(sender);
    }

    thread::spawn(move || {
        let url = format!("{}/gameservers/events", config::API_BASE_URL);
        let api_port = config::get_api_port();
        log::info!("Sender thread started, posting to {url} with apiPort={api_port}");

        for message in receiver {
            match message {
                Message::Event(json) => {
                    let body = inject_api_port(&json, api_port);
                    let result = ureq::post(&url)
                        .timeout(std::time::Duration::from_secs(5))
                        .set("Content-Type", "application/json")
                        .send_string(&body);

                    if let Err(error) = result {
                        log::error!("Failed to send event: {error}");
                    }
                }
                Message::Flush(ack) => {
                    let _ = ack.send(());
                }
            }
        }
    });
}

pub fn stop() {
    if let Ok(mut channel) = CHANNEL.lock() {
        *channel = None; // Dropping sender closes channel, thread exits
    }
}

pub fn queue_event(json: &str) {
    // Cache server_status events for the GET /server endpoint
    if let Some(data_json) = extract_event_data(json, "server_status") {
        crate::status::cache_status(&data_json);
    }

    if let Ok(channel) = CHANNEL.lock()
        && let Some(sender) = channel.as_ref()
    {
        let _ = sender.send(Message::Event(json.to_string()));
    }
}

/// Extract the "data" value from a JSON event envelope if the type matches.
/// Uses simple string searching to avoid adding a JSON parsing dependency.
///
/// NOTE: This does not handle braces inside JSON string values.
/// Safe for server_status and performance events which contain
/// only numbers, simple strings, and flat/shallow objects.
fn extract_event_data(json: &str, event_type: &str) -> Option<String> {
    // CBA_fnc_encodeJSON produces "key": value (with space after colon),
    // so check both formats
    let has_type = json.contains(&format!(r#""type":"{event_type}""#))
        || json.contains(&format!(r#""type": "{event_type}""#));
    if !has_type {
        return None;
    }

    // Bound the "data" key search to after the "type" key position to avoid
    // matching the literal substring "data": inside a value preceding it
    // (e.g. a map or mission name containing that text).
    let type_pos = json.find(r#""type""#).unwrap_or(0);
    let data_start = json[type_pos..]
        .find(r#""data":"#)
        .or_else(|| json[type_pos..].find(r#""data": "#))
        .map(|offset| type_pos + offset)?;
    let after_key = &json[data_start..];
    let colon_offset = after_key.find(':')?;
    let after_colon = &after_key[colon_offset + 1..];
    let brace_offset = after_colon.find('{')?;

    // Verify only whitespace between colon and brace
    if !after_colon[..brace_offset].chars().all(|c| c.is_ascii_whitespace()) {
        return None;
    }

    let value_start = data_start + colon_offset + 1 + brace_offset;
    let bytes = json.as_bytes();

    let mut depth = 0;
    for (i, &byte) in bytes[value_start..].iter().enumerate() {
        match byte {
            b'{' => depth += 1,
            b'}' => {
                depth -= 1;
                if depth == 0 {
                    return Some(json[value_start..value_start + i + 1].to_string());
                }
            }
            _ => {}
        }
    }
    None
}

fn inject_api_port(json: &str, api_port: u16) -> String {
    // Insert "apiPort":N after the opening brace
    format!("{{\"apiPort\":{api_port},{}", &json[1..])
}

pub fn flush() -> bool {
    let (ack_tx, ack_rx) = mpsc::channel();

    if let Ok(channel) = CHANNEL.lock() {
        if let Some(sender) = channel.as_ref() {
            let _ = sender.send(Message::Flush(ack_tx));
        } else {
            return false;
        }
    }

    ack_rx
        .recv_timeout(std::time::Duration::from_secs(10))
        .is_ok()
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_queue_event_when_not_started() {
        // Should not panic
        queue_event("{\"type\":\"test\"}");
    }

    #[test]
    fn test_start_and_stop() {
        start();
        queue_event("{\"type\":\"test\"}");
        stop();
    }

    #[test]
    fn test_event_reaches_http_server() {
        config::store_api_port(2303);

        // Start a local test server
        let server = tiny_http::Server::http("127.0.0.1:0").unwrap();
        let port = server.server_addr().to_ip().unwrap().port();

        // Send directly to test server (bypassing config URL)
        let (sender, receiver) = mpsc::channel::<Message>();
        let url = format!("http://127.0.0.1:{port}/gameservers/events");
        let api_port = config::get_api_port();

        thread::spawn(move || {
            for message in receiver {
                match message {
                    Message::Event(json) => {
                        let body = inject_api_port(&json, api_port);
                        let _ = ureq::post(&url)
                            .set("Content-Type", "application/json")
                            .send_string(&body);
                    }
                    Message::Flush(ack) => {
                        let _ = ack.send(());
                    }
                }
            }
        });

        sender
            .send(Message::Event("{\"type\":\"test\"}".to_string()))
            .unwrap();

        let mut request = server
            .recv_timeout(std::time::Duration::from_secs(5))
            .unwrap()
            .unwrap();
        assert_eq!(request.method(), &tiny_http::Method::Post);

        let mut body = String::new();
        request.as_reader().read_to_string(&mut body).unwrap();
        assert_eq!(body, "{\"apiPort\":2303,\"type\":\"test\"}");
    }

    #[test]
    fn test_inject_api_port() {
        let json = "{\"type\":\"shutdown_complete\",\"data\":{}}";
        let result = inject_api_port(json, 2303);
        assert_eq!(result, "{\"apiPort\":2303,\"type\":\"shutdown_complete\",\"data\":{}}");
    }

    #[test]
    fn test_extract_event_data_status() {
        let json = r#"{"type":"server_status","data":{"map":"Altis","players":5}}"#;
        let result = extract_event_data(json, "server_status");
        assert_eq!(result, Some(r#"{"map":"Altis","players":5}"#.to_string()));
    }

    #[test]
    fn test_extract_event_data_status_spaced() {
        // CBA_fnc_encodeJSON produces spaces after colons
        let json = r#"{"type": "server_status", "data": {"map": "Altis", "players": ["uid1", "uid2"]}}"#;
        let result = extract_event_data(json, "server_status");
        assert_eq!(
            result,
            Some(r#"{"map": "Altis", "players": ["uid1", "uid2"]}"#.to_string())
        );
    }

    #[test]
    fn test_extract_event_data_wrong_type() {
        let json = r#"{"type":"persistence_save","data":{"key":"test"}}"#;
        let result = extract_event_data(json, "server_status");
        assert!(result.is_none());
    }

    #[test]
    fn test_extract_event_data_wrong_type_spaced() {
        let json = r#"{"type": "persistence_save", "data": {"key": "test"}}"#;
        let result = extract_event_data(json, "server_status");
        assert!(result.is_none());
    }

    #[test]
    fn test_extract_event_data_nested_braces() {
        let json = r#"{"type":"server_status","data":{"map":"Altis","nested":{"a":1}}}"#;
        let result = extract_event_data(json, "server_status");
        assert_eq!(result, Some(r#"{"map":"Altis","nested":{"a":1}}"#.to_string()));
    }

    #[test]
    fn test_flush_when_not_started() {
        // Ensure channel is None
        if let Ok(mut channel) = CHANNEL.lock() {
            *channel = None;
        }
        assert!(!flush());
    }
}
