use std::time::Duration;

use crate::config;
use crate::delivery::event_type;

pub const ORDINARY_REQUEST_TIMEOUT: Duration = Duration::from_secs(5);
pub const ACKNOWLEDGED_REQUEST_TIMEOUT: Duration = Duration::from_secs(30);
const PROTOCOL_VERSION: &str = "2";

pub enum SendResult {
    Delivered,
    Rejected,
    Failed,
}

pub fn try_send(url: &str, body: &str, enqueue_at: &str, timeout: Duration) -> SendResult {
    let api_port = config::get_api_port();
    match ureq::post(url)
        .timeout(timeout)
        .set("Content-Type", "text/plain; charset=utf-8")
        .set("X-Api-Port", &api_port.to_string())
        .set("X-Enqueued-At", enqueue_at)
        .set("X-Uksf-Protocol", PROTOCOL_VERSION)
        .send_string(body)
    {
        Ok(_) => SendResult::Delivered,
        Err(ureq::Error::Status(422, _)) => SendResult::Rejected,
        Err(error) => {
            log::error!("Failed to send {} (will retry): {error}", event_type(body));
            SendResult::Failed
        }
    }
}
