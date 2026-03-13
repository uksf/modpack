use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::Mutex;
use std::thread::{self, JoinHandle};

use arma_rs::Context;
use crossbeam_channel::Sender;

use crate::config;
use crate::listener;
use crate::sender;

static RUNNING: AtomicBool = AtomicBool::new(false);
static CALLBACK_TX: Mutex<Option<Sender<CallbackRequest>>> = Mutex::new(None);
static BRIDGE_HANDLE: Mutex<Option<JoinHandle<()>>> = Mutex::new(None);

struct CallbackRequest {
    function: String,
    data: String,
}

/// Send a callback to Arma via the bridge thread.
/// Called by loader and listener from background threads.
pub fn fire_callback(function: &str, data: &str) {
    if let Ok(guard) = CALLBACK_TX.lock()
        && let Some(sender) = guard.as_ref()
    {
        let _ = sender.send(CallbackRequest {
            function: function.to_string(),
            data: data.to_string(),
        });
    }
}

pub fn handle_start(context: Context) -> String {
    log::info!("Start command received");

    if RUNNING.load(Ordering::SeqCst) {
        log::warn!("Already running, ignoring start");
        return "already running".to_string();
    }

    log::info!("Searching for -apiport in launch arguments");
    let Some(port) = config::find_api_port() else {
        log::error!("-apiport not found in launch arguments");
        return "error: -apiport not found in launch arguments".to_string();
    };
    log::info!("Found API port: {port}");

    config::store_api_port(port);

    // Set up callback bridge before starting listener/loader
    let (tx, rx) = crossbeam_channel::unbounded();
    if let Ok(mut guard) = CALLBACK_TX.lock() {
        *guard = Some(tx);
    }

    let handle = thread::spawn(move || {
        log::info!("Callback bridge thread started");
        for request in rx {
            let _ = context.callback_data("uksf", &request.function, request.data);
        }
        log::info!("Callback bridge thread exiting");
    });

    if let Ok(mut guard) = BRIDGE_HANDLE.lock() {
        *guard = Some(handle);
    }

    log::info!("Starting listener on 127.0.0.1:{port}");
    if let Err(error) = listener::start(port) {
        log::error!("Failed to start listener: {error}");
        stop_callback_bridge();
        return format!("error: failed to start listener: {error}");
    }
    log::info!("Listener started");

    log::info!("Starting sender thread");
    sender::start();
    RUNNING.store(true, Ordering::SeqCst);

    let pid = std::process::id();
    log::info!("Extension fully started on port {port}, pid {pid}");
    format!("started on port {port} pid {pid}")
}

pub fn handle_stop() -> String {
    log::info!("Stop command received");

    if !RUNNING.load(Ordering::SeqCst) {
        log::info!("Not running, nothing to stop");
        return "not running".to_string();
    }

    log::info!("Stopping listener");
    listener::stop();
    log::info!("Stopping sender");
    sender::stop();
    stop_callback_bridge();
    RUNNING.store(false, Ordering::SeqCst);

    log::info!("Extension stopped");
    "stopped".to_string()
}

pub fn handle_load(key: &str) -> String {
    if !RUNNING.load(Ordering::SeqCst) {
        log::warn!("Load requested for '{key}' but extension not running");
        return "error: not running".to_string();
    }

    log::info!("Loading persistence key: {key}");
    crate::loader::load(key);
    "loading".to_string()
}

pub fn handle_flush() -> String {
    if !RUNNING.load(Ordering::SeqCst) {
        return "not running".to_string();
    }

    log::info!("Flushing sender queue");
    if sender::flush() {
        log::info!("Flush complete");
        "flushed".to_string()
    } else {
        log::warn!("Flush timed out");
        "flush timeout".to_string()
    }
}

pub fn handle_event(json: &str) -> String {
    if !RUNNING.load(Ordering::SeqCst) {
        return "error: not running".to_string();
    }

    log::debug!("Queuing event: {json}");
    sender::queue_event(json);
    "queued".to_string()
}

fn stop_callback_bridge() {
    if let Ok(mut guard) = CALLBACK_TX.lock() {
        *guard = None;
    }
    if let Ok(mut guard) = BRIDGE_HANDLE.lock()
        && let Some(handle) = guard.take()
    {
        let _ = handle.join();
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_event_before_start() {
        RUNNING.store(false, Ordering::SeqCst);
        let result = handle_event("{\"type\":\"test\"}");
        assert_eq!(result, "error: not running");
    }

    #[test]
    fn test_load_before_start() {
        RUNNING.store(false, Ordering::SeqCst);
        let result = handle_load("test_key");
        assert_eq!(result, "error: not running");
    }

    #[test]
    fn test_stop_before_start() {
        RUNNING.store(false, Ordering::SeqCst);
        let result = handle_stop();
        assert_eq!(result, "not running");
    }

    #[test]
    fn test_flush_before_start() {
        RUNNING.store(false, Ordering::SeqCst);
        let result = handle_flush();
        assert_eq!(result, "not running");
    }
}
