//! Windows named-pipe CLIENT for `\\.\pipe\uksf_stt`. ACRE (TS plugin) is the
//! server. One connection carries many utterances; we parse frames, assemble
//! each utterance, and hand PCM to the transcribe worker. This thread never
//! loads whisper — that work raced OpenAL filler playback and AVed the game.

use std::time::{Duration, Instant};

use windows::Win32::Foundation::{CloseHandle, GetLastError, GENERIC_READ, HANDLE};
use windows::Win32::Storage::FileSystem::{
    CreateFileW, ReadFile, FILE_ATTRIBUTE_NORMAL, FILE_SHARE_READ, FILE_SHARE_WRITE, OPEN_EXISTING,
};
use windows::Win32::System::Pipes::WaitNamedPipeW;

use super::frame::{Frame, FrameReader};
use super::{enqueue_utterance_at, tlog};

const PIPE_NAME: &str = r"\\.\pipe\uksf_stt";
const READ_CHUNK: usize = 1 << 14;
const RETRY_MS: u64 = 500;
const WAIT_PIPE_MS: u32 = 1000;
/// Raw interleaved i16 cap (~10 s of 48 kHz stereo). Prevents a stuck PTT
/// from growing without bound on this thread.
const MAX_SAMPLES: usize = 48000 * 2 * 10;
const FAIL_LOG_EVERY: u32 = 10;

fn wide(s: &str) -> Vec<u16> {
    s.encode_utf16().chain(std::iter::once(0)).collect()
}

/// Long-lived loop: connect to ACRE, read until drop, retry.
pub fn run_pipe_client() {
    tlog("pipe client started");
    let mut fails: u32 = 0;
    loop {
        match connect() {
            Some(handle) => {
                tlog("connected");
                fails = 0;
                serve_connection(handle);
                tlog("disconnected");
                unsafe {
                    let _ = CloseHandle(handle);
                }
            }
            None => {
                fails = fails.saturating_add(1);
                if fails == 1 || fails.is_multiple_of(FAIL_LOG_EVERY) {
                    let err = unsafe { GetLastError().0 };
                    tlog(&format!("connect miss x{fails} err={err}"));
                }
                std::thread::sleep(Duration::from_millis(RETRY_MS));
            }
        }
    }
}

fn connect() -> Option<HANDLE> {
    let name = wide(PIPE_NAME);
    unsafe {
        let _ = WaitNamedPipeW(windows::core::PCWSTR(name.as_ptr()), WAIT_PIPE_MS);
        CreateFileW(
            windows::core::PCWSTR(name.as_ptr()),
            GENERIC_READ.0,
            FILE_SHARE_READ | FILE_SHARE_WRITE,
            None,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL,
            None,
        )
        .ok()
    }
}

fn serve_connection(handle: HANDLE) {
    let mut reader = FrameReader::new();
    let mut current: Option<(super::frame::StartInfo, Vec<i16>, Instant)> = None;
    let mut chunk = vec![0u8; READ_CHUNK];

    loop {
        let mut read: u32 = 0;
        let ok = unsafe { ReadFile(handle, Some(chunk.as_mut_slice()), Some(&mut read), None) };
        if ok.is_err() || read == 0 {
            break;
        }
        reader.push(&chunk[..read as usize]);

        loop {
            match reader.next_frame() {
                None => break,
                Some(Ok(Frame::Start(info))) => {
                    log::info!(
                        "stt: utt={} start rate={} ch={}",
                        info.utt_id,
                        info.sample_rate,
                        info.channels
                    );
                    current = Some((info, Vec::new(), Instant::now()));
                }
                Some(Ok(Frame::Data(samples))) => {
                    if let Some((_, acc, _)) = current.as_mut() {
                        if acc.len() + samples.len() > MAX_SAMPLES {
                            tlog("data overflow; dropping utterance");
                            current = None;
                        } else {
                            acc.extend_from_slice(&samples);
                        }
                    }
                }
                Some(Ok(Frame::End { utt_id })) => {
                    if let Some((info, acc, started)) = current.take() {
                        log::info!(
                            "stt: utt={utt_id} +{}ms end samples={}",
                            started.elapsed().as_millis(),
                            acc.len()
                        );
                        enqueue_utterance_at(info, acc, utt_id, Instant::now());
                    }
                }
                Some(Err(e)) => {
                    tlog(&format!("frame error ({e}); dropping connection"));
                    return;
                }
            }
        }
    }
}
