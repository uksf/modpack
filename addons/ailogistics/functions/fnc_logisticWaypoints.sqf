#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Assign the waypoints for the logistical vehicles.

    Parameters:
        0: _group <GROUP>

    Return value:
        Nothing
*/

params ["_module", "_group"];

private _destination =  synchronizedObjects _module;

[_group, getPos (_destination select 0), 0, "MOVE", "CARELESS", "YELLOW", "LIMITED", "", "", [30,45,60]] call CBA_fnc_addWaypoint;
[_group, getPos _module, 0, "MOVE", "CARELESS", "YELLOW", "LIMITED", "COLUMN", QUOTE([this] call FUNC(handleDelete)), [10,15,20]] call CBA_fnc_addWaypoint;
