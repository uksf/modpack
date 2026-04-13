use windows::Win32::UI::Input::KeyboardAndMouse::{
    SendInput, INPUT, INPUT_0, INPUT_KEYBOARD, KEYBDINPUT, KEYEVENTF_KEYUP, VK_RETURN,
};

pub fn press_enter() -> String {
    let down = INPUT {
        r#type: INPUT_KEYBOARD,
        Anonymous: INPUT_0 {
            ki: KEYBDINPUT {
                wVk: VK_RETURN,
                ..Default::default()
            },
        },
    };
    let up = INPUT {
        r#type: INPUT_KEYBOARD,
        Anonymous: INPUT_0 {
            ki: KEYBDINPUT {
                wVk: VK_RETURN,
                dwFlags: KEYEVENTF_KEYUP,
                ..Default::default()
            },
        },
    };

    let inputs = [down, up];
    let sent = unsafe { SendInput(&inputs, std::mem::size_of::<INPUT>() as i32) };

    if sent == 2 {
        log::info!("press_enter: sent 2 input events");
        "ok".to_string()
    } else {
        let msg = format!("press_enter: only sent {sent}/2 events");
        log::error!("{msg}");
        msg
    }
}
