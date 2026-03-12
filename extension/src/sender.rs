use std::sync::mpsc::{self, Sender};
use std::sync::Mutex;
use std::thread;

use crate::config;

static CHANNEL: Mutex<Option<Sender<String>>> = Mutex::new(None);

pub fn start() {
    let (sender, receiver) = mpsc::channel::<String>();

    if let Ok(mut channel) = CHANNEL.lock() {
        *channel = Some(sender);
    }

    thread::spawn(move || {
        let url = format!("{}/api/gameservers/events", config::API_BASE_URL);
        let api_port = config::get_api_port();

        for json in receiver {
            let result = ureq::post(&url)
                .timeout(std::time::Duration::from_secs(5))
                .set("Content-Type", "application/json")
                .set("X-Api-Port", &api_port.to_string())
                .send_string(&json);

            if let Err(error) = result {
                log::error!("Failed to send event: {error}");
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
            let _ = sender.send(json.to_string());
        }
    }
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
        let (sender, receiver) = mpsc::channel::<String>();
        let url = format!("http://127.0.0.1:{port}/api/gameservers/events");
        let api_port = config::get_api_port();

        thread::spawn(move || {
            for json in receiver {
                let _ = ureq::post(&url)
                    .set("Content-Type", "application/json")
                    .set("X-Api-Port", &api_port.to_string())
                    .send_string(&json);
            }
        });

        sender.send("{\"type\":\"test\"}".to_string()).unwrap();

        let mut request = server
            .recv_timeout(std::time::Duration::from_secs(5))
            .unwrap()
            .unwrap();
        assert_eq!(request.method(), &tiny_http::Method::Post);

        let header = request
            .headers()
            .iter()
            .find(|h| h.field.as_str() == "X-Api-Port")
            .expect("X-Api-Port header missing");
        assert_eq!(header.value.as_str(), "2303");

        let mut body = String::new();
        request.as_reader().read_to_string(&mut body).unwrap();
        assert_eq!(body, "{\"type\":\"test\"}");
    }
}
