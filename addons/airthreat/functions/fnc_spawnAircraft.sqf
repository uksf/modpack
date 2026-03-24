#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns an aircraft at a spawn point position, creates crew, and orients
        toward a target position. The aircraft is spawned in flight at the
        specified altitude. Does not add waypoints — callers configure behaviour.
        Runs on whatever machine calls it (HC via headlessEvent, or server as fallback).

    Parameters:
        0: Spawn position <ARRAY> - ASL position of the spawn point
        1: Aircraft classnames <ARRAY> - Pool of classnames to select from
        2: Target position <ARRAY> - Position to orient toward (default: [0,0,0])
        3: Altitude <NUMBER> - Spawn altitude in metres ASL (default: 2000)

    Return Value:
        [group, vehicle] <ARRAY> - The created group and vehicle, or [grpNull, objNull] on failure

    Example:
        [_spawnPosition, GVAR(fighterClassnames), _targetPosition, 1500] call uksf_airthreat_fnc_spawnAircraft
*/
params [
    ["_spawnPosition", [], [[]]],
    ["_classnames", [], [[]]],
    ["_targetPosition", [0, 0, 0], [[]]],
    ["_altitude", 2000, [0]]
];

if (_classnames isEqualTo []) exitWith {
    WARNING("No aircraft classnames configured");
    [grpNull, objNull]
};

if (_spawnPosition isEqualTo []) exitWith {
    WARNING("No spawn position provided");
    [grpNull, objNull]
};

private _classname = selectRandom _classnames;
private _finalPosition = +_spawnPosition;
_finalPosition set [2, _altitude + random 100];

// Create high to prevent terrain collision during setup
private _vehicle = createVehicle [_classname, [0, 0, 1000 + random 500], [], 0, "FLY"];
private _direction = _finalPosition getDir _targetPosition;
_vehicle setDir _direction;
createVehicleCrew _vehicle;

private _group = group (driver _vehicle);
_group setBehaviour "COMBAT";
_group setCombatMode "RED";
_group setSpeedMode "FULL";

// Blacklist from ACEX HC transfer — we spawn directly on HC, don't want it moved
_group setVariable ["acex_headless_blacklist", true, true];

// Tag for identification and track spawn time for stale mission cleanup
_vehicle setVariable [QGVAR(isThreat), true, true];
_vehicle setVariable [QGVAR(spawnTime), time, true];
_group setVariable [QGVAR(missionType), "", true];

// Move to final position
_vehicle setPosASL _finalPosition;

[_group, _vehicle]
