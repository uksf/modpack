#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers a projectile for Zeus debug visualisation and recursively tracks
        any submunitions it spawns.
        The label is the ammo display name, then the magazine, then the weapon, then
        the parent projectile's label, then the ammo classname. Magazines that share
        one ammo class, such as artillery charges, keep their own labels.

    Parameter(s):
        0: Projectile <OBJECT>
        1: Ammo classname <STRING>
        2: Side colour <ARRAY>
        3: Magazine classname <STRING> (default: "")
        4: Weapon classname <STRING> (default: "")
        5: Parent projectile label <STRING> (default: "")

    Return Value:
        None

    Example:
        [_projectile, _ammo, _sideColor, _magazine, _weapon] call uksf_zeus_fnc_trackProjectile
*/
params ["_projectile", "_ammo", "_sideColor", ["_magazine", ""], ["_weapon", ""], ["_parentName", ""]];

if (isNull _projectile || {_ammo isEqualTo ""}) exitWith {};

private _nameKey = [_ammo, _magazine, _weapon, _parentName];
private _name = GVAR(projectileNameCache) get _nameKey;
if (isNil "_name") then {
    _name = [
        getText (EGVAR(common,configAmmo) >> _ammo >> "displayName"),
        getText (EGVAR(common,configMagazines) >> _magazine >> "displayName"),
        getText (EGVAR(common,configWeapons) >> _weapon >> "displayName"),
        _parentName,
        _ammo
    ] select {_x isNotEqualTo ""} select 0;
    GVAR(projectileNameCache) set [_nameKey, _name];
};

GVAR(trackedProjectiles) pushBack [_projectile, _name, _sideColor];
TRACE_3("tracked projectile",_projectile,_name,count GVAR(trackedProjectiles));

_projectile setVariable [QGVAR(sideColor), _sideColor];
_projectile setVariable [QGVAR(name), _name];
_projectile addEventHandler ["SubmunitionCreated", {
    params ["_parentProjectile", "_submunitionProjectile"];
    if (isNull _submunitionProjectile) exitWith {};

    private _sideColor = _parentProjectile getVariable [QGVAR(sideColor), [1, 1, 1, 0.9]];
    private _parentName = _parentProjectile getVariable [QGVAR(name), ""];
    [_submunitionProjectile, typeOf _submunitionProjectile, _sideColor, "", "", _parentName] call FUNC(trackProjectile);
}];
