#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs on the server. Sends a drone's stored task to the machine where the drone's crew group is local, because waypoints belong to the group and the group can be local to a different machine than the vehicle.
        Records which machine runs each escort, so the escort can be sent again when that machine disconnects.

    Parameter(s):
        0: Drone <OBJECT>

    Return Value:
        Nothing

    Example:
        [_drone] call uksf_ctab_fnc_droneRoute
*/
params ["_drone"];

GVAR(escorts) = GVAR(escorts) select {alive (_x select 0) && {_x select 0 != _drone}};

private _group = _drone call FUNC(droneGroup);
if (!alive _drone || {isNull _group}) exitWith {};

private _owner = groupOwner _group;
if ((_drone getVariable [QGVAR(droneTask), []]) param [0, ""] == "escort") then {
    GVAR(escorts) pushBack [_drone, _owner];
};
[QGVAR(droneTask), [_drone], _owner] call CBA_fnc_ownerEvent;
