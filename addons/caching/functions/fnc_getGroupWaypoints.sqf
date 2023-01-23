#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
       Gets and returns a groups waypoints
       To stop AI going backwards to a previous WP, doesnt include waypoints with an index less than the current waypoint

    Parameters:
        0: group <OBJECT>

    Return value:
        _waypointDetailsArray
*/

params ["_group"];

private _waypointDetailsArray = [];

// returns waypoints yet to be completed
private _waypoints = waypoints _group select {!(_x#1 < currentWaypoint _group)}; // [[EAST 1-1-A,2],[EAST 1-1-A,3],[EAST 1-1-A,4]]

{
    _waypointDetailsArray pushBack [waypointBehaviour _x, waypointFormation _x, waypointPosition _x, waypointSpeed _x, waypointType _x, waypointCombatMode _x];
} forEach _waypoints;

_waypointDetailsArray // [[wpB, wpF, wpP, wpS, wpT, wpCM], [wpB, wpF, wpP, wpS, wpT, wpCM]]
