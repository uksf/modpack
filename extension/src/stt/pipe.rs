//! Windows named-pipe CLIENT for `\\.\pipe\uksf_stt`. ACRE (TS plugin) is the
//! server. One connection carries many utterances; we parse frames, assemble
//! each utterance, transcribe at END, and hand the text to the callback pump.

use windows::Win32::Foundation::{CloseHandle, GENERIC_READ, HANDLE};
use windows::Win32::Storage::FileSystem::{
    CreateFileW, ReadFile, FILE_ATTRIBUTE_NORMAL, FILE_SHARE_NONE, OPEN_EXISTING,
};

use super::frame::{Frame, FrameReader, StartInfo};
use super::{fire_transcript, transcribe};

const PIPE_NAME: &str = r"\\.\pipe\uksf_stt";
const READ_CHUNK: usize = 1 << 14; // 16 KiB
const RETRY_MS: u64 = 500;

fn wide(s: &str) -> Vec<u16> {
    s.encode_utf16().chain(std::iter::once(0)).collect()
}

/// Long-lived loop: connect to ACRE, serve until drop, retry. Never blocks the game.
pub fn run_pipe_client() {
    log::info!("stt: pipe client targeting {PIPE_NAME}");
    loop {
        match connect() {
            Some(handle) => {
                log::info!("stt: connected to {PIPE_NAME}");
                serve_connection(handle);
                log::info!("stt: disconnected; retrying");
                unsafe {
                    let _ = CloseHandle(handle);
                }
            }
            None => {
                std::thread::sleep(std::time::Duration::from_millis(RETRY_MS));
            }
        }
    }
}

fn connect() -> Option<HANDLE> {
    let name = wide(PIPE_NAME);
    unsafe {
        CreateFileW(
            windows::core::PCWSTR(name.as_ptr()),
            GENERIC_READ.0,
            FILE_SHARE_NONE,
            None,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL,
            None,
        )
        .ok()
    }
}

/// Read+parse until the server disconnects (ReadFile yields 0 / errors).
fn serve_connection(handle: HANDLE) {
    let mut reader = FrameReader::new();
    let mut current: Option<(StartInfo, Vec<i16>)> = None;
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
                    current = Some((info, Vec::new()));
                }
                Some(Ok(Frame::Data(samples))) => {
                    if let Some((_, acc)) = current.as_mut() {
                        acc.extend_from_slice(&samples);
                    }
                }
                Some(Ok(Frame::End { utt_id })) => {
                    if let Some((info, acc)) = current.take() {
                        if let Some(text) = transcribe::transcribe_utterance(&info, &acc) {
                            log::info!("stt: utt {utt_id}: \"{text}\"");
                            fire_transcript(utt_id, &text);
                        }
                    }
                }
                Some(Err(e)) => {
                    log::warn!("stt: frame error ({e}); dropping connection to resync");
                    return;
                }
            }
        }
    }
}
