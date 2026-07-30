use rust_embed::RustEmbed;
use std::path::Path;

#[derive(RustEmbed)]
#[folder = "resources"]
struct Assets;

/// Extract the embedded OpenAL32.dll to the process working directory (the Arma
/// root) if not already present, so `Alto::load_default()` finds it. This is the
/// exact proven approach from ArmaRadio `src/audio.rs` — a bare relative path,
/// NOT next to current_exe(). Do not "improve" the path; this is the location
/// the Windows loader resolves for the extension.
fn ensure_openal_dll() {
    let target = Path::new("OpenAL32.dll");
    if target.exists() {
        return;
    }
    match Assets::get("OpenAL32.dll") {
        Some(dll) => {
            if std::fs::write(target, dll.data.as_ref()).is_err() {
                log::error!("audio: failed to write OpenAL32.dll");
            } else {
                log::info!("audio: extracted OpenAL32.dll");
            }
        }
        None => log::error!("audio: embedded OpenAL32.dll missing"),
    }
}

use std::io::Cursor;

pub struct DecodedClip {
    pub samples: Vec<i16>,
    pub freq: u32,
}

/// Decode a complete WAV byte buffer to mono 16-bit PCM. Multi-channel input is
/// downmixed by averaging interleaved frames.
pub fn decode_wav(bytes: &[u8]) -> Result<DecodedClip, String> {
    let mut reader = hound::WavReader::new(Cursor::new(bytes))
        .map_err(|e| format!("wav header: {e}"))?;
    let spec = reader.spec();
    if spec.bits_per_sample != 16 || spec.sample_format != hound::SampleFormat::Int {
        return Err(format!(
            "unsupported wav format: {} bit {:?}",
            spec.bits_per_sample, spec.sample_format
        ));
    }
    let raw: Vec<i16> = reader
        .samples::<i16>()
        .collect::<Result<_, _>>()
        .map_err(|e| format!("wav samples: {e}"))?;

    let channels = spec.channels.max(1) as usize;
    let samples = if channels == 1 {
        raw
    } else {
        raw.chunks(channels)
            .map(|frame| {
                let sum: i32 = frame.iter().map(|&s| s as i32).sum();
                (sum / channels as i32) as i16
            })
            .collect()
    };

    Ok(DecodedClip { samples, freq: spec.sample_rate })
}

use base64::{engine::general_purpose::STANDARD, Engine};

/// Accumulates base64 chunks for one clip, decoded to raw bytes on completion.
pub struct ClipAccumulator {
    b64: String,
}

impl ClipAccumulator {
    pub fn new() -> Self {
        Self { b64: String::new() }
    }

    pub fn push(&mut self, chunk: &str) {
        self.b64.push_str(chunk);
    }

    pub fn decode(&self) -> Result<Vec<u8>, String> {
        STANDARD
            .decode(self.b64.as_bytes())
            .map_err(|e| format!("base64: {e}"))
    }
}

use std::collections::HashMap;
use std::sync::mpsc::{self, Sender};
use std::sync::Mutex;
use std::thread;
use std::time::{Duration, Instant};

use alto::{Alto, Context, Mono, Source, SourceState, StreamingSource};

use crate::audio_dsp::LowPass4;

enum AudioMsg {
    Open { id: String },
    Chunk { id: String, b64: String },
    /// Streaming variant of Chunk: base64 raw i16 little-endian PCM at STREAM_FREQ,
    /// appended to a Playing that may already be sounding. Frames arrive over the
    /// network; the Playing is created on the first Feed, not on Play.
    Feed { id: String, b64: String },
    Play { id: String, pos: [f32; 3], vol: f32, offset_ms: f32 },
    Pos { id: String, pos: [f32; 3], vol: f32 },
    Listener { forward: [f32; 3], up: [f32; 3] },
    /// Mark a stream closed: no more Feed frames. The clip finishes naturally
    /// once its queued PCM drains. Distinct from Stop, which halts now.
    End { id: String },
    Stop { id: String },
}

static CHANNEL: Mutex<Option<Sender<AudioMsg>>> = Mutex::new(None);

/// A streaming clip: decoded PCM fed in chunks, low-passed per chunk at a
/// cutoff that tracks `vol`. Gain is `vol` on the source. `smoothed_cutoff`
/// lerps toward the target to avoid zipper noise (ACRE smooths over 4800 samples).
struct Playing {
    source: StreamingSource,
    samples: Vec<i16>,
    cursor: usize,
    freq: i32,
    filter: LowPass4,
    smoothed_cutoff: f32,
    target_cutoff: f32,
    last_touch: Instant,
    /// True while Feed frames may still arrive. The pump pauses rather than
    /// stopping on an empty queue while open, so a network stall never drops
    /// the clip.
    open: bool,
    /// Samples the pump holds back before first playback (network jitter
    /// budget). Zero for one-shot clips fed whole via Play; the first Feed
    /// sets it.
    prebuffer: usize,
}

