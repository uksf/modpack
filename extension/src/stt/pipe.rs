//! Windows named-pipe SERVER for `\\.\pipe\uksf_stt`. ACRE (sub-plan #3) is the
//! client. One connection carries many utterances; we parse frames, assemble
//! each utterance, transcribe at END, and hand the text to the callback pump.

use windows::Win32::Foundation::{CloseHandle, ERROR_PIPE_CONNECTED, HANDLE, WIN32_ERROR};
use windows::Win32::Storage::FileSystem::{
    ReadFile, PIPE_ACCESS_INBOUND,
};
use windows::Win32::System::Pipes::{
    ConnectNamedPipe, CreateNamedPipeW, DisconnectNamedPipe, PIPE_READMODE_BYTE, PIPE_TYPE_BYTE,
    PIPE_WAIT,
};

use super::frame::{Frame, FrameReader, StartInfo};
use super::{fire_transcript, transcribe};

const PIPE_NAME: &str = r"\\.\pipe\uksf_stt";
const IN_BUFFER: u32 = 1 << 16; // 64 KiB
const READ_CHUNK: usize = 1 << 14; // 16 KiB

fn wide(s: &str) -> Vec<u16> {
    s.encode_utf16().chain(std::iter::once(0)).collect()
}

/// Long-lived loop: create an instance, wait for a client, serve it, repeat.
pub fn run_pipe_server() {
    log::info!("stt: pipe server listening on {PIPE_NAME}");
    loop {
        let name = wide(PIPE_NAME);
        // CreateNamedPipeW returns HANDLE directly in windows 0.58 (not
        // Result<HANDLE>). Validity must be checked with is_invalid().
        let handle = unsafe {
            CreateNamedPipeW(
                windows::core::PCWSTR(name.as_ptr()),
                PIPE_ACCESS_INBOUND,
                PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
                1, // single instance — one local mic
                0,
                IN_BUFFER,
                0,
                None,
            )
        };
        if handle.is_invalid() {
            log::error!("stt: CreateNamedPipeW returned invalid handle");
            std::thread::sleep(std::time::Duration::from_millis(500));
            continue;
        }

        // Block until ACRE connects. ERROR_PIPE_CONNECTED = client beat us here.
        let connected = unsafe { ConnectNamedPipe(handle, None) };
        let ok = connected.is_ok() || connected.as_ref().is_err_and(|e| {
            WIN32_ERROR::from_error(e)
                .map(|w| w == ERROR_PIPE_CONNECTED)
                .unwrap_or(false)
        });
        if !ok {
            log::warn!("stt: ConnectNamedPipe failed: {connected:?}");
            unsafe {
                let _ = CloseHandle(handle);
            }
            continue;
        }

        serve_connection(handle);

        unsafe {
            let _ = DisconnectNamedPipe(handle);
            let _ = CloseHandle(handle);
        }
    }
}

/// Read+parse until the client disconnects (ReadFile yields 0 / errors).
fn serve_connection(handle: HANDLE) {
    let mut reader = FrameReader::new();
    let mut current: Option<(StartInfo, Vec<i16>)> = None;
    let mut chunk = vec![0u8; READ_CHUNK];

    loop {
        let mut read: u32 = 0;
        let ok = unsafe { ReadFile(handle, Some(chunk.as_mut_slice()), Some(&mut read), None) };
        if ok.is_err() || read == 0 {
            break; // client disconnected
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
                    // Malformed stream — resync by dropping this connection.
                    log::warn!("stt: frame error ({e}); dropping connection to resync");
                    return;
                }
            }
        }
    }
}
