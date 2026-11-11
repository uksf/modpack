use arma_rs::{Context, ExtensionBuilder};

use crate::raw::Raw;
use crate::audio;
use crate::input;
use crate::npc_voices;
use crate::stt;

pub fn register(builder: ExtensionBuilder) -> ExtensionBuilder {
    builder
        .command("npcVoices", npc_voices)
        .command("pressSpace", press_space)
        .command("audioOpen", audio_open)
        .command("audioChunk", audio_chunk)
        .command("audioPlay", audio_play)
        .command("audioFeed", audio_feed)
        .command("audioEnd", audio_end)
        .command("audioPos", audio_pos)
        .command("audioListener", audio_listener)
        .command("audioStop", audio_stop)
        .command("sttStart", stt_start)
        .command("sttStop", stt_stop)
        .command("sttHint", stt_hint)
}

pub fn npc_voices() -> String {
    npc_voices::get()
}

pub fn press_space() -> String {
    input::press_space()
}

pub fn audio_open(id: Raw) -> String {
    audio::open(id.0)
}

pub fn audio_chunk(id: Raw, b64: Raw) -> String {
    audio::chunk(id.0, b64.0)
}

pub fn audio_play(id: Raw, x: f32, y: f32, z: f32, vol: f32, offset_ms: f32) -> String {
    audio::play(id.0, x, y, z, vol, offset_ms)
}

pub fn audio_feed(id: Raw, b64: Raw) -> String {
    audio::feed(id.0, b64.0)
}

pub fn audio_end(id: Raw) -> String {
    audio::end(id.0)
}

pub fn audio_pos(id: Raw, x: f32, y: f32, z: f32, vol: f32) -> String {
    audio::pos(id.0, x, y, z, vol)
}

pub fn audio_listener(dx: f32, dy: f32, dz: f32, ux: f32, uy: f32, uz: f32) -> String {
    audio::listener(dx, dy, dz, ux, uy, uz)
}

pub fn audio_stop(id: Raw) -> String {
    audio::stop(id.0)
}

pub fn stt_start(context: Context) -> String {
    stt::start(context)
}

pub fn stt_stop() -> String {
    stt::stop()
}

pub fn stt_hint(names: Raw) -> String {
    stt::set_hint(names.0)
}
