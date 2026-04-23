#include "script_component.hpp"
/*
    Author:
        Bridg, Codex

    Description:
        Handles waypoint completion for vehicle patrols.
        Deletes patrols when they are close to the expected waypoint position.
        Optionally issues an RTB waypoint if destination completion occurs away from target.

    Parameters:
        0: Vehicle <OBJECT>
        1: Crew group <GROUP>
        2: Spawn position <ARRAY>
        3: Target position <ARRAY>
        4: Add RTB waypoint when not near target <BOOL>
        5: Waypoint behaviour <STRING>
        6: Waypoint speed <STRING>

    Return Value:
        Nothing

    Example:
        [_vehicle, _crewGroup, _spawnPosition, _targetPosition, true, "SAFE", "NORMAL"] call uksf_vehiclepatrols_fnc_handleWaypointCompletion
*/

params [
    ["_vehicle", objNull, [objNull]],
    ["_crewGroup", grpNull, [grpNull]],
    ["_spawnPosition", [], [[]]],
    ["_targetPosition", [], [[]]],
    ["_addRTBWhenMissed", false, [true]],
    ["_waypointBehaviour", "SAFE", [""]],
    ["_waypointSpeed", "NORMAL", [""]]
];

if !(isServer) exitWith {};
if (isNull _vehicle) exitWith {};
if (isNull _crewGroup) exitWith {
    [_vehicle, _crewGroup, grpNull] call FUNC(deletePatrol);
};
if (_targetPosition isEqualTo []) exitWith {};

private _deleteDistance = 50;

if ((_vehicle distance2D _targetPosition) <= _deleteDistance) exitWith {
    [_vehicle, _crewGroup, grpNull] call FUNC(deletePatrol);
};

if !(_addRTBWhenMissed) exitWith {};
if (_spawnPosition isEqualTo []) exitWith {};

private _rtbWaypointAdded = _vehicle getVariable [QGVAR(rtbWaypointAdded), false];
if (_rtbWaypointAdded) exitWith {};

_vehicle setVariable [QGVAR(rtbWaypointAdded), true, false];

while {waypoints _crewGroup isNotEqualTo []} do {
    deleteWaypoint [_crewGroup, 0];
};

private _spawnWaypoint = [_crewGroup, ASLToAGL _spawnPosition, 0, "MOVE", _waypointBehaviour, "YELLOW", _waypointSpeed, "COLUMN", "", [0, 0, 0], 50] call CBA_fnc_addWaypoint;
_spawnWaypoint setWaypointStatements [
    "true",
    format ["[vehicle this, group this, %1, %1, false, '%2', '%3'] call %4;", _spawnPosition, _waypointBehaviour, _waypointSpeed, QFUNC(handleWaypointCompletion)]
];
