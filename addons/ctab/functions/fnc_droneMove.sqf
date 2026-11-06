#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Replaces the waypoints of a drone whose crew group is local with one waypoint at a position.
        An aircraft gets a loiter waypoint that circles the position, unless it can hover and is told to stop there.
        A hovering helicopter and a ground drone get a move waypoint.

    Parameter(s):
        0: Drone <OBJECT>
        1: Position, only x and y are used <ARRAY>
        2: Stop at the position instead of circling it when the drone can hover <BOOL> (default: false)

    Return Value:
        Nothing

    Example:
        [_drone, getPosASL player, true] call uksf_ctab_fnc_droneMove
*/
params ["_drone", "_position", ["_stop", false]];

private _group = _drone call FUNC(droneGroup);
if (isNull _group || {!local _group}) exitWith {};

for "_index" from (count waypoints _group - 1) to 0 step -1 do {
    deleteWaypoint [_group, _index];
};

private _waypoint = _group addWaypoint [_position select [0, 2], 0];
if (_drone isKindOf "Plane" || {_drone isKindOf "Air" && {!_stop}}) then {
    _waypoint setWaypointType "LOITER";
    _waypoint setWaypointLoiterType "CIRCLE_L";
    _waypoint setWaypointLoiterRadius DRONE_LOITER_RADIUS;
} else {
    _waypoint setWaypointType "MOVE";
};
_group setCurrentWaypoint _waypoint;
