pub mod dsp;
pub mod frame;
pub mod pipe;
pub mod transcribe;

use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::mpsc::{self, Sender};
use std::sync::Mutex;
use std::thread;

use arma_rs::Context;

static STARTED: AtomicBool = AtomicBool::new(false);
static CALLBACK_TX: Mutex<Option<Sender<(u32, String)>>> = Mutex::new(None);

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

/// Start STT: stand up the callback pump (owns `context`, mirrors bridge.rs)
/// and the pipe-server thread. Idempotent — a second call is a no-op.
pub fn start(context: Context) -> String {
    if STARTED.swap(true, Ordering::SeqCst) {
        return "already running".to_string();
    }

    let (tx, rx) = mpsc::channel::<(u32, String)>();
    if let Ok(mut guard) = CALLBACK_TX.lock() {
        *guard = Some(tx);
    }

    // Callback pump: the one thread that owns `context`.
    thread::spawn(move || {
        log::info!("stt: callback pump started");
        for (utt_id, text) in rx {
            let data = format!("[{},\"{}\"]", utt_id, sqf_escape(&text));
            let _ = context.callback_data("uksf", "sttTranscript", data);
        }
        log::info!("stt: callback pump exiting");
    });

    // Pipe server: long-lived; serves the local mic for the whole process.
    thread::spawn(|| pipe::run_pipe_server());

    log::info!("stt: started");
    "ok".to_string()
}

/// Best-effort stop. The pipe server is process-lived (like the audio thread);
/// we only drop the callback sender so the pump can wind down. A subsequent
/// `start` is still gated by STARTED, so this does not re-arm.
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
}
