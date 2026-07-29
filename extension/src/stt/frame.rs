//! Byte-accurate parser for the STT named-pipe wire format produced by ACRE
//! (sub-plan #3). Frames are little-endian `[u32 type][u32 len][payload]`.

#[derive(Debug, Clone, PartialEq)]
pub struct StartInfo {
    pub sample_rate: u32,
    pub channels: u32,
    pub utt_id: u32,
}

#[derive(Debug, Clone, PartialEq)]
pub enum Frame {
    Start(StartInfo),
    Data(Vec<i16>),
    End { utt_id: u32 },
}

/// Accumulates raw bytes and yields one complete `Frame` at a time.
pub struct FrameReader {
    buf: Vec<u8>,
}

const TYPE_START: u32 = 1;
const TYPE_DATA: u32 = 2;
const TYPE_END: u32 = 3;
const HEADER_LEN: usize = 8;

impl FrameReader {
    pub fn new() -> Self {
        Self { buf: Vec::new() }
    }

    pub fn push(&mut self, bytes: &[u8]) {
        self.buf.extend_from_slice(bytes);
    }

    /// Returns `Some(Ok(frame))` when a whole frame is buffered, `Some(Err(_))`
    /// on a malformed/unknown frame, or `None` when more bytes are needed.
    pub fn next_frame(&mut self) -> Option<Result<Frame, String>> {
        if self.buf.len() < HEADER_LEN {
            return None;
        }
        let ftype = u32::from_le_bytes(self.buf[0..4].try_into().unwrap());
        let len = u32::from_le_bytes(self.buf[4..8].try_into().unwrap()) as usize;
        if self.buf.len() < HEADER_LEN + len {
            return None;
        }
        let payload = self.buf[HEADER_LEN..HEADER_LEN + len].to_vec();
        self.buf.drain(0..HEADER_LEN + len);

        let frame = match ftype {
            TYPE_START => {
                if len != 12 {
                    return Some(Err(format!("START payload len {len} != 12")));
                }
                Some(Ok(Frame::Start(StartInfo {
                    sample_rate: u32::from_le_bytes(payload[0..4].try_into().unwrap()),
                    channels: u32::from_le_bytes(payload[4..8].try_into().unwrap()),
                    utt_id: u32::from_le_bytes(payload[8..12].try_into().unwrap()),
                })))
            }
            TYPE_DATA => {
                if len % 2 != 0 {
                    return Some(Err(format!("DATA payload len {len} not even")));
                }
                let samples = payload
                    .chunks_exact(2)
                    .map(|b| i16::from_le_bytes([b[0], b[1]]))
                    .collect();
                Some(Ok(Frame::Data(samples)))
            }
            TYPE_END => {
                if len != 4 {
                    return Some(Err(format!("END payload len {len} != 4")));
                }
                Some(Ok(Frame::End {
                    utt_id: u32::from_le_bytes(payload[0..4].try_into().unwrap()),
                }))
            }
            other => Some(Err(format!("unknown frame type {other}"))),
        };
        frame
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn frame_bytes(ftype: u32, payload: &[u8]) -> Vec<u8> {
        let mut v = Vec::new();
        v.extend_from_slice(&ftype.to_le_bytes());
        v.extend_from_slice(&(payload.len() as u32).to_le_bytes());
        v.extend_from_slice(payload);
        v
    }

    fn start_payload(rate: u32, ch: u32, utt: u32) -> Vec<u8> {
        let mut p = Vec::new();
        p.extend_from_slice(&rate.to_le_bytes());
        p.extend_from_slice(&ch.to_le_bytes());
        p.extend_from_slice(&utt.to_le_bytes());
        p
    }

    #[test]
    fn parses_start_data_end_in_order() {
        let mut r = FrameReader::new();
        r.push(&frame_bytes(1, &start_payload(48000, 1, 7)));
        r.push(&frame_bytes(2, &[0x01, 0x00, 0xFF, 0xFF])); // i16: 1, -1
        r.push(&frame_bytes(3, &7u32.to_le_bytes()));

        assert_eq!(
            r.next_frame().unwrap().unwrap(),
            Frame::Start(StartInfo { sample_rate: 48000, channels: 1, utt_id: 7 })
        );
        assert_eq!(r.next_frame().unwrap().unwrap(), Frame::Data(vec![1, -1]));
        assert_eq!(r.next_frame().unwrap().unwrap(), Frame::End { utt_id: 7 });
        assert!(r.next_frame().is_none());
    }

    #[test]
    fn handles_bytes_split_across_pushes() {
        let whole = frame_bytes(1, &start_payload(48000, 2, 3));
        let mut r = FrameReader::new();
        r.push(&whole[0..3]); // partial header
        assert!(r.next_frame().is_none());
        r.push(&whole[3..10]); // rest of header + partial payload
        assert!(r.next_frame().is_none());
        r.push(&whole[10..]); // remainder
        assert_eq!(
            r.next_frame().unwrap().unwrap(),
            Frame::Start(StartInfo { sample_rate: 48000, channels: 2, utt_id: 3 })
        );
    }

    #[test]
    fn parses_multiple_frames_from_one_push() {
        let mut blob = frame_bytes(2, &[0x10, 0x00]); // i16: 16
        blob.extend(frame_bytes(3, &9u32.to_le_bytes()));
        let mut r = FrameReader::new();
        r.push(&blob);
        assert_eq!(r.next_frame().unwrap().unwrap(), Frame::Data(vec![16]));
        assert_eq!(r.next_frame().unwrap().unwrap(), Frame::End { utt_id: 9 });
    }

    #[test]
    fn unknown_type_is_error() {
        let mut r = FrameReader::new();
        r.push(&frame_bytes(99, &[]));
        assert!(r.next_frame().unwrap().is_err());
    }

    #[test]
    fn odd_data_payload_is_error() {
        let mut r = FrameReader::new();
        r.push(&frame_bytes(2, &[0x00, 0x00, 0x00])); // 3 bytes
        assert!(r.next_frame().unwrap().is_err());
    }
}
