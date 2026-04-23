#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers a projectile for Zeus debug visualisation and recursively tracks
        any submunitions it spawns.

    Parameter(s):
        0: Projectile <OBJECT>
        1: Ammo classname <STRING>
        2: Side colour <ARRAY>

    Return Value:
        None

    Example:
        [_projectile, _ammo, _sideColor] call uksf_zeus_fnc_trackProjectile
*/
params ["_projectile", "_ammo", "_sideColor"];

if (isNull _projectile || {_ammo isEqualTo ""}) exitWith {};

if (isNil {GVAR(ammoNameCache) get _ammo}) then {
    private _name = getText (EGVAR(common,configAmmo) >> _ammo >> "displayName");
    if (_name isEqualTo "") then { _name = _ammo };
    GVAR(ammoNameCache) set [_ammo, _name];
};

GVAR(trackedProjectiles) pushBack [_projectile, _ammo, _sideColor];
TRACE_3("tracked projectile",_projectile,_ammo,count GVAR(trackedProjectiles));

_projectile setVariable [QGVAR(sideColor), _sideColor];
_projectile addEventHandler ["SubmunitionCreated", {
    params ["_parentProjectile", "_submunitionProjectile"];
    if (isNull _submunitionProjectile) exitWith {};

    private _sideColor = _parentProjectile getVariable [QGVAR(sideColor), [1, 1, 1, 0.9]];
    [_submunitionProjectile, typeOf _submunitionProjectile, _sideColor] call FUNC(trackProjectile);
}];
