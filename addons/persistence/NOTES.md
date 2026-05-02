# Persistence — performance notes

## Save path: SQF str() → API SqfNotationParser

`fnc_saveDataApi` ships the session HashMap to the API as engine-native `str()`
output (SQF-array notation). The API parses it via `SqfNotationParser` +
`SqfNotationParser.ParseAndNormalize`, then `PersistenceConverter.FromHashmap`.

This bypasses `CBA_fnc_encodeJSON` on the SQF side. For ~500 objects + 40
players the old encode path took ~43 s of blocking SQF (single 528 KB blob);
the new path is ~20-77 ms end-to-end. See git log for `cc4cea30` (which
removed chunking) and the follow-up that replaced encoding with this approach.

The SQF wrapper escape only handles `\`, `"`, `\n`, `\r`, `\t`. Other control
chars in user-provided strings would produce invalid JSON. Unlikely in
practice (class names, UUIDs, position arrays). Add escapes if it ever bites.

## Other event payloads still use CBA_fnc_encodeJSON

`fnc_sendPerformance`, `fnc_sendServerStatus`, `fnc_initMission`,
`fnc_serverSync`, `fnc_finishShutdown`, etc. all go through
`EFUNC(api,sendEvent)` which calls `CBA_fnc_encodeJSON`. These payloads are
small (KB-scale, sub-ms encode) so the cost is fine.

**Migrate later** if any of those payloads grow into hundreds-of-KB territory:
- mission stats batches in `fnc_serverSync` are the most likely candidate
- the same path (str → SqfNotationParser) works; needs a per-event-type
  handler in the C# `GameServerEventHandler`

Not a hotfix priority. Open a ticket / write a plan when stats payload size
profile changes.
