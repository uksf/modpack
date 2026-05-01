use std::fs::{self, File};
use std::io::{BufWriter, Write};
use std::path::{Path, PathBuf};
use std::sync::{Mutex, OnceLock};

static WRITER: Mutex<Option<BufWriter<File>>> = Mutex::new(None);
static EXPORT_DIR: OnceLock<PathBuf> = OnceLock::new();

fn export_dir() -> &'static PathBuf {
    EXPORT_DIR.get_or_init(|| {
        std::env::current_exe()
            .ok()
            .and_then(|p| p.parent().map(|d| d.to_path_buf()))
            .unwrap_or_default()
            .join("uksf_config_export")
    })
}

fn safe_filename(name: &str) -> Option<&str> {
    if name.is_empty() || name.contains('/') || name.contains('\\') || name == ".." || name == "." {
        return None;
    }
    if Path::new(name).file_name().and_then(|s| s.to_str()) != Some(name) {
        return None;
    }
    Some(name)
}

pub fn open(filename: String) -> String {
    let Some(name) = safe_filename(&filename) else {
        log::warn!("configExport open rejected unsafe filename: {filename}");
        return "error: invalid filename".to_string();
    };

    let dir = export_dir();
    if let Err(error) = fs::create_dir_all(dir) {
        log::error!("configExport failed to create dir {}: {error}", dir.display());
        return format!("error: create dir failed: {error}");
    }

    let path = dir.join(name);
    let file = match File::create(&path) {
        Ok(file) => file,
        Err(error) => {
            log::error!("configExport open failed for {}: {error}", path.display());
            return format!("error: open failed: {error}");
        }
    };

    let mut guard = match WRITER.lock() {
        Ok(guard) => guard,
        Err(poisoned) => poisoned.into_inner(),
    };
    *guard = Some(BufWriter::new(file));
    log::info!("configExport opened {}", path.display());
    path.display().to_string()
}

pub fn write(chunk: String) -> String {
    let mut guard = match WRITER.lock() {
        Ok(guard) => guard,
        Err(poisoned) => poisoned.into_inner(),
    };
    let Some(writer) = guard.as_mut() else {
        return "error: not open".to_string();
    };
    if let Err(error) = writer.write_all(chunk.as_bytes()) {
        log::error!("configExport write failed: {error}");
        return format!("error: write failed: {error}");
    }
    "ok".to_string()
}

pub fn close() -> String {
    let mut guard = match WRITER.lock() {
        Ok(guard) => guard,
        Err(poisoned) => poisoned.into_inner(),
    };
    let Some(mut writer) = guard.take() else {
        return "error: not open".to_string();
    };
    if let Err(error) = writer.flush() {
        log::error!("configExport flush failed: {error}");
        return format!("error: flush failed: {error}");
    }
    log::info!("configExport closed");
    "ok".to_string()
}

pub fn finish() -> String {
    let _ = close();
    std::thread::sleep(std::time::Duration::from_millis(250));
    std::process::exit(0);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn safe_filename_accepts_plain() {
        assert_eq!(safe_filename("config_220_uksf-5-23-7.cpp"), Some("config_220_uksf-5-23-7.cpp"));
    }

    #[test]
    fn safe_filename_rejects_traversal() {
        assert_eq!(safe_filename("../escape.cpp"), None);
        assert_eq!(safe_filename("..\\escape.cpp"), None);
        assert_eq!(safe_filename(".."), None);
        assert_eq!(safe_filename("."), None);
    }

    #[test]
    fn safe_filename_rejects_separators() {
        assert_eq!(safe_filename("sub/file.cpp"), None);
        assert_eq!(safe_filename("sub\\file.cpp"), None);
    }

    #[test]
    fn safe_filename_rejects_empty() {
        assert_eq!(safe_filename(""), None);
    }

    #[test]
    fn write_without_open_errors() {
        // Ensure no writer is open from a prior test
        let _ = close();
        assert_eq!(write("hello".to_string()), "error: not open");
    }

    #[test]
    fn close_without_open_errors() {
        let _ = close();
        assert_eq!(close(), "error: not open");
    }
}
