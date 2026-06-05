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

use alto::{Alto, Context, Mono, Source, SourceState, StaticSource};

enum AudioMsg {
    Open { id: String },
    Chunk { id: String, b64: String },
    Play { id: String, pos: [f32; 3], gain: f32 },
    Pos { id: String, pos: [f32; 3] },
    Listener { forward: [f32; 3], up: [f32; 3] },
    Stop { id: String },
}

static CHANNEL: Mutex<Option<Sender<AudioMsg>>> = Mutex::new(None);

/// Source plus the wall-clock of its last touch, for the watchdog.
struct Playing {
    source: StaticSource,
    last_touch: Instant,
}

/// Drop a source if no position update arrives within this window (NPC deleted
/// / mission ended without an explicit stop).
const WATCHDOG: Duration = Duration::from_secs(30);

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
        match rx.recv_timeout(Duration::from_millis(250)) {
            Ok(AudioMsg::Open { id }) => {
                pending.insert(id, ClipAccumulator::new());
            }
            Ok(AudioMsg::Chunk { id, b64 }) => {
                if let Some(acc) = pending.get_mut(&id) {
                    acc.push(&b64);
                }
            }
            Ok(AudioMsg::Play { id, pos, gain }) => {
                if let Some(acc) = pending.remove(&id) {
                    match start_source(&context, &acc, pos, gain) {
                        Ok(src) => {
                            playing.insert(id, Playing { source: src, last_touch: Instant::now() });
                        }
                        Err(e) => log::error!("audio: play {id}: {e}"),
                    }
                }
            }
            Ok(AudioMsg::Pos { id, pos }) => {
                if let Some(p) = playing.get_mut(&id) {
                    let _ = p.source.set_position(pos);
                    p.last_touch = Instant::now();
                }
            }
            Ok(AudioMsg::Listener { forward, up }) => {
                let _ = context.set_orientation((forward, up));
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
        sweep(&mut playing);
    }
}

/// Build a static source from accumulated bytes and start it once.
fn start_source(
    context: &Context,
    acc: &ClipAccumulator,
    pos: [f32; 3],
    gain: f32,
) -> Result<StaticSource, String> {
    let bytes = acc.decode()?;
    let clip = decode_wav(&bytes)?;
    let frames: Vec<Mono<i16>> = clip.samples.iter().map(|&s| Mono { center: s }).collect();
    let buffer = context
        .new_buffer::<Mono<i16>, _>(frames, clip.freq as i32)
        .map_err(|e| format!("new_buffer: {e}"))?;

    let mut source = context.new_static_source().map_err(|e| format!("new_static_source: {e}"))?;
    source.set_buffer(std::sync::Arc::new(buffer)).map_err(|e| format!("set_buffer: {e}"))?;
    let _ = source.set_soft_spatialization(alto::SoftSourceSpatialization::Enabled);
    let _ = source.set_gain(gain);
    let _ = source.set_position(pos);
    source.set_looping(false);
    source.play();
    Ok(source)
}

/// Remove sources that finished naturally or went silent past the watchdog.
fn sweep(playing: &mut HashMap<String, Playing>) {
    let now = Instant::now();
    playing.retain(|_id, p| {
        let finished = p.source.state() == SourceState::Stopped;
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

pub fn play(id: String, x: f32, y: f32, z: f32, gain: f32) -> String {
    send(AudioMsg::Play { id, pos: [x, y, z], gain });
    "ok".to_string()
}

pub fn pos(id: String, x: f32, y: f32, z: f32) -> String {
    send(AudioMsg::Pos { id, pos: [x, y, z] });
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
}
