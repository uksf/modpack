#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns a CAP (Combat Air Patrol) mission.
        A fighter aircraft spawns and patrols a random airspace zone.
        A PFH monitors for nearby player aircraft — if detected, the CAP
        will attempt to engage. Times out and RTBs after the mission
        duration expires. Server only.

    Parameters:
        None

    Return Value:
        Nothing

    Example:
        call uksf_airthreat_fnc_cap
*/

if (GVAR(airspaces) isEqualTo []) exitWith {
    WARNING("No airspace zones registered for CAP");
};
if (GVAR(fighterClassnames) isEqualTo []) exitWith {
    WARNING("No fighter classnames configured");
};

private _airspace = selectRandom GVAR(airspaces);
_airspace params ["_airspacePosition"];
private _spawnPosition = selectRandom GVAR(spawnPoints);
private _altitude = 800 + random 1200;

private _result = [_spawnPosition, GVAR(fighterClassnames), _airspacePosition, _altitude] call FUNC(spawnAircraft);
_result params ["_group", "_vehicle"];

if (isNull _group) exitWith {};

[_group, _vehicle, "cap"] call FUNC(registerMission);

// Patrol waypoint at airspace
private _patrolWaypoint = _group addWaypoint [_airspacePosition, 500];
_patrolWaypoint setWaypointType "LOITER";
_patrolWaypoint setWaypointLoiterRadius 1500;
_patrolWaypoint setWaypointSpeed "NORMAL";

private _expiryTime = time + GVAR(capTimeout);

// Monitoring PFH — scans for nearby player aircraft
[{
    params ["_args", "_idPFH"];
    _args params ["_group", "_vehicle", "_expiryTime"];

    if (isNull _group || {!alive _vehicle} || {isNull (driver _vehicle)}) exitWith {
        [QGVAR(missionComplete), [_group, _vehicle]] call CBA_fnc_localEvent;
        [_group, _vehicle] call FUNC(cleanupAircraft);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if !(local (leader _group)) exitWith {};

    if (time > _expiryTime) exitWith {
        [_group, _vehicle] call FUNC(addRtbWaypoint);
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    // Scan for nearby player aircraft to engage
    private _vehiclePosition = getPosASL _vehicle;
    private _nearestThreat = objNull;
    private _nearestDistance = 8000;

    {
        private _playerVehicle = vehicle _x;
        if (_playerVehicle isKindOf "Air" && {!isNull objectParent _x} && {alive _x}) then {
            private _distance = _vehiclePosition distance (getPosASL _playerVehicle);
            if (_distance < _nearestDistance) then {
                _nearestDistance = _distance;
                _nearestThreat = _playerVehicle;
            };
        };
    } forEach ALL_PLAYERS;

    if (!isNull _nearestThreat) then {
        (leader _group) reveal [_nearestThreat, 4];
        (driver _vehicle) doTarget _nearestThreat;
    };
}, 5, [_group, _vehicle, _expiryTime]] call CBA_fnc_addPerFrameHandler;

INFO("CAP mission spawned");
