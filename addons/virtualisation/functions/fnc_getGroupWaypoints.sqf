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
*/

params ["_group"];

// Returns waypoints yet to be completed
private _waypoints = (waypoints _group) select {!(_x#1 < currentWaypoint _group)}; // [[EAST 1-1-A,2],[EAST 1-1-A,3],[EAST 1-1-A,4]]

_waypoints apply {waypointPosition _x, waypointType _x, waypointBehaviour _x, waypointCombatMode _x, waypointSpeed _x, waypointFormation _x}
