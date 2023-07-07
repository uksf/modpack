#include "script_component.hpp"
// https://github.com/ampersand38/reload-repack-turret-magazines
/*
    Author:
        Ampersand, Tim Beswick

    Description:
        Reload and repack the current magazine type

    Parameter(s):
        None

    Return Value:
        None
*/
private _player = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];
private _vehicle = vehicle _player;
if (!alive _player || !alive _vehicle || !(_player in _vehicle)) exitWith {
    DEBUG("Unit/vehicle is dead, or unit is not in this vehicle");
};

private _turretPath = _vehicle unitTurret _player;
weaponState [_vehicle, _turretPath] params ["_weapon", "", "", "_currentMagazine", "_currentAmmo", "_roundReloadPhase", "_magazineReloadPhase"];
if !(_weapon in (_vehicle weaponsTurret _turretPath)) exitWith { // FFV
    DEBUG("FFV");
};

if (_roundReloadPhase > 0 || {_magazineReloadPhase > 0}) exitWith {
    DEBUG("currently reloading");
};

private _fullCount = getNumber (configFile >> "CfgMagazines" >> _currentMagazine >> "count");
if (_currentAmmo == _fullCount) exitWith {
    DEBUG("Current magazine full");
};

private _totalAmmo = 0;
private _magsCount = 0;
{
    _x params ["_xMagazine", "_xTurretPath", "_xAmmoCount"];

    if (_xMagazine != _currentMagazine || {_xTurretPath isNotEqualTo _turretPath}) then {
        continue;
    };

    _magsCount = _magsCount + 1;
    _totalAmmo = _totalAmmo + _xAmmoCount;
} forEach magazinesAllTurrets [_vehicle, true];

if (_magsCount == 1 || {_currentAmmo == _totalAmmo}) exitWith {
    DEBUG("No other ammo than in current mag");
};

private _magazinesToAdd = [];
for "_i" from 1 to _magsCount do {
    _vehicle removeMagazineTurret [_currentMagazine, _turretPath];

    private _ammoThisMag = selectMin [_fullCount, _totalAmmo];
    _magazinesToAdd pushBack [_currentMagazine, _turretPath, _ammoThisMag];
    _totalAmmo = _totalAmmo - _ammoThisMag;
};

TRACE_4("Adding repacked magazines",_vehicle,_weapon,_currentMagazine,_magazinesToAdd);
{
    _vehicle addMagazineTurret _x;
} forEach _magazinesToAdd;