const CHUNK_SAMPLES_PER_SEC_DIV: usize = 50; // ~20 ms chunks
const TARGET_QUEUED: i32 = 6;                // ~120 ms buffered
const CUTOFF_SMOOTH: f32 = 0.25;             // per-chunk lerp toward target
/// Pocket-tts sample rate. Streamed frames are raw i16 LE at this rate.
pub(crate) const STREAM_FREQ: i32 = 24000;
/// Headroom before first playback: covers a network hiccup, not a slow engine.
/// Dead time the player waits through; SPEECH_PREBUFFER_MS mirrors it for the mouth.
pub(crate) const STREAM_PREBUFFER_MS: usize = 200;

/// Drop a source if no position update arrives within this window (NPC deleted
/// / mission ended without an explicit stop).
const WATCHDOG: Duration = Duration::from_secs(30);

/// Sample index for a playback offset in milliseconds, clamped to the clip length.
fn offset_to_cursor(offset_ms: f32, freq: u32, len: usize) -> usize {
    ((offset_ms.max(0.0) / 1000.0 * freq as f32) as usize).min(len)
}

/// Filter one PCM chunk through the low-pass, normalising to f32 and back,
/// clamped to i16 range. Equivalent to ACRE's FilterOcclusion round-trip; the
/// `as i16` cast truncates rather than floors (sub-LSB difference, inaudible).
fn filter_chunk(samples: &[i16], filter: &mut LowPass4) -> Vec<i16> {
    samples
        .iter()
        .map(|&s| {
            let y = filter.process(s as f32 / 32768.0).clamp(-1.0, 1.0);
            (y * 32767.0) as i16
        })
        .collect()
}

/// Open the OpenAL device + context and pin the listener at the origin. Initial
/// orientation faces +Z; it is overwritten each frame by `Listener` messages.
/// Returns None if OpenAL is unavailable (e.g. headless server) — the thread
/// then no-ops every message.
fn open_context(alto: &Alto) -> Option<Context> {
    let device = alto.open(None).map_err(|e| log::error!("audio: open device: {e}")).ok()?;
    let context = device.new_context(None).map_err(|e| log::error!("audio: new context: {e}")).ok()?;
    let _ = context.set_position([0.0f32, 0.0, 0.0]);
    let _ = context.set_velocity([0.0f32, 0.0, 0.0]);
    let _ = context.set_orientation(([0.0f32, 0.0, 1.0], [0.0f32, 1.0, 0.0]));
    context.set_distance_model(alto::DistanceModel::Exponent);
    let _ = context.set_meters_per_unit(1.0);
    // NPC speech does not benefit from doppler; 0 avoids pitch artefacts.
    let _ = context.set_doppler_factor(0.0);
    Some(context)
}

