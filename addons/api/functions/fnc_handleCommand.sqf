#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles an inbound command from the API via extensionCallback.
        Wire format is SQF-array notation, parsed via parseSimpleArray:
            ["<type>", <arg1>, <arg2>, ...]

        Raises QGVAR(command) with [type, args] so consuming components can
        dispatch by type. args is the tail of the parsed array (everything
        after the type token), passed through verbatim.

    Parameters:
        0: Function name <STRING>
        1: Data (SQF array literal) <STRING>

    Return Value:
        None

    Example:
        [_function, _data] call uksf_api_fnc_handleCommand
*/
params ["_function", "_data"];

if (_function != "command") exitWith {
    WARNING_2("Unhandled extension callback type: %1, data: %2",_function,_data);
};

private _parsed = parseSimpleArray _data;
if (isNil "_parsed" || {!(_parsed isEqualType []) || {count _parsed < 1} || {!((_parsed#0) isEqualType "")}}) exitWith {
    WARNING_1("Failed to parse command payload: %1",_data);
};

private _type = _parsed#0;
private _args = _parsed select [1, count _parsed - 1];

TRACE_1("Received command",_type);
[QGVAR(command), [_type, _args]] call CBA_fnc_localEvent;
