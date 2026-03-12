use std::sync::atomic::{AtomicBool, Ordering};

use crate::config;
use crate::listener;
use crate::loader;
use crate::sender;

static RUNNING: AtomicBool = AtomicBool::new(false);

/// Handle a command string from callExtension
pub fn handle_command(command: &str) -> String {
    if command == "start" {
        return handle_start();
    }
    if command == "stop" {
        return handle_stop();
    }
    if command == "flush" {
        return handle_flush();
    }
    if let Some(key) = command.strip_prefix("load:") {
        return handle_load(key);
    }
    if let Some(json) = command.strip_prefix("event:") {
        return handle_event(json);
    }
    format!("unknown command: {command}")
}

fn handle_start() -> String {
    if RUNNING.load(Ordering::SeqCst) {
        return "already running".to_string();
    }

    let Some(port) = config::find_api_port() else {
        return "error: -apiport not found in launch arguments".to_string();
    };

    config::store_api_port(port);

    if let Err(error) = listener::start(port) {
        return format!("error: failed to start listener: {error}");
    }

    sender::start();
    RUNNING.store(true, Ordering::SeqCst);

    format!("started on port {port}")
}

fn handle_stop() -> String {
    if !RUNNING.load(Ordering::SeqCst) {
        return "not running".to_string();
    }

    listener::stop();
    sender::stop();
    RUNNING.store(false, Ordering::SeqCst);

    "stopped".to_string()
}

fn handle_load(key: &str) -> String {
    if !RUNNING.load(Ordering::SeqCst) {
        return "error: not running".to_string();
    }

    loader::load(key);
    "loading".to_string()
}

fn handle_flush() -> String {
    if !RUNNING.load(Ordering::SeqCst) {
        return "not running".to_string();
    }

    if sender::flush() {
        "flushed".to_string()
    } else {
        "flush timeout".to_string()
    }
}

fn handle_event(json: &str) -> String {
    if !RUNNING.load(Ordering::SeqCst) {
        return "error: not running".to_string();
    }

    sender::queue_event(json);
    "queued".to_string()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_unknown_command() {
        let result = handle_command("foobar");
        assert!(result.starts_with("unknown command"));
    }

    #[test]
    fn test_event_before_start() {
        RUNNING.store(false, Ordering::SeqCst);
        let result = handle_command("event:{\"type\":\"test\"}");
        assert_eq!(result, "error: not running");
    }

    #[test]
    fn test_load_before_start() {
        RUNNING.store(false, Ordering::SeqCst);
        let result = handle_command("load:test_key");
        assert_eq!(result, "error: not running");
    }

    #[test]
    fn test_stop_before_start() {
        RUNNING.store(false, Ordering::SeqCst);
        let result = handle_command("stop");
        assert_eq!(result, "not running");
    }

    #[test]
    fn test_flush_before_start() {
        RUNNING.store(false, Ordering::SeqCst);
        let result = handle_command("flush");
        assert_eq!(result, "not running");
    }
}
