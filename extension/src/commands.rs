use arma_rs::Context;

use crate::bridge;
use crate::config_export;
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

pub fn press_space() -> String {
    input::press_space()
}

pub fn config_export_open(filename: String) -> String {
    config_export::open(filename)
}

pub fn config_export_write(line: String) -> String {
    config_export::write(line)
}

pub fn config_export_close() -> String {
    config_export::close()
}
