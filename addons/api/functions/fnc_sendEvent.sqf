#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sends an event to the API via the extension.

    Parameters:
        0: Event type <STRING>
        1: Event data <HASHMAP>

    Return Value:
        None

    Example:
        [_type, _data] call uksf_api_fnc_sendEvent
*/
params [["_type", "", [""]], ["_data", createHashMap, [createHashMap]]];

if (_type isNotEqualTo "server_status" && {_type isNotEqualTo "performance"}) then {
    TRACE_1("Sending event",_type);
};

private _event = createHashMapFromArray [["type", _type], ["data", _data]];
private _json = [_event] call CBA_fnc_encodeJSON;
"uksf" callExtension ["event", [_json]];
