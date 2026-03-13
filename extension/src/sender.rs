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
        let url = format!("{}/api/gameservers/events", config::API_BASE_URL);
        let api_port = config::get_api_port();

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
    if let Ok(channel) = CHANNEL.lock() {
        if let Some(sender) = channel.as_ref() {
            let _ = sender.send(Message::Event(json.to_string()));
        }
    }
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
        let url = format!("http://127.0.0.1:{port}/api/gameservers/events");
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
    fn test_flush_when_not_started() {
        // Ensure channel is None
        if let Ok(mut channel) = CHANNEL.lock() {
            *channel = None;
        }
        assert!(!flush());
    }
}
