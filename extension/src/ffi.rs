use std::ffi::{c_char, c_int, CStr};
use std::sync::Mutex;

use crate::bridge;

/// Callback function type that Arma provides for extensionCallback
type CallbackFn = unsafe extern "C" fn(
    name: *const c_char,
    function: *const c_char,
    data: *const c_char,
) -> c_int;

pub static CALLBACK: Mutex<Option<CallbackFn>> = Mutex::new(None);

/// Called by Arma to register the callback function
#[unsafe(no_mangle)]
pub unsafe extern "C" fn RVExtensionRegisterCallback(callback: CallbackFn) {
    if let Ok(mut cb) = CALLBACK.lock() {
        *cb = Some(callback);
    }
}

/// Called by Arma to get the extension version
#[unsafe(no_mangle)]
pub unsafe extern "C" fn RVExtensionVersion(output: *mut c_char, output_size: c_int) {
    let version = concat!(env!("CARGO_PKG_VERSION"), "\0");
    let bytes = version.as_bytes();
    let len = bytes.len().min(output_size as usize);
    unsafe {
        std::ptr::copy_nonoverlapping(bytes.as_ptr(), output as *mut u8, len);
    }
}

/// Called by Arma when SQF calls "uksf" callExtension "command"
#[unsafe(no_mangle)]
pub unsafe extern "C" fn RVExtension(
    output: *mut c_char,
    output_size: c_int,
    function: *const c_char,
) {
    let command = unsafe { CStr::from_ptr(function) }
        .to_str()
        .unwrap_or("");

    let result = bridge::handle_command(command);

    let bytes = result.as_bytes();
    let max_len = (output_size as usize).saturating_sub(1);
    let len = bytes.len().min(max_len);
    unsafe {
        std::ptr::copy_nonoverlapping(bytes.as_ptr(), output as *mut u8, len);
        *output.add(len) = 0;
    }
}

/// Fire extensionCallback back to SQF
pub fn fire_callback(function: &str, data: &str) {
    let Ok(cb_guard) = CALLBACK.lock() else { return };
    let Some(callback) = *cb_guard else { return };

    let name = std::ffi::CString::new("uksf").unwrap();
    let func = std::ffi::CString::new(function).unwrap();
    let data = std::ffi::CString::new(data).unwrap();

    unsafe {
        callback(name.as_ptr(), func.as_ptr(), data.as_ptr());
    }
}
