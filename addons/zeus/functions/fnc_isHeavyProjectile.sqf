#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if ammo classname is a heavy projectile (missile, shell, rocket, bomb).
        Caches the result in a hashmap for performance.

    Parameter(s):
        0: Ammo classname <STRING>

    Return Value:
        Is heavy projectile <BOOL>

    Example:
        [_ammo] call uksf_zeus_fnc_isHeavyProjectile
*/
params ["_ammo"];

private _cached = GVAR(ammoTypeCache) getOrDefault [_ammo, -1];
if (_cached != -1) exitWith {
    TRACE_2("cache hit",_ammo,_cached);
    _cached == 1
};

private _isHeavy = _ammo isKindOf ["MissileBase", EGVAR(common,configAmmo)]
    || {_ammo isKindOf ["ShellBase", EGVAR(common,configAmmo)]}
    || {_ammo isKindOf ["RocketBase", EGVAR(common,configAmmo)]}
    || {_ammo isKindOf ["BombCore", EGVAR(common,configAmmo)]}
    || {_ammo isKindOf ["SubmunitionBase", EGVAR(common,configAmmo)]}
    || {_ammo isKindOf ["FlareBase", EGVAR(common,configAmmo)]};

GVAR(ammoTypeCache) set [_ammo, parseNumber _isHeavy];

_isHeavy
