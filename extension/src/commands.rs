use arma_rs::Context;

use crate::bridge;
use crate::input;

pub fn start(context: Context) -> String {
    bridge::handle_start(context)
}

pub fn stop() -> String {
    bridge::handle_stop()
}

pub fn flush() -> String {
    bridge::handle_flush()
}

pub fn event(json: String) -> String {
    bridge::handle_event(&json)
}

pub fn load(key: String) -> String {
    bridge::handle_load(&key)
}

pub fn click() -> String {
    input::click()
}
