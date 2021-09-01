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

private _persistenceId = _logic getVariable [QGVAR(persistenceID), ""];
if (_persistenceId isEqualTo "") exitWith {
    ERROR("Rating area does not have a persistence ID");
};

GVAR(ratingAreaModules) pushBack [_persistenceId, _logic, _area];
