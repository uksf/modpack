#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles an inbound callback from the API via extensionCallback.
        Raises CBA events so consuming components can handle what they care about.

    Parameters:
        0: Function name <STRING>
        1: Data (JSON string) <STRING>

    Return Value:
        None

    Example:
        [_function, _data] call uksf_api_fnc_handleCommand
*/
params ["_function", "_data"];

TRACE_2("Received command",_function,_data);

// Raw extension callback — consumers handle specific function names
if (_function != "command") exitWith {
    [QGVAR(extensionCallback), [_function, _data]] call CBA_fnc_localEvent;
};

// Parsed command — consumers handle specific command types
private _parsed = [_data, 2] call CBA_fnc_parseJSON;
if (isNil "_parsed") exitWith {
    WARNING_1("Failed to parse command JSON: %1",_data);
};

private _type = _parsed getOrDefault ["type", ""];
INFO_1("Received command: %1",_type);
[QGVAR(command), [_type, _parsed]] call CBA_fnc_localEvent;
