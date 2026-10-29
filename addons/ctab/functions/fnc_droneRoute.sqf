#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs on the server. Sends a drone's stored task to the machine where the drone's crew group is local, because waypoints belong to the group and the group can be local to a different machine than the vehicle.

    Parameter(s):
        0: Drone <OBJECT>

    Return Value:
        Nothing

    Example:
        [_drone] call uksf_ctab_fnc_droneRoute
*/
params ["_drone"];

private _group = _drone call FUNC(droneGroup);
if (!alive _drone || {isNull _group}) exitWith {};

[QGVAR(droneTask), [_drone], groupOwner _group] call CBA_fnc_ownerEvent;
