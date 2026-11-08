#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers a projectile for Zeus debug visualisation and recursively tracks
        any submunitions it spawns.
        The label names the single munition, never a pack count, read from config only.
        Artillery charge magazines (artillery ammo the firing weapon also loads from
        another magazine at a different initSpeed) use the magazine display name.
        Otherwise the order is: ammo displayName, ammo displayNameShort, the magazine's
        pylonWeapon displayName, the firing weapon displayName, the magazine
        displayNameShort, the parent projectile's label, then the ammo classname.

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
    private _magazineConfig = EGVAR(common,configMagazines) >> _magazine;
    private _ammoConfig = EGVAR(common,configAmmo) >> _ammo;
    private _weaponConfig = EGVAR(common,configWeapons) >> _weapon;
    private _initSpeed = getNumber (_magazineConfig >> "initSpeed");
    private _isCharge = getNumber (_ammoConfig >> "artilleryLock") == 1 && {
        getArray (_weaponConfig >> "magazines") findIf {
            private _siblingConfig = EGVAR(common,configMagazines) >> _x;
            getText (_siblingConfig >> "ammo") == _ammo && {getNumber (_siblingConfig >> "initSpeed") != _initSpeed}
        } != -1
    };
    private _candidates = [
        ["", getText (_magazineConfig >> "displayName")] select _isCharge,
        getText (_ammoConfig >> "displayName"),
        getText (_ammoConfig >> "displayNameShort"),
        getText (EGVAR(common,configWeapons) >> getText (_magazineConfig >> "pylonWeapon") >> "displayName"),
        getText (_weaponConfig >> "displayName"),
        getText (_magazineConfig >> "displayNameShort"),
        _parentName,
        _ammo
    ];
    _name = _candidates select {_x isNotEqualTo ""} select 0;
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