fn run_audio_thread(rx: mpsc::Receiver<AudioMsg>) {
    ensure_openal_dll();
    let alto = match Alto::load_default() {
        Ok(a) => a,
        Err(e) => {
            log::error!("audio: Alto::load_default failed: {e}");
            for _ in rx {} // drain so senders never block
            return;
        }
    };
    let context = match open_context(&alto) {
        Some(c) => c,
        None => {
            for _ in rx {}
            return;
        }
    };

    let mut pending: HashMap<String, ClipAccumulator> = HashMap::new();
    let mut playing: HashMap<String, Playing> = HashMap::new();

    loop {
        match rx.recv_timeout(Duration::from_millis(20)) {
            Ok(AudioMsg::Open { id }) => {
                pending.insert(id, ClipAccumulator::new());
            }
            Ok(AudioMsg::Chunk { id, b64 }) => {
                if let Some(acc) = pending.get_mut(&id) {
                    acc.push(&b64);
                }
            }
            Ok(AudioMsg::Feed { id, b64 }) => {
                handle_feed(&context, &mut playing, id, b64);
            }
            Ok(AudioMsg::Play { id, pos, vol, offset_ms }) => {
                let vol = if vol.is_finite() { vol.max(0.0) } else { 1.0 };
                if let Some(acc) = pending.remove(&id) {
                    match start_streaming(&context, &acc, pos, vol, offset_ms) {
                        Ok(p) => {
                            playing.insert(id, p);
                        }
                        Err(e) => log::error!("audio: play {id}: {e}"),
                    }
                } else if let Some(p) = playing.get_mut(&id) {
                    // Streamed clip: Play sets where it sits and how loud. The
                    // offset still applies if playback has not started yet.
                    let _ = p.source.set_position(pos);
                    let _ = p.source.set_gain(vol);
                    p.target_cutoff = crate::audio_dsp::cutoff_from_vol(vol, p.freq as u32);
                    if p.cursor == 0 {
                        p.cursor = offset_to_cursor(offset_ms, p.freq as u32, p.samples.len());
                    }
                    p.last_touch = Instant::now();
                }
            }
            Ok(AudioMsg::Pos { id, pos, vol }) => {
                let vol = if vol.is_finite() { vol.max(0.0) } else { 1.0 };
                if let Some(p) = playing.get_mut(&id) {
                    let _ = p.source.set_position(pos);
                    let _ = p.source.set_gain(vol);
                    p.target_cutoff = crate::audio_dsp::cutoff_from_vol(vol, p.freq as u32);
                    p.last_touch = Instant::now();
                }
            }
            Ok(AudioMsg::Listener { forward, up }) => {
                let _ = context.set_orientation((forward, up));
            }
            Ok(AudioMsg::End { id }) => {
                // Close the stream; the clip plays out what it has buffered.
                if let Some(p) = playing.get_mut(&id) {
                    p.open = false;
                    p.last_touch = Instant::now();
                }
            }
            Ok(AudioMsg::Stop { id }) => {
                if let Some(mut p) = playing.remove(&id) {
                    p.source.stop();
                }
                pending.remove(&id);
            }
            Err(mpsc::RecvTimeoutError::Timeout) => {}
            Err(mpsc::RecvTimeoutError::Disconnected) => break,
        }
        // Ordering is load-bearing: pump before sweep so an underrun-recovered
        // source is back in Playing before sweep inspects state, else sweep would
        // reclaim it mid-clip.
        for p in playing.values_mut() {
            pump(&context, p);
        }
        sweep(&mut playing);
    }
}

/// Create an empty streaming source at `pos`/`vol`, primed with its low-pass.
/// Used for both one-shot clips (samples loaded by `start_streaming`) and
/// streams (samples appended by `handle_feed`).
fn new_streaming(context: &Context, pos: [f32; 3], vol: f32, freq: i32) -> Result<Playing, String> {
    let mut source = context
        .new_streaming_source()
        .map_err(|e| format!("new_streaming_source: {e}"))?;
    let _ = source.set_soft_spatialization(alto::SoftSourceSpatialization::Enabled);
    let _ = source.set_gain(vol.max(0.0));
    let _ = source.set_position(pos);

    let cutoff = crate::audio_dsp::cutoff_from_vol(vol, freq as u32);
    let filter = LowPass4::new(freq as f32);

    Ok(Playing {
        source,
        samples: Vec::new(),
        cursor: 0,
        freq,
        filter,
        smoothed_cutoff: cutoff,
        target_cutoff: cutoff,
        last_touch: Instant::now(),
        open: false,
        prebuffer: 0,
    })
}

/// Decode one Feed frame (base64 raw i16 LE at STREAM_FREQ) and append it to the
/// clip, creating the Playing on the first frame. The stream starts open and is
/// closed by Stop; the first frame sets the prebuffer headroom.
fn handle_feed(context: &Context, playing: &mut HashMap<String, Playing>, id: String, b64: String) {
    let bytes = match STANDARD.decode(b64.as_bytes()) {
        Ok(b) => b,
        Err(e) => {
            log::error!("audio: feed {id} base64: {e}");
            return;
        }
    };
    if !playing.contains_key(&id) {
        match new_streaming(context, [0.0; 3], 1.0, STREAM_FREQ) {
            Ok(mut p) => {
                p.open = true;
                p.prebuffer = STREAM_FREQ as usize * STREAM_PREBUFFER_MS / 1000;
                playing.insert(id.clone(), p);
            }
            Err(e) => {
                log::error!("audio: feed {id}: {e}");
                return;
            }
        }
    }
    if let Some(p) = playing.get_mut(&id) {
        let mut pcm = Vec::with_capacity(bytes.len() / 2);
        for pair in bytes.chunks_exact(2) {
            pcm.push(i16::from_le_bytes([pair[0], pair[1]]));
        }
        p.samples.extend_from_slice(&pcm);
        p.last_touch = Instant::now();
    }
}

