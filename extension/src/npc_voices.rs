use std::sync::Mutex;
use std::thread;
use std::time::{Duration, Instant};

use crate::config;

const REFRESH_AFTER: Duration = Duration::from_secs(60);

struct Cache {
    voices: Option<Vec<(String, String)>>,
    error: String,
    fetched_at: Option<Instant>,
    fetching: bool,
}

static CACHE: Mutex<Cache> = Mutex::new(Cache { voices: None, error: String::new(), fetched_at: None, fetching: false });

pub fn get() -> String {
    let mut cache = CACHE.lock().unwrap();
    let stale = cache.fetched_at.is_none_or(|at| at.elapsed() > REFRESH_AFTER);
    if stale && !cache.fetching {
        cache.fetching = true;
        thread::spawn(refresh);
    }

    let status = match (&cache.voices, cache.fetching) {
        (Some(_), _) => "ready",
        (None, true) => "pending",
        (None, false) => "error",
    };
    to_sqf(status, cache.voices.as_deref().unwrap_or_default(), &cache.error)
}

fn refresh() {
    let url = format!("{}/npcvoices/names", config::public_api_base_url());
    let result = fetch(&url);
    let mut cache = CACHE.lock().unwrap();
    cache.fetching = false;
    cache.fetched_at = Some(Instant::now());
    match result {
        Ok(voices) => {
            cache.voices = Some(voices);
            cache.error.clear();
        }
        Err(error) => {
            log::warn!("NPC voice list fetch from {url} failed: {error}");
            cache.error = error;
        }
    }
}

fn fetch(url: &str) -> Result<Vec<(String, String)>, String> {
    let body = ureq::get(url)
        .timeout(Duration::from_secs(10))
        .call()
        .map_err(|error| error.to_string())?
        .into_string()
        .map_err(|error| error.to_string())?;
    parse(&body)
}

fn parse(body: &str) -> Result<Vec<(String, String)>, String> {
    let items: Vec<serde_json::Value> = serde_json::from_str(body).map_err(|error| format!("bad voice list: {error}"))?;
    Ok(items
        .iter()
        .filter_map(|item| {
            let id = item.get("voiceId")?.as_str()?;
            let name = item.get("displayName").and_then(|n| n.as_str()).filter(|n| !n.is_empty()).unwrap_or(id);
            Some((id.to_string(), name.to_string()))
        })
        .collect())
}

fn quote(text: &str) -> String {
    format!("\"{}\"", text.replace('"', "\"\""))
}

fn to_sqf(status: &str, voices: &[(String, String)], error: &str) -> String {
    let items: Vec<String> = voices.iter().map(|(id, name)| format!("[{},{}]", quote(id), quote(name))).collect();
    format!("[{},[{}],{}]", quote(status), items.join(","), quote(error))
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn parses_names_and_falls_back_to_id() {
        let voices = parse(r#"[{"voiceId":"merl","displayName":"Merl"},{"voiceId":"tomas","displayName":""},{"displayName":"no id"}]"#).unwrap();
        assert_eq!(voices, vec![("merl".into(), "Merl".into()), ("tomas".into(), "tomas".into())]);
    }

    #[test]
    fn rejects_a_body_that_is_not_a_list() {
        assert!(parse("<html>").is_err());
    }

    #[test]
    fn escapes_quotes_for_sqf() {
        let sqf = to_sqf("ready", &[("a".into(), "The \"Boss\"".into())], "");
        assert_eq!(sqf, r#"["ready",[["a","The ""Boss"""]],""]"#);
    }

    #[test]
    fn fetches_from_the_api() {
        let server = tiny_http::Server::http("127.0.0.1:0").unwrap();
        let port = server.server_addr().to_ip().unwrap().port();
        thread::spawn(move || {
            let request = server.recv().unwrap();
            assert_eq!(request.url(), "/npcvoices/names");
            request.respond(tiny_http::Response::from_string(r#"[{"voiceId":"merl","displayName":"Merl"}]"#)).unwrap();
        });

        let voices = fetch(&format!("http://127.0.0.1:{port}/npcvoices/names")).unwrap();

        assert_eq!(voices, vec![("merl".into(), "Merl".into())]);
    }
}
