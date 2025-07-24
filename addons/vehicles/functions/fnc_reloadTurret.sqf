#include "script_component.hpp"
// https://github.com/ampersand38/reload-repack-turret-magazines
/*
    Author:
        Ampersand

    Description:
        Reload and repack the current magazine type

    Parameter(s):
        None

    Return Value:
        None
*/

private _player = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];
if (isRemoteControlling _player) then {
    _player = remoteControlled _player;
};

private _vehicle = objectParent _player;
if (isNull _vehicle || {_vehicle != cameraOn}) exitWith {};

private _turretPath = _vehicle unitTurret _player;
weaponState [_vehicle, _turretPath] params ["_weapon"];
if !(_weapon in (_vehicle weaponsTurret _turretPath)) exitWith {}; // FFV

weaponState [_vehicle, _turretPath] params ["", "", "", "_currentMagazine", "_currentAmmo", "_roundReloadPhase", "_magazineReloadPhase"];
if (_roundReloadPhase != 0 || {_magazineReloadPhase != 0}) exitWith {
    //systemChat "currently reloading";
};

private _cfgMagazine = configFile >> "CfgMagazines" >> _currentMagazine;

if (getText (_cfgMagazine >> "pylonWeapon") != "") exitWith {};

private _fullCount = getNumber (configFile >> "CfgMagazines" >> _currentMagazine >> "count");
if (_currentAmmo == _fullCount) exitWith {
    //systemChat "current mag full";
};

private _totalAmmo = 0;
private _magsCount = 0;

{
_x params ["_xMagazine", "_xTurretPath", "_xAmmoCount"];
if (_xMagazine != _currentMagazine || {_xTurretPath isNotEqualTo _turretPath}) then {continue;};
    _magsCount = _magsCount + 1;
    _totalAmmo = _totalAmmo + _xAmmoCount;
} forEach magazinesAllTurrets [_vehicle, true];
if (_magsCount == 1 || {_currentAmmo == _totalAmmo}) exitWith {
    //systemChat "no other ammo than in current mag";
};

private _message = format ["Total: %1. Magazines: ", _totalAmmo];
private _magsAdd = [];
for "_i" from 1 to _magsCount do {
    _vehicle removeMagazineTurret [_currentMagazine, _turretPath];
    private _ammoThisMag = selectMin [_fullCount, _totalAmmo];
    _magsAdd pushBack [_currentMagazine, _turretPath, _ammoThisMag];
    _totalAmmo = _totalAmmo - _ammoThisMag;
    _message = _message + str _ammoThisMag + ([", ", ""] select (_i == _magsCount));
};

// _vehicle vehicleChat _message;

{
    _vehicle addMagazineTurret _x;
} forEach _magsAdd;