/// Build a streaming source from accumulated bytes. Decodes the full clip into a
/// PCM buffer and loads it into the Playing. Buffers are queued lazily by `pump`.
fn start_streaming(
    context: &Context,
    acc: &ClipAccumulator,
    pos: [f32; 3],
    vol: f32,
    offset_ms: f32,
) -> Result<Playing, String> {
    let bytes = acc.decode()?;
    let clip = decode_wav(&bytes)?;
    let freq = clip.freq as i32;
    let cursor = offset_to_cursor(offset_ms, clip.freq, clip.samples.len());

    let mut p = new_streaming(context, pos, vol, freq)?;
    p.samples = clip.samples;
    p.cursor = cursor;
    Ok(p)
}

/// Recycle processed buffers and top up the queue with freshly filtered chunks,
/// lerping the cutoff toward its target so occlusion changes smoothly. Starts the
/// source once enough is buffered. An open stream pauses on underrun and resumes
/// when the next frame arrives; it is never stopped by an empty queue.
fn pump(context: &Context, p: &mut Playing) {
    while p.source.buffers_processed() > 0 {
        let _ = p.source.unqueue_buffer();
    }
    let chunk = (p.freq as usize / CHUNK_SAMPLES_PER_SEC_DIV).max(1);
    while p.source.buffers_queued() < TARGET_QUEUED && p.cursor < p.samples.len() {
        p.smoothed_cutoff += (p.target_cutoff - p.smoothed_cutoff) * CUTOFF_SMOOTH;
        p.filter.set_cutoff(p.smoothed_cutoff);
        let end = (p.cursor + chunk).min(p.samples.len());
        let filtered = filter_chunk(&p.samples[p.cursor..end], &mut p.filter);
        let frames: Vec<Mono<i16>> = filtered.into_iter().map(|s| Mono { center: s }).collect();
        match context.new_buffer::<Mono<i16>, _>(frames, p.freq) {
            Ok(buf) => {
                if p.source.queue_buffer(buf).is_ok() {
                    p.cursor = end;
                    p.last_touch = Instant::now(); // streaming progress = liveness
                } else {
                    break; // queue rejected; retry this chunk next pump, do NOT advance
                }
            }
            Err(_) => break,
        }
    }
    let buffered = p.source.buffers_queued() as usize * chunk;
    // Readiness is measured against PCM received, not queue depth: the queue holds at
    // most TARGET_QUEUED buffers (~120 ms), so any prebuffer above that could never be
    // reached and the clip would stay silent until the stream closed.
    let ready = if p.open { p.samples.len() >= p.prebuffer } else { p.source.buffers_queued() > 0 };
    match p.source.state() {
        SourceState::Playing if buffered == 0 && p.open => {
            // Underrun on an open stream: pause and wait for the next frame
            // rather than stopping the source.
            let _ = p.source.pause();
        }
        SourceState::Paused if ready => {
            let _ = p.source.play();
        }
        SourceState::Initial if ready => {
            let _ = p.source.play();
        }
        _ => {}
    }
}

/// Remove sources that finished naturally, drained their stream, or went silent
/// past the watchdog.
fn sweep(playing: &mut HashMap<String, Playing>) {
    let now = Instant::now();
    playing.retain(|_id, p| {
        // Reclaim only when the clip is genuinely finished (PCM exhausted AND queue
        // empty) or stuck past the watchdog. An open stream is never finished: its
        // samples can still grow. A bare Stopped check would kill a clip on a
        // transient underrun (new_buffer failure) before its cursor is done — pump
        // re-queues such a source; the watchdog catches one that never recovers.
        let finished = !p.open && p.cursor >= p.samples.len() && p.source.buffers_queued() == 0;
        let expired = now.duration_since(p.last_touch) > WATCHDOG;
        if finished || expired {
            p.source.stop();
            false
        } else {
            true
        }
    });
}

fn ensure_audio_thread() {
    let mut channel = CHANNEL.lock().unwrap();
    if channel.is_some() {
        return;
    }
    let (tx, rx) = mpsc::channel::<AudioMsg>();
    *channel = Some(tx);
    thread::spawn(move || run_audio_thread(rx));
}

fn send(msg: AudioMsg) {
    ensure_audio_thread();
    let channel = CHANNEL.lock().unwrap();
    if let Some(tx) = channel.as_ref() {
        let _ = tx.send(msg);
    }
}

pub fn open(id: String) -> String {
    send(AudioMsg::Open { id });
    "ok".to_string()
}

