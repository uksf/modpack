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

private _parsed = [_data, 2] call CBA_fnc_parseJSON;
if (isNil "_parsed" || {!(_parsed isEqualType createHashMap)}) exitWith {
    WARNING_1("Failed to parse command JSON: %1",_data);
};

private _type = _parsed getOrDefault ["type", ""];
TRACE_1("Received command",_type);
[QGVAR(command), [_type, _parsed]] call CBA_fnc_localEvent;
