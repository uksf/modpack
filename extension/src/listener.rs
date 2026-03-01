use std::io::Read;
use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::Mutex;
use std::thread::{self, JoinHandle};

use crate::ffi;

static SHOULD_STOP: AtomicBool = AtomicBool::new(false);
static THREAD_HANDLE: Mutex<Option<JoinHandle<()>>> = Mutex::new(None);

pub fn start(port: u16) -> Result<(), String> {
    let address = format!("127.0.0.1:{port}");
    let server = tiny_http::Server::http(&address)
        .map_err(|error| format!("failed to bind {address}: {error}"))?;

    SHOULD_STOP.store(false, Ordering::SeqCst);

    let handle = thread::spawn(move || {
        while !SHOULD_STOP.load(Ordering::SeqCst) {
            let mut request = match server.recv_timeout(std::time::Duration::from_secs(1)) {
                Ok(Some(request)) => request,
                Ok(None) => continue,
                Err(_) => break,
            };

            if request.method() != &tiny_http::Method::Post
                || request.url() != "/command"
            {
                let response = tiny_http::Response::from_string("not found")
                    .with_status_code(404);
                let _ = request.respond(response);
                continue;
            }

            let peer = request.remote_addr().map(|address| address.ip());
            let is_localhost = matches!(
                peer,
                Some(std::net::IpAddr::V4(ip)) if ip.is_loopback()
            ) || matches!(
                peer,
                Some(std::net::IpAddr::V6(ip)) if ip.is_loopback()
            );

            if !is_localhost {
                let response = tiny_http::Response::from_string("forbidden")
                    .with_status_code(403);
                let _ = request.respond(response);
                continue;
            }

            // Reject oversized bodies (max 64KB)
            if request.body_length().is_some_and(|len| len > 65536) {
                let response = tiny_http::Response::from_string("payload too large")
                    .with_status_code(413);
                let _ = request.respond(response);
                continue;
            }

            let mut body = String::new();
            if request.as_reader().take(65536).read_to_string(&mut body).is_ok() {
                ffi::fire_callback("command", &body);
            }

            let response = tiny_http::Response::from_string("ok");
            let _ = request.respond(response);
        }
    });

    if let Ok(mut th) = THREAD_HANDLE.lock() {
        *th = Some(handle);
    }

    Ok(())
}

pub fn stop() {
    SHOULD_STOP.store(true, Ordering::SeqCst);

    // Wait for the listener thread to finish (up to 2 seconds)
    if let Ok(mut th) = THREAD_HANDLE.lock() {
        if let Some(handle) = th.take() {
            let _ = handle.join();
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_start_on_used_port_fails() {
        // Bind a port first
        let server = tiny_http::Server::http("127.0.0.1:0").unwrap();
        let port = server.server_addr().to_ip().unwrap().port();

        // Try to start listener on same port — should fail
        let result = start(port);
        assert!(result.is_err());

        drop(server);
    }

    #[test]
    fn test_listener_receives_command() {
        let port = {
            let temp = std::net::TcpListener::bind("127.0.0.1:0").unwrap();
            temp.local_addr().unwrap().port()
        };

        start(port).unwrap();

        // Give the server thread a moment to start
        std::thread::sleep(std::time::Duration::from_millis(100));

        let response = ureq::post(&format!("http://127.0.0.1:{port}/command"))
            .set("Content-Type", "application/json")
            .send_string("{\"type\":\"shutdown\"}");

        assert!(response.is_ok());

        stop();
    }

    #[test]
    fn test_listener_rejects_wrong_path() {
        let port = {
            let temp = std::net::TcpListener::bind("127.0.0.1:0").unwrap();
            temp.local_addr().unwrap().port()
        };

        start(port).unwrap();

        std::thread::sleep(std::time::Duration::from_millis(100));

        let response = ureq::get(&format!("http://127.0.0.1:{port}/server")).call();
        // Should get 404
        assert!(response.is_err());

        stop();
    }
}