pub fn chunk(id: String, b64: String) -> String {
    send(AudioMsg::Chunk { id, b64 });
    "ok".to_string()
}

pub fn play(id: String, x: f32, y: f32, z: f32, vol: f32, offset_ms: f32) -> String {
    send(AudioMsg::Play { id, pos: [x, y, z], vol, offset_ms });
    "ok".to_string()
}

/// Feed one PCM frame into an open stream. The stream is created on the first
/// frame at 24 kHz mono; End closes it, Stop halts it.
pub fn feed(id: String, b64: String) -> String {
    send(AudioMsg::Feed { id, b64 });
    "ok".to_string()
}

/// Mark a stream closed; the clip plays out its buffered PCM.
pub fn end(id: String) -> String {
    send(AudioMsg::End { id });
    "ok".to_string()
}

pub fn pos(id: String, x: f32, y: f32, z: f32, vol: f32) -> String {
    send(AudioMsg::Pos { id, pos: [x, y, z], vol });
    "ok".to_string()
}

pub fn listener(dx: f32, dy: f32, dz: f32, ux: f32, uy: f32, uz: f32) -> String {
    send(AudioMsg::Listener { forward: [dx, dy, dz], up: [ux, uy, uz] });
    "ok".to_string()
}

pub fn stop(id: String) -> String {
    send(AudioMsg::Stop { id });
    "ok".to_string()
}

#[cfg(test)]
mod tests {
    use super::*;

    /// Build a minimal 16-bit PCM mono WAV in memory for tests.
    fn make_wav(samples: &[i16], freq: u32) -> Vec<u8> {
        let spec = hound::WavSpec {
            channels: 1,
            sample_rate: freq,
            bits_per_sample: 16,
            sample_format: hound::SampleFormat::Int,
        };
        let mut buf = std::io::Cursor::new(Vec::new());
        {
            let mut writer = hound::WavWriter::new(&mut buf, spec).unwrap();
            for &s in samples {
                writer.write_sample(s).unwrap();
            }
            writer.finalize().unwrap();
        }
        buf.into_inner()
    }

    #[test]
    fn decode_wav_returns_samples_and_freq() {
        let wav = make_wav(&[0, 100, -100, 32767, -32768], 24000);
        let decoded = decode_wav(&wav).unwrap();
        assert_eq!(decoded.freq, 24000);
        assert_eq!(decoded.samples, vec![0, 100, -100, 32767, -32768]);
    }

    #[test]
    fn decode_wav_rejects_garbage() {
        assert!(decode_wav(b"not a wav").is_err());
    }

    #[test]
    fn accumulator_concats_and_decodes_base64() {
        use base64::{engine::general_purpose::STANDARD, Engine};
        let original = b"hello world bytes";
        let b64 = STANDARD.encode(original);
        let (a, b) = b64.split_at(5);

        let mut acc = ClipAccumulator::new();
        acc.push(a);
        acc.push(b);
        let bytes = acc.decode().unwrap();
        assert_eq!(bytes, original);
    }

    #[test]
    fn accumulator_rejects_bad_base64() {
        let mut acc = ClipAccumulator::new();
        acc.push("!!!not base64!!!");
        assert!(acc.decode().is_err());
    }

    #[test]
    fn offset_to_cursor_clamps_and_scales() {
        assert_eq!(offset_to_cursor(0.0, 24000, 48000), 0);
        assert_eq!(offset_to_cursor(1000.0, 24000, 48000), 24000); // 1s @24k
        assert_eq!(offset_to_cursor(5000.0, 24000, 48000), 48000); // clamps to len
        assert_eq!(offset_to_cursor(-50.0, 24000, 48000), 0);      // negative floored
    }

    #[test]
    fn filter_chunk_stays_in_range_and_quiets_when_muffled() {
        use crate::audio_dsp::{LowPass4, cutoff_from_vol};
        let pcm: Vec<i16> = (0..4800).map(|i| if i % 2 == 0 { 16000 } else { -16000 }).collect();
        let mut f = LowPass4::new(24000.0);
        f.set_cutoff(cutoff_from_vol(0.2, 24000)); // muffled
        let out = filter_chunk(&pcm, &mut f);
        assert_eq!(out.len(), pcm.len());
        assert!(out.iter().all(|&s| s.abs() <= i16::MAX));
        let tail_peak = out[2400..].iter().map(|&s| s.unsigned_abs()).max().unwrap();
        assert!(tail_peak < 4000, "muffled Nyquist should be quiet, got {tail_peak}");
    }
}
