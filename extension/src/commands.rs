use crate::raw::Raw;
use crate::bridge;
use crate::file_export;
use crate::dev_run;

pub fn event(body: Raw) -> String {
    if body.0.starts_with("\"[") {
        return "error: escaped event body".to_string();
    }
    bridge::handle_event(&body.0)
}

pub fn delivered(seq: Raw) -> String {
    bridge::handle_delivered(&seq.0)
}

pub fn load(key: Raw) -> String {
    bridge::handle_load(&key.0)
}

pub fn file_export_open(filename: Raw) -> String {
    file_export::open(filename.0)
}

pub fn file_export_write(line: Raw) -> String {
    file_export::write(line.0)
}

pub fn dev_run_open(run_id: Raw) -> String {
    dev_run::open(run_id.0)
}

pub fn dev_run_chunk(run_id: Raw, chunk: Raw) -> String {
    dev_run::chunk(run_id.0, chunk.0)
}

pub fn dev_run_log(run_id: Raw, line: Raw) -> String {
    dev_run::log(run_id.0, line.0)
}

pub fn dev_run_finish(run_id: Raw) -> String {
    dev_run::finish(run_id.0)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn event_rejects_escaped_body_before_queueing() {
        assert_eq!(event(Raw("\"[\"\"save\"\",[]]\"".to_string())), "error: escaped event body");
    }
}
