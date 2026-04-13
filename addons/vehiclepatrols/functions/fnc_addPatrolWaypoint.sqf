#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Adds patrol waypoint(s) and uses waypoint statements for deletion handling.

    Parameters:
        0: Vehicle <OBJECT>
        1: Crew group <GROUP>
        2: Passenger group <GROUP>
        3: Destination position <ARRAY>
        4: Waypoint behaviour <STRING>
        5: Waypoint speed <STRING>
        6: Turn around <BOOL>
        7: Spawn position <ARRAY>
    Return Value:
        Nothing

    Example:
        [_vehicle, _crewGroup, _passengerGroup, _destinationPosition, _waypointBehaviour, _waypointSpeed, _turnAround, _spawnPosition] call uksf_vehiclepatrols_fnc_addPatrolWaypoint
*/

params [
    ["_vehicle", objNull, [objNull]],
    ["_crewGroup", grpNull, [grpNull]],
    ["_passengerGroup", grpNull, [grpNull]],
    ["_destinationPosition", [], [[]]],
    ["_waypointBehaviour", "SAFE", [""]],
    ["_waypointSpeed", "NORMAL", [""]],
    ["_turnAround", false, [true]],
    ["_spawnPosition", [], [[]]]
];

if (isNull _vehicle) exitWith {};
if (isNull _crewGroup) exitWith {
    [_vehicle, _crewGroup, _passengerGroup] call FUNC(deletePatrol);
};

private _destinationWaypoint = [_crewGroup, ASLToAGL _destinationPosition, 0, "MOVE", _waypointBehaviour, "YELLOW", _waypointSpeed, "COLUMN", "", [0, 0, 0], 50] call CBA_fnc_addWaypoint;

if (_turnAround isEqualTo false) exitWith {
    _destinationWaypoint setWaypointStatements [
        "true",
        format ["[vehicle this, group this, grpNull] call %1;", QFUNC(deletePatrol)]
    ];
};

private _spawnWaypoint = [_crewGroup, ASLToAGL _spawnPosition, 0, "MOVE", _waypointBehaviour, "YELLOW", _waypointSpeed, "COLUMN", "", [0, 0, 0], 50] call CBA_fnc_addWaypoint;
_spawnWaypoint setWaypointStatements [
    "true",
    format ["[vehicle this, group this, grpNull] call %1;", QFUNC(deletePatrol)]
];
