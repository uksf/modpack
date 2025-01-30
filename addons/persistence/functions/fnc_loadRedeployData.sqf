#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Loads player re-deploy data on first respawn

    Parameter(s):
        None

    Return Value:
        None
*/

TRACE_1("First respawn",GVAR(data));
GVAR(data) params ["_position", "_vehicleState", "_direction", "_animation", "_loadout", "_damage", "_aceStates", "_earplugs", "_attached", "_radios", ["_diveState", [false]]];
//_positionData params ["_position", "_leaderID", "_leaderPosition", "_leaderDirection", "_relativePosition"];

private _playerPosition = getPosASL player;
if (GVAR(selectedRespawn) == "") then { // TODO: Doesn't handle objects
    WARNING("No respawn selected");
    private _respawnMarkers = allMapMarkers select {"respawn_west_" in _x};
    _respawnMarkers = _respawnMarkers apply {[_playerPosition distance (markerPos _x), _x]};
    _respawnMarkers sort true;

    GVAR(selectedRespawn) = _respawnMarkers#0#1;
};

if !(isNil QGVAR(respawn)) then {
    [{deleteMarkerLocal GVAR(respawn)}, [], 1] call CBA_fnc_waitAndExecute;
};
/*if !(isNil QGVAR(groupRespawn)) then {
    deleteMarkerLocal GVAR(groupRespawn);
};*/

TRACE_1("Respawned at",GVAR(selectedRespawn));
if (GVAR(selectedRespawn) != RESPAWN_MARKER && (_position distance _playerPosition) > 2) exitWith {
    WARNING("Different respawn selected");
};

if (isNil QGVAR(data) || {GVAR(data) isEqualTo []}) exitWith {
    WARNING("No redeploy data");
};

DEBUG("Respawn is redeploy");

player setUnitLoadout _loadout;
player setDamage _damage;

player setVariable ["ACE_hasEarPlugsIn", _earplugs, true];
[[true]] call ace_hearing_fnc_updateVolume;
[] call ace_hearing_fnc_updateHearingProtection;
{[player, player, [_x], true] call ace_attach_fnc_attach} forEach _attached;

[{call EFUNC(radios,deserializeRadios)}, [_radios], 2] call CBA_fnc_waitAndExecute;
[_diveState] call EFUNC(diving,deserialiseState);
[player, _aceStates] call EFUNC(common,deserializeAceMedical);

_vehicleState params ["_vehicleId"];
if (_vehicleId != "") exitWith {
    [QGVAR(onPersistentVehicleExists), {
        params ["_vehicle", "_vehicleId", "_role", "_index"];
        [_thisType, _thisId] call CBA_fnc_removeEventHandler;

        if (isNull _vehicle) exitWith {};

        switch (_role) do {
            case "driver": {player moveInDriver _vehicle};
            case "gunner": {player moveInGunner _vehicle};
            case "commander": {player moveInCommander _vehicle};
            case "turret": {player moveInTurret [_vehicle, _index]};
            default {player moveInCargo [_vehicle, _index]};
        };

        if (objectParent player != _vehicle) then {
            player moveInCargo _vehicle;
        };
    }] call CBA_fnc_addEventHandlerArgs;
    [QGVAR(checkPersistentVehicleExists), [_vehicleState, player]] call CBA_fnc_serverEvent;
};

[{
    params ["_position", "_direction"];

    if (((getPosASL player) distance _position) <= 1 && (round (getDir player)) == _direction) exitWith {
        true
    };

    player setDir _direction;
    player setPosASL _position;

    false
}, {}, [_position, round _direction], 0.5] call CBA_fnc_waitUntilAndExecute;

// Don't set animation if diving, does not work
if (_divingState#0 && _position#2 < 0) exitWith {};

[{
    params ["_animation"];

    private _currentAnimation = animationState player;

    if (animationState player == _animation) exitWith {
        true
    };

    player switchMove _animation;

    false
}, {}, [_animation], 0.5] call CBA_fnc_waitUntilAndExecute;
