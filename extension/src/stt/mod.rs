pub mod dsp;
pub mod frame;
pub mod pipe;
pub mod transcribe;

use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::mpsc::{self, Receiver, Sender};
use std::sync::Mutex;
use std::thread;
use std::time::Instant;

use arma_rs::Context;

use self::frame::StartInfo;

static STARTED: AtomicBool = AtomicBool::new(false);
static CALLBACK_TX: Mutex<Option<Sender<(u32, String, Instant)>>> = Mutex::new(None);
static TRANSCRIBE_TX: Mutex<Option<Sender<(StartInfo, Vec<i16>, u32, Instant)>>> = Mutex::new(None);
static HINT: Mutex<String> = Mutex::new(String::new());

pub fn tlog(msg: &str) {
    log::info!("stt: {msg}");
}

fn utt_log(utt_id: u32, since: Instant, msg: &str) {
    log::info!("stt: utt={utt_id} +{}ms {msg}", since.elapsed().as_millis());
}

const HINT_MAX: usize = 400;

/// Live name list for Whisper. Empty is fine: decode then has no extra bias.
pub fn set_hint(raw: String) -> String {
    let cleaned: String = raw
        .chars()
        .filter(|c| *c != '\0' && (*c == ' ' || *c == '-' || *c == '\'' || c.is_alphabetic()))
        .take(HINT_MAX)
        .collect();
    let cleaned = cleaned.split_whitespace().collect::<Vec<_>>().join(" ");
    if let Ok(mut guard) = HINT.lock() {
        *guard = cleaned.clone();
    }
    cleaned
}

pub fn hint() -> String {
    HINT.lock().map(|g| g.clone()).unwrap_or_default()
}

/// Escape a transcript for embedding in an SQF-notation string literal: double
/// any internal quotes so `parseSimpleArray` reads it back intact.
fn sqf_escape(text: &str) -> String {
    text.replace('"', "\"\"")
}

/// Hand assembled PCM to the whisper worker. Never call whisper here.
pub fn enqueue_utterance_at(info: StartInfo, samples: Vec<i16>, utt_id: u32, queued: Instant) {
    if let Ok(guard) = TRANSCRIBE_TX.lock()
        && let Some(tx) = guard.as_ref()
    {
        if tx.send((info, samples, utt_id, queued)).is_err() {
            tlog("transcribe worker dropped an utterance");
        }
    } else {
        tlog("transcribe worker not armed; dropping utterance");
    }
}

fn spawn_callback_pump(context: Context, rx: Receiver<(u32, String, Instant)>) {
    thread::spawn(move || {
        for (utt_id, text, since) in rx {
            let data = format!("[{},\"{}\"]", utt_id, sqf_escape(&text));
            let _ = context.callback_data("uksf", "sttTranscript", data);
            utt_log(utt_id, since, "callback");
        }
    });
}

fn spawn_transcribe_worker(rx: Receiver<(StartInfo, Vec<i16>, u32, Instant)>) {
    thread::spawn(move || {
        for (info, samples, utt_id, queued) in rx {
            utt_log(utt_id, queued, "whisper begin");
            let whisper_start = Instant::now();
            match transcribe::transcribe_utterance(&info, &samples) {
                Some(text) => {
                    utt_log(utt_id, whisper_start, &format!("\"{text}\""));
                    if let Ok(guard) = CALLBACK_TX.lock()
                        && let Some(tx) = guard.as_ref()
                    {
                        let _ = tx.send((utt_id, text, Instant::now()));
                    }
                }
                None => utt_log(utt_id, whisper_start, "whisper skip"),
            }
        }
    });
}

/// Start STT: stand up the callback pump (owns `context`, mirrors bridge.rs)
/// and the pipe-client thread. A later start rearms the callback for a new
/// mission without starting a second client.
pub fn start(context: Context) -> String {
    let (tx, rx) = mpsc::channel::<(u32, String, Instant)>();
    if let Ok(mut guard) = CALLBACK_TX.lock() {
        *guard = Some(tx);
    }
    spawn_callback_pump(context, rx);

    if STARTED.swap(true, Ordering::SeqCst) {
        tlog("rearmed");
        return "rearmed".to_string();
    }

    let (ttx, trx) = mpsc::channel::<(StartInfo, Vec<i16>, u32, Instant)>();
    if let Ok(mut guard) = TRANSCRIBE_TX.lock() {
        *guard = Some(ttx);
    }
    spawn_transcribe_worker(trx);
    thread::spawn(|| pipe::run_pipe_client());
    tlog("started");
    "ok".to_string()
}

/// Best-effort stop. The pipe client is process-lived (like the audio thread);
/// we only drop the callback sender so the pump can wind down. A subsequent
/// `start` rearms the callback without starting a second client.
pub fn stop() -> String {
    if let Ok(mut guard) = CALLBACK_TX.lock() {
        *guard = None;
    }
    tlog("stopped");
    "stopped".to_string()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn sqf_escape_doubles_quotes() {
        assert_eq!(sqf_escape(r#"he said "hi""#), r#"he said ""hi"""#);
        assert_eq!(sqf_escape("plain"), "plain");
    }

    #[test]
    fn hint_keeps_names_and_drops_junk() {
        assert_eq!(set_hint("Tomas  Pavel\0,?".into()), "Tomas Pavel");
        assert_eq!(hint(), "Tomas Pavel");
        assert_eq!(set_hint("".into()), "");
    }
}
