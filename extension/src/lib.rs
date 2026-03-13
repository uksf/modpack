use arma_rs::{arma, Extension};
use simplelog::{LevelFilter, WriteLogger};
use std::fs::File;

mod bridge;
mod commands;
mod config;
mod listener;
mod loader;
mod sender;

fn init_logger() {
    let dll_dir = std::env::current_exe()
        .ok()
        .and_then(|p| p.parent().map(|d| d.to_path_buf()))
        .unwrap_or_default();
    let log_path = dll_dir.join("uksf_x64.log");
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
