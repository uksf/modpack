#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if ammo classname is a heavy projectile (missile, shell, rocket, bomb).
        Caches result, display name, and icon in hashmaps for performance.

    Parameter(s):
        0: Ammo classname <STRING>
        1: Weapon classname <STRING>

    Return Value:
        Is heavy projectile <BOOL>
*/
params ["_ammo", "_weapon"];

private _cached = GVAR(ammoTypeCache) getOrDefault [_ammo, -1];
if (_cached != -1) exitWith {
    TRACE_2("cache hit",_ammo,_cached);
    _cached == 1
};

private _isHeavy = _ammo isKindOf ["MissileBase", EGVAR(common,configAmmo)]
    || {_ammo isKindOf ["ShellBase", EGVAR(common,configAmmo)]}
    || {_ammo isKindOf ["RocketBase", EGVAR(common,configAmmo)]}
    || {_ammo isKindOf ["BombCore", EGVAR(common,configAmmo)]};

GVAR(ammoTypeCache) set [_ammo, parseNumber _isHeavy];

if (_isHeavy) then {
    private _name = [getText (EGVAR(common,configAmmo) >> _ammo >> "displayName"), getText (EGVAR(common,configWeapons) >> _weapon >> "displayName"), _ammo] select {_x isNotEqualTo ""} select 0;
    GVAR(ammoNameCache) set [_ammo, _name];
    TRACE_2("heavy projectile classified",_ammo,_name);
};

_isHeavy
