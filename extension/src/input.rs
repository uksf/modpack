use windows::Win32::UI::Input::KeyboardAndMouse::VK_RETURN;
use windows::Win32::UI::WindowsAndMessaging::{
    FindWindowW, PostMessageW, WM_KEYDOWN, WM_KEYUP,
};
use windows::Win32::Foundation::{WPARAM, LPARAM};
use windows::core::{w, PCWSTR};

const VK_RETURN_SCAN_CODE: isize = 0x1C;

pub fn press_enter() -> String {
    // Search by window title, not class name (class name varies)
    let hwnd = match unsafe { FindWindowW(PCWSTR::null(), w!("Arma 3")) } {
        Ok(h) if !h.is_invalid() => h,
        _ => {
            let msg = "press_enter: Arma 3 window not found";
            log::error!("{msg}");
            return msg.to_string();
        }
    };

    let vk = VK_RETURN.0 as usize;
    // lparam layout: repeat count (bits 0-15), scan code (bits 16-23),
    // extended (bit 24), context (bit 29), previous state (bit 30), transition (bit 31)
    let lparam_down: isize = 1 | (VK_RETURN_SCAN_CODE << 16);
    let lparam_up: isize = 1 | (VK_RETURN_SCAN_CODE << 16) | (1 << 30) | (1 << 31);

    let down_result = unsafe { PostMessageW(hwnd, WM_KEYDOWN, WPARAM(vk), LPARAM(lparam_down)) };
    let up_result = unsafe { PostMessageW(hwnd, WM_KEYUP, WPARAM(vk), LPARAM(lparam_up)) };

    if let Err(e) = down_result {
        let msg = format!("press_enter: WM_KEYDOWN failed: {e}");
        log::error!("{msg}");
        return msg;
    }
    if let Err(e) = up_result {
        let msg = format!("press_enter: WM_KEYUP failed: {e}");
        log::error!("{msg}");
        return msg;
    }

    log::info!("press_enter: posted WM_KEYDOWN/WM_KEYUP to Arma 3 window");
    "ok".to_string()
}
