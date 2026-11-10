#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Player who should be credited for a shot, hit, or kill. objNull means
        nobody: AI, or Zeus remote control.

        On foot and in a manned vehicle, the seat that owns the weapon is
        credited when that seat is a player. A UAV credits the player in the
        firing role from UAVControl: driver turret (path [-1]) to "DRIVER",
        any other turret to "GUNNER". That is the controller at call time.
        Shots call this when the round is fired. When the weapon is unknown
        and the firer is the UAV itself, one connected player is credited;
        two different players are not guessed.

        Zeus remote control is not credited. The puppet is AI, and curator
        puppetry is not personal performance.

    Parameters:
        0: Firer <OBJECT> — man, vehicle, or UAV crew
        1: Weapon <STRING> (Optional) — fired weapon, used to pick the turret

    Return Value:
        Credited player <OBJECT>, or objNull

    Example:
        [_vehicle, _weapon] call uksf_statistics_fnc_creditedShooter
*/
params [["_firer", objNull, [objNull]], ["_weapon", "", [""]]];

if (isNull _firer) exitWith {objNull};
if ([_firer] call FUNC(zeusRemoteControlled)) exitWith {objNull};

private _fnc_controller = {
    params ["_uav", "_role"];
    if (isNull _uav || {!unitIsUAV _uav}) exitWith {objNull};
    private _control = UAVControl _uav;
    private _roleIndex = _control find _role;
    if (_roleIndex < 1) then {
        _roleIndex = _control find toLower _role;
    };
    if (_roleIndex < 1) exitWith {objNull};
    private _controller = _control select (_roleIndex - 1);
    if (isNull _controller || {!isPlayer _controller}) exitWith {objNull};
    _controller
};

if (_firer isKindOf "CAManBase") exitWith {
    if (isPlayer _firer && {!unitIsUAV _firer}) exitWith {_firer};
    if (!unitIsUAV _firer) exitWith {objNull};
    private _uav = vehicle _firer;
    private _role = "GUNNER";
    if (assignedVehicleRole _firer isEqualTo ["driver"] || {_uav unitTurret _firer isEqualTo [-1]}) then {
        _role = "DRIVER";
    };
    [_uav, _role] call _fnc_controller
};

private _vehicle = _firer;
private _seat = objNull;
private _turret = [];
if (_weapon isNotEqualTo "") then {
    {
        if (_weapon in (_vehicle weaponsTurret _x)) exitWith {
            _seat = _vehicle turretUnit _x;
            _turret = _x;
        };
    } forEach allTurrets [_vehicle, true];
    if (isNull _seat && {_weapon in (_vehicle weaponsTurret [-1])}) then {
        _seat = _vehicle turretUnit [-1];
        _turret = [-1];
    };
};

if (isNull _seat && {isManualFire _vehicle}) then {
    _seat = effectiveCommander _vehicle;
    _turret = _vehicle unitTurret _seat;
};

private _acePlayer = missionNamespace getVariable ["ACE_player", objNull];
if (isNull _seat && {isPlayer _acePlayer} && {vehicle _acePlayer isEqualTo _vehicle}) then {
    _seat = _acePlayer;
    _turret = _vehicle unitTurret _seat;
};

if (!isNull _seat) exitWith {
    if ([_seat] call FUNC(zeusRemoteControlled)) exitWith {objNull};
    if (isPlayer _seat && {!unitIsUAV _seat}) exitWith {_seat};
    if (unitIsUAV _vehicle || {unitIsUAV _seat}) then {
        private _role = "GUNNER";
        if (_turret isEqualTo [-1] || {assignedVehicleRole _seat isEqualTo ["driver"]}) then {
            _role = "DRIVER";
        };
        [_vehicle, _role] call _fnc_controller
    } else {
        objNull
    };
};

if (!unitIsUAV _vehicle) exitWith {objNull};

if (_turret isNotEqualTo []) exitWith {
    private _role = if (_turret isEqualTo [-1]) then {"DRIVER"} else {"GUNNER"};
    [_vehicle, _role] call _fnc_controller
};

private _driver = [_vehicle, "DRIVER"] call _fnc_controller;
private _gunner = [_vehicle, "GUNNER"] call _fnc_controller;
if (isNull _driver) exitWith {_gunner};
if (isNull _gunner || {_gunner isEqualTo _driver}) exitWith {_driver};
objNull
