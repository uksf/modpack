use std::sync::mpsc::{self, Sender};
use std::sync::Mutex;
use std::thread;
use std::time::Duration;

use crate::config;

#[derive(Debug)]
enum Message {
    Log { run_id: String, line: String },
    Finish { run_id: String, payload: String },
}

struct State {
    run_id: String,
    buffer: String,
}

static STATE: Mutex<Option<State>> = Mutex::new(None);
static CHANNEL: Mutex<Option<Sender<Message>>> = Mutex::new(None);

fn ensure_worker_started() {
    let mut channel = CHANNEL.lock().unwrap();
    if channel.is_some() {
        return;
    }
    let (tx, rx) = mpsc::channel::<Message>();
    *channel = Some(tx);

    thread::spawn(move || {
        for msg in rx {
            match msg {
                Message::Log { run_id, line } => {
                    let url = format!("{}/dev-run/internal/{}/log", config::api_base_url(), run_id);
                    let body = format!(r#"{{"line":{}}}"#, json_escape(&line));
                    let _ = ureq::post(&url)
                        .timeout(Duration::from_secs(5))
                        .set("Content-Type", "application/json")
                        .send_string(&body);
                }
                Message::Finish { run_id, payload } => {
                    let result_url = format!("{}/dev-run/internal/{}/result", config::api_base_url(), run_id);
                    let _ = ureq::post(&result_url)
                        .timeout(Duration::from_secs(30))
                        .set("Content-Type", "text/plain")
                        .send_string(&payload);
                    let finish_url = format!("{}/dev-run/internal/{}/finish", config::api_base_url(), run_id);
                    let _ = ureq::post(&finish_url)
                        .timeout(Duration::from_secs(5))
                        .set("Content-Type", "application/json")
                        .send_string("{}");
                    log::info!("dev_run: finish posted, exiting process");
                    std::process::exit(0);
                }
            }
        }
    });
}

fn json_escape(s: &str) -> String {
    let escaped: String = s
        .chars()
        .flat_map(|c| match c {
            '"' => "\\\"".chars().collect::<Vec<_>>(),
            '\\' => "\\\\".chars().collect(),
            '\n' => "\\n".chars().collect(),
            '\r' => "\\r".chars().collect(),
            '\t' => "\\t".chars().collect(),
            c if (c as u32) < 0x20 => format!("\\u{:04x}", c as u32).chars().collect(),
            c => vec![c],
        })
        .collect();
    format!("\"{escaped}\"")
}

pub fn open(run_id: String) -> String {
    let mut state = STATE.lock().unwrap();
    if state.is_some() {
        return "error: already open".to_string();
    }
    *state = Some(State {
        run_id,
        buffer: String::new(),
    });
    "ok".to_string()
}

pub fn chunk(run_id: String, chunk: String) -> String {
    let mut state = STATE.lock().unwrap();
    let Some(s) = state.as_mut() else {
        return "error: not open".to_string();
    };
    if s.run_id != run_id {
        return "error: runId mismatch".to_string();
    }
    s.buffer.push_str(&chunk);
    "ok".to_string()
}

pub fn log(run_id: String, line: String) -> String {
    if config::get_api_port() == 0 {
        return "error: extension not started".to_string();
    }
    ensure_worker_started();
    let channel = CHANNEL.lock().unwrap();
    if let Some(tx) = channel.as_ref() {
        let _ = tx.send(Message::Log { run_id, line });
    }
    "ok".to_string()
}

pub fn finish(run_id: String) -> String {
    if config::get_api_port() == 0 {
        return "error: extension not started".to_string();
    }
    ensure_worker_started();

    let payload = {
        let mut state = STATE.lock().unwrap();
        match state.take() {
            Some(s) if s.run_id == run_id => s.buffer,
            Some(s) => {
                *state = Some(s);
                return "error: runId mismatch".to_string();
            }
            None => return "error: not open".to_string(),
        }
    };

    let channel = CHANNEL.lock().unwrap();
    if let Some(tx) = channel.as_ref() {
        let _ = tx.send(Message::Finish { run_id, payload });
    }
    "ok".to_string()
}

#[cfg(test)]
mod tests {
    use super::*;

    fn reset_state() {
        let mut s = STATE.lock().unwrap();
        *s = None;
    }

    #[test]
    fn open_then_chunk_then_finish_round_trip() {
        reset_state();
        assert_eq!(open("R1".into()), "ok");
        assert_eq!(chunk("R1".into(), "hello".into()), "ok");
        assert_eq!(chunk("R2".into(), "x".into()), "error: runId mismatch");
    }

    #[test]
    fn double_open_rejected() {
        reset_state();
        assert_eq!(open("R1".into()), "ok");
        assert_eq!(open("R1".into()), "error: already open");
    }

    #[test]
    fn json_escape_handles_quotes_and_newlines() {
        assert_eq!(json_escape("hi\n\"world\""), "\"hi\\n\\\"world\\\"\"");
    }
}
