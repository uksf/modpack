#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles an inbound command from the API via extensionCallback.
        JSON is parsed using CBA_fnc_parseJSON into a native hashmap.

    Parameters:
        0: Function name <STRING>
        1: Data (JSON string) <STRING>

    Return Value:
        None
*/
params ["_function", "_data"];

TRACE_2("Received command",_function,_data);

if (_function != "command") exitWith {};

private _parsed = [_data, 2] call CBA_fnc_parseJSON;
if (isNil "_parsed") exitWith {
    WARNING_1("Failed to parse command JSON: %1",_data);
};

private _type = _parsed getOrDefault ["type", ""];
switch (_type) do {
    case "shutdown": {
        INFO("Received shutdown command from API");
        if (isServer && {!isNil {EFUNC(persistence,shutdown)}}) then {
            call EFUNC(persistence,shutdown);
        } else {
            SERVER_COMMAND serverCommand "#shutdown";
        };
    };
    default {
        WARNING_1("Unknown command type: %1",_type);
    };
};
