use arma_rs::Context;

use crate::bridge;
use crate::config_export;
use crate::dev_run;
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

pub fn config_export_finish() -> String {
    config_export::finish()
}

pub fn dev_run_open(run_id: String) -> String {
    dev_run::open(run_id)
}

pub fn dev_run_chunk(run_id: String, chunk: String) -> String {
    dev_run::chunk(run_id, chunk)
}

pub fn dev_run_log(run_id: String, line: String) -> String {
    dev_run::log(run_id, line)
}

pub fn dev_run_finish(run_id: String) -> String {
    dev_run::finish(run_id)
}
