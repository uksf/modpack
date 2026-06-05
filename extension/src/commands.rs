use arma_rs::Context;

use crate::audio;
use crate::bridge;
use crate::file_export;
use crate::dev_run;
use crate::input;
use crate::stt;

pub fn start(context: Context) -> String {
    bridge::handle_start(context)
}

pub fn stop() -> String {
    bridge::handle_stop()
}

pub fn flush() -> String {
    bridge::handle_flush()
}

pub fn event(body: String) -> String {
    bridge::handle_event(&body)
}

pub fn load(key: String) -> String {
    bridge::handle_load(&key)
}

pub fn press_space() -> String {
    input::press_space()
}

pub fn file_export_open(filename: String) -> String {
    file_export::open(filename)
}

pub fn file_export_write(line: String) -> String {
    file_export::write(line)
}

pub fn file_export_close() -> String {
    file_export::close()
}

pub fn file_export_finish() -> String {
    file_export::finish()
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

pub fn audio_open(id: String) -> String {
    audio::open(id)
}

pub fn audio_chunk(id: String, b64: String) -> String {
    audio::chunk(id, b64)
}

pub fn audio_play(id: String, x: f32, y: f32, z: f32, gain: f32) -> String {
    audio::play(id, x, y, z, gain)
}

pub fn audio_pos(id: String, x: f32, y: f32, z: f32) -> String {
    audio::pos(id, x, y, z)
}

pub fn audio_listener(dx: f32, dy: f32, dz: f32, ux: f32, uy: f32, uz: f32) -> String {
    audio::listener(dx, dy, dz, ux, uy, uz)
}

pub fn audio_stop(id: String) -> String {
    audio::stop(id)
}

pub fn stt_start(context: Context) -> String {
    stt::start(context)
}

pub fn stt_stop() -> String {
    stt::stop()
}
