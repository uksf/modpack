#include "script_component.hpp"
/*
    Author:
        www.3commandobrigade.com, Tim Beswick

    Description:
        Whether the reload action can resupply the current weapon from vehicle cargo,
        or a smoke launcher that needs ammunition.

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        Reload available <BOOLEAN>

    Example:
        _vehicle call UK3CB_BAF_Vehicles_Weapons_fnc_can_resupply_ammo
*/

private _vehicle = _this;
private _unit = [] call CBA_fnc_currentUnit;

if (!alive _unit || {!alive _vehicle} || {_vehicle isKindOf "StaticWeapon"} || {!(_unit in _vehicle)}) exitWith {
    false
};

private _turret = _vehicle unitTurret _unit;
private _gunNeedsCargo = false;
if (_turret isNotEqualTo []) then {
    (weaponState [_vehicle, _turret]) params ["_weapon", "_muzzle", "", "_currentMagazine", "_currentAmmo"];
    if (_weapon in (_vehicle weaponsTurret _turret) && {_currentAmmo < 1}) then {
        private _cargo = (getMagazineCargo _vehicle) select 0;
        _gunNeedsCargo = compatibleMagazines [_weapon, _muzzle] findIf { _x in _cargo } >= 0;
    };
};
if (_gunNeedsCargo) exitWith { true };

[_vehicle, false] call FUNC(reloadSmoke)
