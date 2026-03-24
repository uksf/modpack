#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns a CAS (Close Air Support) mission. An attack helicopter
        flies to the target position and performs search-and-destroy.
        Can be called with an explicit target position (from recon follow-up)
        or will select a ground player target.
        Runs on HC via headlessEvent.

    Parameters:
        0: Target position <ARRAY> - Explicit target position, or empty to use selectTarget (default: [])

    Return Value:
        Nothing

    Example:
        [_targetPosition] call uksf_airthreat_fnc_cas
*/
params [["_targetPosition", [], [[]]]];

if (GVAR(casClassnames) isEqualTo []) exitWith {
    WARNING("No CAS classnames configured");
};

// If no explicit target, select a ground player
if (_targetPosition isEqualTo []) then {
    private _target = [false] call FUNC(selectTarget);
    if (isNull _target) exitWith {};
    _targetPosition = getPosASL _target;
};

if (_targetPosition isEqualTo []) exitWith {};

private _spawnPosition = selectRandom GVAR(spawnPoints);

private _result = [_spawnPosition, GVAR(casClassnames), _targetPosition, 300 + random 200] call FUNC(spawnAircraft);
_result params ["_group", "_vehicle"];

if (isNull _group) exitWith {};

[_group, _vehicle, "cas"] call FUNC(registerMission);

// SAD waypoint at target
private _waypoint = _group addWaypoint [_targetPosition, 200];
_waypoint setWaypointType "SAD";
_waypoint setWaypointBehaviour "COMBAT";
_waypoint setWaypointCombatMode "RED";
_waypoint setWaypointSpeed "FULL";

// Timeout — RTB after 10-15 minutes
private _expiryTime = time + 600 + random 300;

[{
    params ["_group", "_vehicle", "_expiryTime"];

    if (isNull _group || {!alive _vehicle} || {isNull (driver _vehicle)}) exitWith {
        [QGVAR(missionComplete), [_group, _vehicle]] call CBA_fnc_serverEvent;
        [_group, _vehicle] call FUNC(cleanupAircraft);
        [_thisHandle] call CBA_fnc_removePerFrameHandler;
    };

    if !(local (leader _group)) exitWith {};

    if (time > _expiryTime) exitWith {
        [_group, _vehicle] call FUNC(addRtbWaypoint);
        [_thisHandle] call CBA_fnc_removePerFrameHandler;
    };

    // Force target acquisition on nearby players
    private _vehiclePosition = getPosASL _vehicle;
    {
        if (alive _x && {(_vehiclePosition distance getPosASL _x) < 3000}) then {
            (leader _group) reveal [_x, 4];
        };
    } forEach ALL_PLAYERS;
}, 15, [_group, _vehicle, _expiryTime]] call CBA_fnc_addPerFrameHandler;

INFO("CAS mission spawned");
