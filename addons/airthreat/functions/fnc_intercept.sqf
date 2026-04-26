#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns an intercept mission targeting a player aircraft.
        Group A (direct intercept) spawns immediately. Group B (flanking)
        spawns staggered by INTERCEPT_STAGGER_DELAY ±25% to feel less
        scripted. Both groups actively pursue the target with forced
        target acquisition. Server only.

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

// Group A — direct intercept, spawns immediately
private _altitudeA = 1000 + random 300;
private _resultA = [_nearestSpawn, GVAR(fighterClassnames), _targetPosition, _altitudeA] call FUNC(spawnAircraft);
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

[_groupA, _vehicleA, _target] call FUNC(interceptPursue);

// Group B — flanking approach at higher altitude, spawns staggered
private _staggerDelay = INTERCEPT_STAGGER_DELAY * (0.75 + random 0.5);

[{
    params ["_nearestSpawn", "_target", "_zoneIndex"];

    if (isNull _target || {!alive _target} || {!(vehicle _target isKindOf "Air")}) exitWith {
        TRACE_1("Intercept group B aborted — target lost during stagger",_target);
    };

    if !(call FUNC(canSpawnMission)) exitWith {
        TRACE_1("Intercept group B aborted — max missions at stagger commit",_target);
    };

    private _altitudeB = 1500 + random 500;
    private _targetPositionB = getPosASL (vehicle _target);
    private _resultB = [_nearestSpawn, GVAR(fighterClassnames), _targetPositionB, _altitudeB] call FUNC(spawnAircraft);
    _resultB params ["_groupB", "_vehicleB"];

    if (isNull _groupB) exitWith {};

    [_groupB, _vehicleB, "intercept", _zoneIndex] call FUNC(registerMission);
    _vehicleB setVariable [QGVAR(interceptTarget), _target, true];

    {
        _x setSkill 1;
    } forEach (units _groupB);

    private _waypointB = _groupB addWaypoint [_targetPositionB, 100];
    _waypointB setWaypointType "MOVE";
    _waypointB setWaypointBehaviour "COMBAT";
    _waypointB setWaypointCombatMode "RED";
    _waypointB setWaypointSpeed "FULL";

    [_groupB, _vehicleB, _target] call FUNC(interceptPursue);
}, [_nearestSpawn, _target, _zoneIndex], _staggerDelay] call CBA_fnc_waitAndExecute;

DEBUG("Intercept mission spawned (A now, B staggered)");
