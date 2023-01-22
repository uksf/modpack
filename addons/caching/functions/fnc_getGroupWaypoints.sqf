#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
       Gets and returns a groups waypoints

    Parameters:
        0: group <OBJECT>

    Return value:
        _waypointDetailsArray
*/

params ["_group"];

private _waypointDetailsArray = [];

private _waypoints = waypoints _group; // [[EAST 1-1-A,0],[EAST 1-1-A,1],[EAST 1-1-A,2]]

{
    private _waypointBehaviour = waypointBehaviour _x;
    private _waypointFormation = waypointFormation _x;
    private _waypointPosition = waypointPosition _x;
    private _waypointSpeed = waypointSpeed _x;
    private _waypointType = waypointType _x;
    private _waypointCombatMode = waypointCombatMode _x;

    _waypointDetailsArray pushBack [_waypointBehaviour, _waypointFormation, _waypointPosition, _waypointSpeed, _waypointType, _waypointCombatMode];

} forEach _waypoints;

_waypointDetailsArray // [[wpB, wpF, wpP, wpS, wpT, wpCM], [wpB, wpF, wpP, wpS, wpT, wpCM]]
