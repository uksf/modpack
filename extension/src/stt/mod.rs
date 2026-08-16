pub mod dsp;
pub mod frame;
pub mod pipe;
pub mod transcribe;

use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::mpsc::{self, Receiver, Sender};
use std::sync::Mutex;
use std::thread;

use arma_rs::Context;

static STARTED: AtomicBool = AtomicBool::new(false);
static CALLBACK_TX: Mutex<Option<Sender<(u32, String)>>> = Mutex::new(None);
static HINT: Mutex<String> = Mutex::new(String::new());

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

/// Queue a transcript for delivery to SQF. Called from the pipe thread.
pub fn fire_transcript(utt_id: u32, text: &str) {
    if let Ok(guard) = CALLBACK_TX.lock()
        && let Some(tx) = guard.as_ref()
    {
        let _ = tx.send((utt_id, text.to_string()));
    }
}

fn spawn_callback_pump(context: Context, rx: Receiver<(u32, String)>) {
    thread::spawn(move || {
        log::info!("stt: callback pump started");
        for (utt_id, text) in rx {
            let data = format!("[{},\"{}\"]", utt_id, sqf_escape(&text));
            let _ = context.callback_data("uksf", "sttTranscript", data);
        }
        log::info!("stt: callback pump exiting");
    });
}

/// Start STT: stand up the callback pump (owns `context`, mirrors bridge.rs)
/// and the pipe-server thread. A later start rearms the callback for a new
/// mission without restarting the process-lived pipe server.
pub fn start(context: Context) -> String {
    let (tx, rx) = mpsc::channel::<(u32, String)>();
    if let Ok(mut guard) = CALLBACK_TX.lock() {
        *guard = Some(tx);
    }
    spawn_callback_pump(context, rx);

    if STARTED.swap(true, Ordering::SeqCst) {
        log::info!("stt: callback rearmed");
        return "rearmed".to_string();
    }

    thread::spawn(|| pipe::run_pipe_server());
    log::info!("stt: started");
    "ok".to_string()
}

/// Best-effort stop. The pipe server is process-lived (like the audio thread);
/// we only drop the callback sender so the pump can wind down. A subsequent
/// `start` rearms the callback without starting a second pipe server.
pub fn stop() -> String {
    if let Ok(mut guard) = CALLBACK_TX.lock() {
        *guard = None;
    }
    log::info!("stt: stop requested (callback pump released)");
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
