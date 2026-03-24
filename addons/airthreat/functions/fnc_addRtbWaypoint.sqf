#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds an RTB (return to base) waypoint at the nearest spawn point.
        When the aircraft reaches the waypoint, it triggers cleanup.

    Parameters:
        0: Group <GROUP>
        1: Vehicle <OBJECT>

    Return Value:
        Nothing

    Example:
        [_group, _vehicle] call uksf_airthreat_fnc_addRtbWaypoint
*/
params [["_group", grpNull, [grpNull]], ["_vehicle", objNull, [objNull]]];

if (isNull _group || {isNull _vehicle}) exitWith {};

private _vehiclePosition = getPosASL _vehicle;
private _nearestSpawn = [0, 0, 0];
private _nearestDistance = 1e10;

{
    private _distance = _vehiclePosition distance _x;
    if (_distance < _nearestDistance) then {
        _nearestDistance = _distance;
        _nearestSpawn = _x;
    };
} forEach GVAR(spawnPoints);

private _waypoint = _group addWaypoint [_nearestSpawn, 100];
_waypoint setWaypointType "MOVE";
_waypoint setWaypointBehaviour "CARELESS";
_waypoint setWaypointCombatMode "BLUE";
_waypoint setWaypointStatements [
    "true",
    format ["['%1', [group this, vehicle this]] call CBA_fnc_serverEvent;", QGVAR(missionComplete)]
];
