#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns an intercept mission targeting a player aircraft.
        Two fighter groups are spawned: one direct intercept and one
        flanking from an offset angle at a different altitude.
        Both groups actively pursue the target with forced target acquisition.
        Runs on HC via headlessEvent.

    Parameters:
        0: Target player <OBJECT> - The player in an aircraft to intercept

    Return Value:
        Nothing

    Example:
        [_target] call uksf_airthreat_fnc_intercept
*/
params [["_target", objNull, [objNull]]];

if (isNull _target) exitWith {};
if (GVAR(fighterClassnames) isEqualTo []) exitWith {
    WARNING("No fighter classnames configured");
};

private _targetVehicle = vehicle _target;
private _targetPosition = getPosASL _targetVehicle;

// Group A — direct intercept
private _spawnA = selectRandom GVAR(spawnPoints);
private _altitudeA = 1000 + random 300;

private _resultA = [_spawnA, GVAR(fighterClassnames), _targetPosition, _altitudeA] call FUNC(spawnAircraft);
_resultA params ["_groupA", "_vehicleA"];

if (isNull _groupA) exitWith {};

[_groupA, _vehicleA, "intercept"] call FUNC(registerMission);

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
private _spawnB = selectRandom GVAR(spawnPoints);
private _altitudeB = 1500 + random 500;

private _resultB = [_spawnB, GVAR(fighterClassnames), _targetPosition, _altitudeB] call FUNC(spawnAircraft);
_resultB params ["_groupB", "_vehicleB"];

if (!isNull _groupB) then {
    [_groupB, _vehicleB, "intercept"] call FUNC(registerMission);

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

INFO("Intercept mission spawned");
