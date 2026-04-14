use std::cell::Cell;
use windows::Win32::Foundation::{BOOL, HWND, LPARAM, WPARAM};
use windows::Win32::System::Threading::GetCurrentProcessId;
use windows::Win32::UI::Input::KeyboardAndMouse::VK_SPACE;
use windows::Win32::UI::WindowsAndMessaging::{
    EnumWindows, GetWindowThreadProcessId, IsWindowVisible, PostMessageW, WM_KEYDOWN, WM_KEYUP,
};

const VK_SPACE_SCAN_CODE: isize = 0x39;

thread_local! {
    static FOUND_HWND: Cell<Option<HWND>> = Cell::new(None);
}

extern "system" fn enum_windows_proc(hwnd: HWND, lparam: LPARAM) -> BOOL {
    let target_pid = lparam.0 as u32;
    let mut window_pid: u32 = 0;
    unsafe { GetWindowThreadProcessId(hwnd, Some(&mut window_pid)) };

    if window_pid == target_pid && unsafe { IsWindowVisible(hwnd) }.as_bool() {
        FOUND_HWND.with(|h| h.set(Some(hwnd)));
        return BOOL(0); // stop enumeration
    }

    BOOL(1) // continue
}

fn find_arma_window() -> Option<HWND> {
    let pid = unsafe { GetCurrentProcessId() };
    FOUND_HWND.with(|h| h.set(None));
    let _ = unsafe { EnumWindows(Some(enum_windows_proc), LPARAM(pid as isize)) };
    FOUND_HWND.with(|h| h.get())
}

pub fn press_space() -> String {
    let hwnd = match find_arma_window() {
        Some(h) => h,
        None => {
            let msg = "press_space: no visible window found for current process";
            log::error!("{msg}");
            return msg.to_string();
        }
    };

    let vk = VK_SPACE.0 as usize;
    let lparam_down: isize = 1 | (VK_SPACE_SCAN_CODE << 16);
    let lparam_up: isize = 1 | (VK_SPACE_SCAN_CODE << 16) | (1 << 30) | (1 << 31);

    let down_result = unsafe { PostMessageW(hwnd, WM_KEYDOWN, WPARAM(vk), LPARAM(lparam_down)) };
    let up_result = unsafe { PostMessageW(hwnd, WM_KEYUP, WPARAM(vk), LPARAM(lparam_up)) };

    if let Err(e) = down_result {
        let msg = format!("press_space: WM_KEYDOWN failed: {e}");
        log::error!("{msg}");
        return msg;
    }
    if let Err(e) = up_result {
        let msg = format!("press_space: WM_KEYUP failed: {e}");
        log::error!("{msg}");
        return msg;
    }

    log::info!("press_space: posted to hwnd {:?}", hwnd.0);
    "ok".to_string()
}
