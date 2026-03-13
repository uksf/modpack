use arma_rs::{arma, Extension};
use simplelog::{LevelFilter, WriteLogger};
use std::fs::{self, File};
use std::path::PathBuf;

mod bridge;
mod commands;
mod config;
mod listener;
mod loader;
mod sender;

fn logs_dir() -> PathBuf {
    std::env::current_exe()
        .ok()
        .and_then(|p| p.parent().map(|d| d.to_path_buf()))
        .unwrap_or_default()
        .join("logs")
}

fn prune_old_logs(dir: &std::path::Path, keep: usize) {
    let Ok(entries) = fs::read_dir(dir) else {
        return;
    };
    let mut logs: Vec<_> = entries
        .filter_map(Result::ok)
        .filter(|e| {
            e.path()
                .file_name()
                .is_some_and(|n| n.to_string_lossy().starts_with("uksf_") && n.to_string_lossy().ends_with(".log"))
        })
        .collect();
    logs.sort_by_key(|e| std::cmp::Reverse(e.path()));
    for old in logs.into_iter().skip(keep) {
        let _ = fs::remove_file(old.path());
    }
}

fn init_logger() {
    let dir = logs_dir();
    let _ = fs::create_dir_all(&dir);
    prune_old_logs(&dir, 9);

    let timestamp = chrono::Local::now().format("%Y-%m-%d_%H-%M-%S");
    let log_path = dir.join(format!("uksf_{timestamp}.log"));
    if let Ok(file) = File::create(&log_path) {
        let _ = WriteLogger::init(LevelFilter::Info, simplelog::Config::default(), file);
    }
}

#[arma]
fn init() -> Extension {
    init_logger();

    Extension::build()
        .version(env!("CARGO_PKG_VERSION").to_string())
        .allow_no_args()
        .command("start", commands::start)
        .command("stop", commands::stop)
        .command("flush", commands::flush)
        .command("event", commands::event)
        .command("load", commands::load)
        .finish()
}
