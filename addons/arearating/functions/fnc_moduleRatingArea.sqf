#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Rating area module

    Parameters:
        0: The module logic <OBJECT>

    Return value:
        Nothing
*/
(_this#1) params ["_logic"];

if !(isServer) exitWith {};

private _area = _logic getVariable ["objectarea", []];
if (_area isEqualTo []) exitWith {};

private _id = _logic getVariable [QGVAR(id), ""];
if (_id isEqualTo "") exitWith {
    ERROR("Rating area does not have an ID");
};

private _displayName = _logic getVariable [QGVAR(displayName), ""];

GVAR(ratingAreaModules) pushBack [_id, _displayName, _logic, _area];
