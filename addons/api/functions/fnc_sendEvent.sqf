#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sends an event to the API via the extension. The wire format is engine-native
        SQF str() output of `[_type, _data]`. The extension forwards the bytes
        unchanged to the API as text/plain; the API parses the SQF on receipt.

        Bypasses CBA_fnc_encodeJSON which is O(n*log n) in addEventHandler chains
        and was a measurable cost on large payloads (e.g. mission_stats).

    Parameters:
        0: Event type <STRING>
        1: Event data <HASHMAP>

    Return Value:
        Extension queue acknowledgement <STRING> ("queued" on success)

    Example:
        [_type, _data] call uksf_api_fnc_sendEvent
*/
params [["_type", "", [""]], ["_data", createHashMap, [createHashMap]]];

if (_type isNotEqualTo "server_status" && {_type isNotEqualTo "performance"}) then {
    TRACE_1("Sending event",_type);
};

// Game-side wire is SQF: extension forwards verbatim, API parses with SqfNotationParser.
// Internal `"` characters are doubled by str() per SQF string-literal escape rules,
// so the body is already round-trip safe for `parseSimpleArray`/SqfNotationParser.
private _body = str [_type, _data];
private _result = "uksf" callExtension ["event", [_body]];
private _response = _result#0;
if (_response != "queued") then {
    WARNING_2("Extension did not queue event '%1': %2",_type,_response);
};
_response
