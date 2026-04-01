#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns an intercept mission targeting a player aircraft.
        Two fighter groups are spawned: one direct intercept and one
        flanking from an offset angle at a different altitude.
        Both groups actively pursue the target with forced target acquisition.
        Server only.

    Parameters:
        0: Target player <OBJECT> - The player in an aircraft to intercept
        1: Zone index <NUMBER> - Index into interceptZones that triggered this mission (default: -1)

    Return Value:
        Nothing

    Example:
        [_target, _zoneIndex] call uksf_airthreat_fnc_intercept
*/
params [["_target", objNull, [objNull]], ["_zoneIndex", -1, [0]]];

if (isNull _target) exitWith {};
if (GVAR(fighterClassnames) isEqualTo []) exitWith {
    WARNING("No fighter classnames configured");
};

private _targetVehicle = vehicle _target;
private _targetPosition = getPosASL _targetVehicle;

// Select nearest spawn point to target for faster intercept response
private _nearestSpawn = GVAR(spawnPoints) select 0;
private _nearestDistance = _targetPosition distance _nearestSpawn;
{
    private _distance = _targetPosition distance _x;
    if (_distance < _nearestDistance) then {
        _nearestDistance = _distance;
        _nearestSpawn = _x;
    };
} forEach GVAR(spawnPoints);

// Group A — direct intercept
private _spawnA = _nearestSpawn;
private _altitudeA = 1000 + random 300;

private _resultA = [_spawnA, GVAR(fighterClassnames), _targetPosition, _altitudeA] call FUNC(spawnAircraft);
_resultA params ["_groupA", "_vehicleA"];

if (isNull _groupA) exitWith {};

[_groupA, _vehicleA, "intercept", _zoneIndex] call FUNC(registerMission);
_vehicleA setVariable [QGVAR(interceptTarget), _target, true];

{
    _x setSkill 1;
} forEach (units _groupA);

private _waypointA = _groupA addWaypoint [_targetPosition, 100];
_waypointA setWaypointType "MOVE";
_waypointA setWaypointBehaviour "COMBAT";
_waypointA setWaypointCombatMode "RED";
_waypointA setWaypointSpeed "FULL";

// Start pursuit PFH for Group A
[_groupA, _vehicleA, _target] call FUNC(interceptPursue);

// Group B — flanking approach at higher altitude
private _spawnB = _nearestSpawn;
private _altitudeB = 1500 + random 500;

private _resultB = [_spawnB, GVAR(fighterClassnames), _targetPosition, _altitudeB] call FUNC(spawnAircraft);
_resultB params ["_groupB", "_vehicleB"];

if (!isNull _groupB) then {
    [_groupB, _vehicleB, "intercept", _zoneIndex] call FUNC(registerMission);
    _vehicleB setVariable [QGVAR(interceptTarget), _target, true];

    {
        _x setSkill 1;
    } forEach (units _groupB);

    private _waypointB = _groupB addWaypoint [_targetPosition, 100];
    _waypointB setWaypointType "MOVE";
    _waypointB setWaypointBehaviour "COMBAT";
    _waypointB setWaypointCombatMode "RED";
    _waypointB setWaypointSpeed "FULL";

    [_groupB, _vehicleB, _target] call FUNC(interceptPursue);
};

DEBUG("Intercept mission spawned");
