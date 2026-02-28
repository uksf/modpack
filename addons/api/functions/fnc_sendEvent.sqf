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
*/
params [["_type", "", [""]], ["_data", createHashMap, [createHashMap]]];

private _event = createHashMapFromArray [["type", _type], ["data", _data]];
private _json = [_event] call CBA_fnc_encodeJSON;
"uksf" callExtension ("event:" + _json);
