#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Loads all saved data

    Parameter(s):
        None

    Return Value:
        None
*/

{
    _x params ["_id", "_function"];

    private _data = GVAR(dataNamespace) getVariable [_id, []];
    [_data] call _function;
} forEach GVAR(deserializers);

[{call FUNC(loadAllObjectData)}] call CBA_fnc_execNextFrame;
