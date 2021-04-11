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

private _destinationModule = (synchronizedObjects _module) select {_x isKindOf "uksf_ailogistics_logisticsDestination"};
private _picketGroupModules = (synchronizedObjects _module) select {_x isKindOf "uksf_ailogistics_logisticsPicketGroup"};
private _picketGroupModulesDistances = _picketGroupModules apply {[_x distance2D _module, (getPos _x) nearRoads 100]};
_picketGroupModulesDistances sort true;

{
    [_group, getPos ((_x select 1) select 0), 0, "MOVE", "CARELESS", "YELLOW", "LIMITED", "", "", [0,0,0], 300] call CBA_fnc_addWaypoint;
} forEach _picketGroupModulesDistances;
[_group, getPos (_destinationModule select 0), 0, "MOVE", "CARELESS", "YELLOW", "LIMITED", "COLUMN", "", [45,60,75]] call CBA_fnc_addWaypoint;
[_group, getPos _module, 0, "MOVE", "CARELESS", "YELLOW", "LIMITED", "COLUMN", QUOTE([this] call FUNC(handleDelete)), [10,15,20]] call CBA_fnc_addWaypoint;
