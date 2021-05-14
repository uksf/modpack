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

if !(isNil QGVAR(respawn)) then {
    [{deleteMarkerLocal GVAR(respawn)}, [], 1] call CBA_fnc_waitAndExecute;
};
/*if !(isNil QGVAR(groupRespawn)) then {
    deleteMarkerLocal GVAR(groupRespawn);
};*/

TRACE_1("Respawned at",GVAR(selectedRespawn));

if (GVAR(data) isEqualTo [] || {GVAR(selectedRespawn) != RESPAWN_MARKER && {(_position distance2D (getPos player)) > 5}}) exitWith {};

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

    private _currentPosition = getPosASL player;
    private _currentDirection = getDir player;

    if ((_currentPosition distance _position) <= 1 && _currentDirection == _direction) exitWith {
        true
    };

    if ((_currentPosition distance _position) > 1) then {
        player setPosASL _position;
    };

    if (_currentDirection != _direction) then {
        player setDir _direction;
    };

    false
}, {}, [_position, _direction], 1] call CBA_fnc_waitUntilAndExecute;


// Don't set animation if diving
if (_diveState#0 && ((eyePos player)#2) < 0) exitWith {};

[{
    params ["_animation"];

    if ((animationState player) == _animation) exitWith {
        true
    };

    player playMove _animation;

    false
}, {}, [_animation], 1] call CBA_fnc_waitUntilAndExecute;

