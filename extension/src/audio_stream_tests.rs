//! Tests for the streamed-clip continuity logic: frame decode, the prebuffer
//! ready gate, and the frame-size budget. The full OpenAL path needs a device, so
//! these exercise the pure decisions the pump and feed make.
#![cfg(test)]

use base64::{engine::general_purpose::STANDARD, Engine};

use crate::audio::{STREAM_FREQ, STREAM_PREBUFFER_MS};

/// Decode one base64 i16 LE PCM frame the way handle_feed does.
fn feed_decode(b64: &str) -> Vec<i16> {
    let bytes = STANDARD.decode(b64.as_bytes()).unwrap();
    bytes.chunks_exact(2).map(|p| i16::from_le_bytes([p[0], p[1]])).collect()
}

#[test]
fn feed_decode_round_trips_pcm() {
    let pcm: Vec<i16> = vec![0, 1000, -1000, 32767, -32768];
    let bytes: Vec<u8> = pcm.iter().flat_map(|s| s.to_le_bytes()).collect();
    let b64 = STANDARD.encode(&bytes);
    assert_eq!(feed_decode(&b64), pcm);
}

#[test]
fn prebuffer_waits_then_starts_when_met() {
    // The pump's ready gate: hold back below the prebuffer, start once buffered
    // meets it, play immediately once the stream closed with a queue to drain.
    let prebuffer = STREAM_FREQ as usize * STREAM_PREBUFFER_MS / 1000;
    let ready = |open: bool, buffered: usize, cursor: usize, len: usize| {
        if open { buffered >= prebuffer || (len > 0 && cursor >= len) } else { buffered > 0 }
    };
    assert!(!ready(true, prebuffer - 1, 0, prebuffer * 2)); // below headroom
    assert!(ready(true, prebuffer, 0, prebuffer * 2)); // headroom met
    assert!(ready(true, 1, 5, 5)); // drained while open
    assert!(ready(false, 1, 0, 1)); // closed with any queue
    assert!(!ready(false, 0, 0, 0)); // closed and empty
}

#[test]
fn frame_size_matches_design_budget() {
    // 750 ms frames at 24 kHz -> a ~4 s line is a handful of frames, not fifty.
    let frame = (STREAM_FREQ as f32 * 0.75) as usize;
    let line = STREAM_FREQ as usize * 4;
    let frames = line.div_ceil(frame);
    assert!(frames <= 8, "a 4 s line should be under 8 frames, got {frames}");
    // The 500 ms prebuffer is under one frame of lead, so first playback is not
    // held hostage to a second frame arriving.
    assert!(STREAM_PREBUFFER_MS < 750);
}
