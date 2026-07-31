//! Voice DSP: ACRE-parity occlusion low-pass. Structured as a single filter now;
//! the per-source chain is the seam for future voice effects (radio, etc.).
use std::f32::consts::PI;

const CUTOFF_FREQ: f64 = 15000.0;

/// ACRE's raw occlusion cutoff curve (`FilterOcclusion.cpp`): the same Hz value
/// ACRE feeds its Butterworth, before any Nyquist clamp. `vol` is the composed
/// direct-speech volume scalar (0..1).
pub fn cutoff_from_vol_raw(vol: f32) -> f32 {
    let v = (vol as f64).max(1e-6);
    (CUTOFF_FREQ * (v * 10.0).log10().powi(4)) as f32
}

/// Cutoff clamped to a usable range for sample rate `fs`: floored at 20 Hz,
/// ceilinged just under Nyquist (above which the filter is effectively open).
pub fn cutoff_from_vol(vol: f32, fs: u32) -> f32 {
    let nyq = 0.49 * fs as f32;
    cutoff_from_vol_raw(vol).clamp(20.0, nyq)
}

/// One RBJ biquad, Transposed Direct Form II (matches ACRE's TransposedDirectFormII).
#[derive(Clone, Copy)]
struct Biquad {
    b0: f32, b1: f32, b2: f32, a1: f32, a2: f32,
    z1: f32, z2: f32,
    q: f32,
}

impl Biquad {
    fn new(q: f32) -> Self {
        Self { b0: 1.0, b1: 0.0, b2: 0.0, a1: 0.0, a2: 0.0, z1: 0.0, z2: 0.0, q }
    }

    /// Recompute low-pass coefficients for cutoff `fc` at sample rate `fs`,
    /// preserving filter state (z1/z2) so retuning mid-stream doesn't click.
    fn set_lowpass(&mut self, fc: f32, fs: f32) {
        let w0 = 2.0 * PI * fc / fs;
        let (sin, cos) = (w0.sin(), w0.cos());
        let alpha = sin / (2.0 * self.q);
        let a0 = 1.0 + alpha;
        self.b0 = (1.0 - cos) / 2.0 / a0;
        self.b1 = (1.0 - cos) / a0;
        self.b2 = self.b0;
        self.a1 = (-2.0 * cos) / a0;
        self.a2 = (1.0 - alpha) / a0;
    }

    fn process(&mut self, x: f32) -> f32 {
        let y = self.b0 * x + self.z1;
        self.z1 = self.b1 * x - self.a1 * y + self.z2;
        self.z2 = self.b2 * x - self.a2 * y;
        y
    }
}

/// 4th-order Butterworth low-pass: two cascaded biquads with the Butterworth
/// section Q's. Cutoff retunable per chunk for time-varying occlusion.
pub struct LowPass4 {
    stages: [Biquad; 2],
    fs: f32,
}

impl LowPass4 {
    pub fn new(fs: f32) -> Self {
        let mut s = Self { stages: [Biquad::new(0.54119610), Biquad::new(1.30656296)], fs };
        s.set_cutoff(0.49 * fs); // start open
        s
    }

    pub fn set_cutoff(&mut self, fc: f32) {
        let fc = fc.clamp(20.0, 0.49 * self.fs);
        for st in self.stages.iter_mut() {
            st.set_lowpass(fc, self.fs);
        }
    }

    pub fn process(&mut self, x: f32) -> f32 {
        let s0 = self.stages[0].process(x);
        self.stages[1].process(s0)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn cutoff_raw_matches_acre_formula() {
        // vol=1 -> 15000*(log10(10))^4 = 15000
        assert!((cutoff_from_vol_raw(1.0) - 15000.0).abs() < 1.0);
        // vol=0.1 -> log10(1)=0 -> 0
        assert!(cutoff_from_vol_raw(0.1).abs() < 1e-6);
    }

    #[test]
    fn cutoff_clamped_to_nyquist_and_floor() {
        let fs = 24000;
        assert!((cutoff_from_vol(1.0, fs) - 0.49 * fs as f32).abs() < 1.0);
        assert!((cutoff_from_vol(0.1, fs) - 20.0).abs() < 1e-3);
    }

    #[test]
    fn lowpass_passes_dc() {
        let mut f = LowPass4::new(24000.0);
        f.set_cutoff(2000.0);
        let mut y = 0.0;
        for _ in 0..2000 { y = f.process(1.0); }
        assert!((y - 1.0).abs() < 0.05, "DC should pass, got {y}");
    }

    #[test]
    fn lowpass_attenuates_nyquist() {
        let mut f = LowPass4::new(24000.0);
        f.set_cutoff(500.0);
        let mut peak = 0.0f32;
        for i in 0..4000 {
            let x = if i % 2 == 0 { 1.0 } else { -1.0 };
            let y = f.process(x).abs();
            if i > 2000 { peak = peak.max(y); }
        }
        assert!(peak < 0.05, "Nyquist should be crushed at fc=500, peak {peak}");
    }

    #[test]
    fn lowpass_open_is_near_transparent() {
        let mut f = LowPass4::new(24000.0);
        f.set_cutoff(cutoff_from_vol(1.0, 24000));
        let mut maxerr = 0.0f32;
        for i in 0..2000 {
            let x = ((i as f32) * 0.3).sin();
            let y = f.process(x);
            maxerr = maxerr.max((y - x).abs());
        }
        assert!(maxerr < 0.1, "open filter should pass low tones, err {maxerr}");
    }

    #[test]
    fn filter_is_numerically_stable() {
        let mut f = LowPass4::new(48000.0);
        f.set_cutoff(20.0);
        for i in 0..10000 {
            let x = if i % 3 == 0 { 1.0 } else { -1.0 };
            let y = f.process(x);
            assert!(y.is_finite(), "filter blew up at {i}: {y}");
        }
    }
}
