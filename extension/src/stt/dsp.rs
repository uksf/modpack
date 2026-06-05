//! Pure audio transforms: interleaved multi-channel i16 @ 48 kHz → mono f32 @
//! 16 kHz, which is what whisper expects. 48000/16000 is exactly 3:1, so the
//! resample is a 3-sample average (acts as a crude low-pass — fine for speech).

/// Average interleaved frames down to mono. `channels == 1` is a passthrough.
pub fn downmix_to_mono(samples: &[i16], channels: u32) -> Vec<i16> {
    let channels = channels.max(1) as usize;
    if channels == 1 {
        return samples.to_vec();
    }
    samples
        .chunks_exact(channels)
        .map(|frame| {
            let sum: i32 = frame.iter().map(|&s| s as i32).sum();
            (sum / channels as i32) as i16
        })
        .collect()
}

/// 48 kHz → 16 kHz by averaging non-overlapping 3-sample groups. A trailing
/// partial group (< 3 samples) is dropped — negligible for speech.
pub fn decimate_48k_to_16k(mono: &[i16]) -> Vec<i16> {
    mono.chunks_exact(3)
        .map(|g| ((g[0] as i32 + g[1] as i32 + g[2] as i32) / 3) as i16)
        .collect()
}

/// Normalise i16 PCM to f32 in [-1.0, 1.0).
pub fn i16_to_f32(samples: &[i16]) -> Vec<f32> {
    samples.iter().map(|&s| s as f32 / 32768.0).collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn downmix_stereo_averages_pairs() {
        // L/R interleaved: (10,20) -> 15 ; (-4,-6) -> -5
        assert_eq!(downmix_to_mono(&[10, 20, -4, -6], 2), vec![15, -5]);
    }

    #[test]
    fn downmix_mono_is_passthrough() {
        assert_eq!(downmix_to_mono(&[1, 2, 3], 1), vec![1, 2, 3]);
    }

    #[test]
    fn decimate_produces_third_length_average() {
        // 6 samples -> 2 outputs: avg(3,3,3)=3, avg(9,9,9)=9
        let input: Vec<i16> = vec![3, 3, 3, 9, 9, 9];
        assert_eq!(decimate_48k_to_16k(&input), vec![3, 9]);
    }

    #[test]
    fn decimate_drops_trailing_partial_group() {
        assert_eq!(decimate_48k_to_16k(&[3, 3, 3, 5]), vec![3]);
    }

    #[test]
    fn i16_to_f32_normalises_range() {
        let out = i16_to_f32(&[0, 16384, -32768]);
        assert!((out[0] - 0.0).abs() < 1e-6);
        assert!((out[1] - 0.5).abs() < 1e-6);
        assert!((out[2] - (-1.0)).abs() < 1e-6);
    }
}
