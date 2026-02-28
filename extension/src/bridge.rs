/// Handle a command string from callExtension
pub fn handle_command(command: &str) -> String {
    match command {
        "start" => "start not yet implemented".to_string(),
        "stop" => "stop not yet implemented".to_string(),
        cmd if cmd.starts_with("event:") => "event not yet implemented".to_string(),
        _ => format!("unknown command: {command}"),
    }
}
