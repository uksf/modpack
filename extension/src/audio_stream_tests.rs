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
    // The pump's ready gate, measured against PCM received: hold back below the
    // prebuffer, start once that much has arrived, and play whatever is left the
    // moment the stream closes.
    let prebuffer = STREAM_FREQ as usize * STREAM_PREBUFFER_MS / 1000;
    let ready = |open: bool, fed: usize, queued: usize| if open { fed >= prebuffer } else { queued > 0 };
    assert!(!ready(true, prebuffer - 1, 0)); // below headroom
    assert!(ready(true, prebuffer, 0)); // headroom met
    assert!(ready(false, 0, 1)); // closed with any queue
    assert!(!ready(false, 0, 0)); // closed and empty
}

#[test]
fn prebuffer_is_reachable_given_the_queue_ceiling() {
    // Regression: readiness was measured from queued buffers, which cap at
    // TARGET_QUEUED (6) chunks of 20 ms — 120 ms. Any larger prebuffer was
    // unreachable, so a streamed clip stayed silent until the stream closed and
    // the whole line played after the mouth animation had already run.
    let queue_ceiling_ms = 6 * 1000 / 50;
    assert!(
        STREAM_PREBUFFER_MS > queue_ceiling_ms,
        "prebuffer must exceed the {queue_ceiling_ms} ms queue ceiling for this regression to bite"
    );
    let prebuffer = STREAM_FREQ as usize * STREAM_PREBUFFER_MS / 1000;
    let fed_after_one_frame = STREAM_FREQ as usize * 750 / 1000;
    assert!(fed_after_one_frame >= prebuffer, "one 750 ms frame must satisfy the prebuffer");
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
