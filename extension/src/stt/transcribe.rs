//! whisper.cpp wrapper. Owns a lazily-loaded model context and turns one
//! assembled utterance (raw interleaved i16 @ 48 kHz) into text.

use std::path::PathBuf;
use std::sync::OnceLock;

use whisper_rs::{FullParams, SamplingStrategy, WhisperContext, WhisperContextParameters};

use super::dsp;
use super::frame::StartInfo;

const MODEL_FILE: &str = "ggml-base.en.bin";

/// Absolute path to the model file that ships next to this DLL. Uses the DLL's
/// own module path (NOT current_exe, which is the game executable).
pub fn model_path() -> Option<PathBuf> {
    use windows::Win32::Foundation::HMODULE;
    use windows::Win32::System::LibraryLoader::{
        GetModuleFileNameW, GetModuleHandleExW, GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
        GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
    };

    // An address inside this DLL, used to resolve our own HMODULE.
    let anchor = model_path as *const () as *const u16;
    let mut module = HMODULE::default();
    let ok = unsafe {
        GetModuleHandleExW(
            GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
            windows::core::PCWSTR(anchor),
            &mut module,
        )
    };
    if ok.is_err() {
        log::error!("stt: GetModuleHandleExW failed");
        return None;
    }

    let mut buf = [0u16; 1024];
    let len = unsafe { GetModuleFileNameW(module, &mut buf) } as usize;
    if len == 0 || len >= buf.len() {
        log::error!("stt: GetModuleFileNameW failed/truncated");
        return None;
    }
    let dll_path = PathBuf::from(String::from_utf16_lossy(&buf[..len]));
    let dir = dll_path.parent()?;
    Some(dir.join(MODEL_FILE))
}

/// Number of whisper threads: keep it modest so it never starves the game.
fn n_threads() -> i32 {
    let cores = std::thread::available_parallelism().map(|n| n.get()).unwrap_or(4);
    cores.clamp(1, 4) as i32
}

pub struct Transcriber {
    ctx: WhisperContext,
}

impl Transcriber {
    /// Load the model. Returns None (logged) if the file is missing or load
    /// fails — STT then no-ops; the game must never crash over a missing model.
    fn load() -> Option<Self> {
        let path = model_path()?;
        if !path.exists() {
            log::error!("stt: model not found at {}", path.display());
            return None;
        }
        match WhisperContext::new_with_params(&path, WhisperContextParameters::default()) {
            Ok(ctx) => {
                log::info!("stt: model loaded from {}", path.display());
                Some(Self { ctx })
            }
            Err(e) => {
                log::error!("stt: failed to load model: {e}");
                None
            }
        }
    }

    fn transcribe(&self, audio_f32_16k_mono: &[f32]) -> Option<String> {
        let mut state = self
            .ctx
            .create_state()
            .map_err(|e| log::error!("stt: create_state: {e}"))
            .ok()?;
        let mut params = FullParams::new(SamplingStrategy::Greedy { best_of: 1 });
        params.set_language(Some("en"));
        params.set_n_threads(n_threads());
        params.set_print_special(false);
        params.set_print_progress(false);
        params.set_print_realtime(false);
        params.set_print_timestamps(false);

        if let Err(e) = state.full(params, audio_f32_16k_mono) {
            log::error!("stt: whisper full() failed: {e}");
            return None;
        }
        let n = state.full_n_segments();
        let mut out = String::new();
        for i in 0..n {
            if let Some(seg) = state.get_segment(i) {
                if let Ok(text) = seg.to_str_lossy() {
                    out.push_str(&text);
                }
            }
        }
        Some(out.trim().to_string())
    }
}

/// Lazily-initialised process-wide transcriber. `None` means unavailable.
static TRANSCRIBER: OnceLock<Option<Transcriber>> = OnceLock::new();

fn transcriber() -> Option<&'static Transcriber> {
    TRANSCRIBER.get_or_init(Transcriber::load).as_ref()
}

/// Minimum samples (post-resample, 16 kHz) to bother transcribing — ~300 ms.
const MIN_SAMPLES_16K: usize = 16000 * 300 / 1000;

/// Full pipeline for one assembled utterance: downmix → resample → normalise →
/// whisper. Returns the trimmed transcript, or None if too short / unavailable
/// / empty.
pub fn transcribe_utterance(start: &StartInfo, raw_interleaved: &[i16]) -> Option<String> {
    let mono = dsp::downmix_to_mono(raw_interleaved, start.channels);
    if start.sample_rate != 48000 {
        log::warn!("stt: unexpected sample rate {}, skipping", start.sample_rate);
        return None;
    }
    let down = dsp::decimate_48k_to_16k(&mono);
    if down.len() < MIN_SAMPLES_16K {
        return None;
    }
    let audio = dsp::i16_to_f32(&down);
    let text = transcriber()?.transcribe(&audio)?;
    if text.is_empty() { None } else { Some(text) }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn short_utterance_is_skipped_without_model() {
        let start = StartInfo { sample_rate: 48000, channels: 1, utt_id: 1 };
        let raw = vec![0i16; 4800]; // 100 ms @ 48k
        assert_eq!(transcribe_utterance(&start, &raw), None);
    }

    #[test]
    fn unexpected_sample_rate_is_skipped() {
        let start = StartInfo { sample_rate: 44100, channels: 1, utt_id: 1 };
        let raw = vec![0i16; 48000];
        assert_eq!(transcribe_utterance(&start, &raw), None);
    }
}
