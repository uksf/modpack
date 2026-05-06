#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles an inbound command from the API via extensionCallback.
        Parses the JSON and raises a CBA event so consuming components
        can handle what they care about based on the command type.

    Parameters:
        0: Function name <STRING>
        1: Data (JSON string) <STRING>

    Return Value:
        None

    Example:
        [_function, _data] call uksf_api_fnc_handleCommand
*/
params ["_function", "_data"];

if (_function != "command") exitWith {
    WARNING_2("Unhandled extension callback type: %1, data: %2",_function,_data);
};

// Persistence load chunks now ride as SQF array envelopes
//   ["persistence_load", "<id>", <index>, <total>, "<data>", "<error>"]
// — parseSimpleArray-compatible, drops CBA_fnc_parseJSON from the chunk hot path.
// API-side POSTs to /command still ship JSON; sniff first non-whitespace char.
private _trimmed = trim _data;
private _parsed = nil;
private _type = "";
private _payload = nil;

if (_trimmed select [0, 1] == "[") then {
    _parsed = parseSimpleArray _data;
    if (!isNil "_parsed" && {_parsed isEqualType [] && {count _parsed >= 1}}) then {
        _type = _parsed#0;
        // Repackage as a hashmap matching the legacy JSON-path consumer contract
        // (handleApiLoadChunk reads index/total/data/error via getOrDefault).
        if (_type == "persistence_load" && {count _parsed >= 5}) then {
            _payload = createHashMapFromArray [
                ["type",  _parsed#0],
                ["id",    _parsed#1],
                ["index", _parsed#2],
                ["total", _parsed#3],
                ["data",  _parsed#4],
                ["error", if (count _parsed >= 6) then {_parsed#5} else {""}]
            ];
        };
    };
} else {
    _payload = [_data, 2] call CBA_fnc_parseJSON;
    if (!isNil "_payload" && {_payload isEqualType createHashMap}) then {
        _type = _payload getOrDefault ["type", ""];
    };
};

if (isNil "_payload" || {!(_payload isEqualType createHashMap)}) exitWith {
    WARNING_1("Failed to parse command payload: %1",_data);
};

TRACE_1("Received command",_type);
[QGVAR(command), [_type, _payload]] call CBA_fnc_localEvent;
