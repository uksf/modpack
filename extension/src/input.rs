use std::cell::Cell;
use windows::Win32::Foundation::{BOOL, HWND, LPARAM};
use windows::Win32::System::Threading::GetCurrentProcessId;
use windows::Win32::UI::Input::KeyboardAndMouse::{
    SendInput, INPUT, INPUT_0, INPUT_KEYBOARD, KEYBDINPUT, KEYEVENTF_KEYUP, KEYEVENTF_SCANCODE,
    VK_SPACE,
};
use windows::Win32::UI::WindowsAndMessaging::{
    EnumWindows, GetForegroundWindow, GetWindowThreadProcessId, IsWindowVisible,
};

const VK_SPACE_SCAN_CODE: u16 = 0x39;

thread_local! {
    static FOUND_HWND: Cell<Option<HWND>> = Cell::new(None);
}

extern "system" fn enum_windows_proc(hwnd: HWND, lparam: LPARAM) -> BOOL {
    let target_pid = lparam.0 as u32;
    let mut window_pid: u32 = 0;
    unsafe { GetWindowThreadProcessId(hwnd, Some(&mut window_pid)) };

    if window_pid == target_pid && unsafe { IsWindowVisible(hwnd) }.as_bool() {
        FOUND_HWND.with(|h| h.set(Some(hwnd)));
        return BOOL(0);
    }

    BOOL(1)
}

fn find_arma_window() -> Option<HWND> {
    let pid = unsafe { GetCurrentProcessId() };
    FOUND_HWND.with(|h| h.set(None));
    let _ = unsafe { EnumWindows(Some(enum_windows_proc), LPARAM(pid as isize)) };
    FOUND_HWND.with(|h| h.get())
}

fn is_arma_foreground() -> bool {
    let Some(arma_hwnd) = find_arma_window() else {
        return false;
    };
    let foreground = unsafe { GetForegroundWindow() };
    foreground == arma_hwnd
}

pub fn press_space() -> String {
    if !is_arma_foreground() {
        let msg = "press_space: Arma not foreground, skipping";
        log::info!("{msg}");
        return "skipped".to_string();
    }

    let down = INPUT {
        r#type: INPUT_KEYBOARD,
        Anonymous: INPUT_0 {
            ki: KEYBDINPUT {
                wVk: VK_SPACE,
                wScan: VK_SPACE_SCAN_CODE,
                dwFlags: KEYEVENTF_SCANCODE,
                ..Default::default()
            },
        },
    };
    let up = INPUT {
        r#type: INPUT_KEYBOARD,
        Anonymous: INPUT_0 {
            ki: KEYBDINPUT {
                wVk: VK_SPACE,
                wScan: VK_SPACE_SCAN_CODE,
                dwFlags: KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP,
                ..Default::default()
            },
        },
    };

    let inputs = [down, up];
    let sent = unsafe { SendInput(&inputs, std::mem::size_of::<INPUT>() as i32) };

    if sent == 2 {
        log::info!("press_space: sent Space via SendInput");
        "ok".to_string()
    } else {
        let msg = format!("press_space: only sent {sent}/2 events");
        log::error!("{msg}");
        msg
    }
}
