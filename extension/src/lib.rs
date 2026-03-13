use arma_rs::{arma, Extension};

mod bridge;
mod commands;
mod config;
mod listener;
mod loader;
mod sender;

#[arma]
fn init() -> Extension {
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
