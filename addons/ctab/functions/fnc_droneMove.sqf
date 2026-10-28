#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Replaces a local drone's waypoints with one waypoint at a position.
        An aircraft gets a loiter waypoint that circles the position. A ground drone gets a move waypoint.

    Parameter(s):
        0: Drone <OBJECT>
        1: Position, only x and y are used <ARRAY>

    Return Value:
        Nothing

    Example:
        [_drone, getPosASL player] call uksf_ctab_fnc_droneMove
*/
params ["_drone", "_position"];

private _group = group driver _drone;
if (isNull _group) then {
    _group = group gunner _drone;
};
if (isNull _group) exitWith {};

for "_index" from (count waypoints _group - 1) to 0 step -1 do {
    deleteWaypoint [_group, _index];
};

private _waypoint = _group addWaypoint [_position select [0, 2], 0];
if (_drone isKindOf "Air") then {
    _waypoint setWaypointType "LOITER";
    _waypoint setWaypointLoiterType "CIRCLE_L";
    _waypoint setWaypointLoiterRadius DRONE_LOITER_RADIUS;
} else {
    _waypoint setWaypointType "MOVE";
};
_group setCurrentWaypoint _waypoint;
