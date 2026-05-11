#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns the full waypoint list for a group, with no currentWaypoint trim.
        Element format matches fnc_getGroupWaypoints. Required for CYCLE handling
        in the virtualisation simulation.

    Parameter(s):
        0: Group <GROUP>

    Return Value:
        Array of waypoint info <ARRAY>

    Example:
        [_group] call uksf_virtualisation_fnc_getFullGroupWaypoints
*/
params ["_group"];

// Index 0 is always the engine auto-stub at the group's start position.
// Real waypoints begin at index 1. Wiki: currentWaypoint
private _validWaypoints = (waypoints _group) select { (_x#1) > 0 };

_validWaypoints apply {
    [waypointPosition _x, waypointType _x, waypointBehaviour _x, waypointCombatMode _x, waypointSpeed _x, waypointFormation _x, (waypointStatements _x)#1]
}
