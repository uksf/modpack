#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Module function that fires a target event that calls the use searchlight function where the gunner is local.

    Parameters:
        0: _module <OBJECT>

    Return value:
        Nothing
*/

(_this select 1) params ["_module"];

if (!isServer) exitWith {};

private _searchLights = synchronizedObjects _module;

{
    private _operator = gunner _x;
    [QGVAR(useSearchlightEvent), [_operator], _operator] call CBA_fnc_targetEvent;
} forEach _searchLights;
