#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
       Gets and returns a groups waypoints
       To stop AI going backwards to a previous WP, doesnt include waypoints with an index less than the current waypoint

    Parameters:
        0: Group <GROUP>

    Return value:
        Array of waypoint info

    Example:
        [_group] call uksf_virtualisation_fnc_getGroupWaypoints
*/

params ["_group"];

// Returns waypoints yet to be completed. Index 0 is the engine auto-stub at start position.
private _minIndex = (currentWaypoint _group) max 1;
private _waypoints = (waypoints _group) select { (_x#1) >= _minIndex };

_waypoints apply {[waypointPosition _x, waypointType _x, waypointBehaviour _x, waypointCombatMode _x, waypointSpeed _x, waypointFormation _x]}
