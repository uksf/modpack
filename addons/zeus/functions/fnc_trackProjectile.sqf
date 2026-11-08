#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers a projectile for Zeus debug visualisation and recursively tracks
        any submunitions it spawns.
        The label names the single munition, never a pack count. It uses the ammo
        display name, then displayNameShort, then the magazine name with pack-count
        tokens removed. Artillery charge magazines keep their charge name. The weapon
        name, the parent projectile's label, and the ammo classname are fallbacks.

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
    private _fnc_singleRoundName = {
        params ["_label"];
        if (_label isEqualTo "") exitWith {""};
        _label = _label regexReplace ["\s+x\d+", ""];
        _label = _label regexReplace ["\d+x\s+", ""];
        _label = _label regexReplace ["\(\d+\)", ""];
        _label = _label regexReplace ["\d+Rnd", ""];
        _label = _label regexReplace ["\(\s*\)", ""];
        _label = _label regexReplace ["\s{2,}", " "];
        _label regexReplace ["^\s+|\s+$", ""]
    };

    private _magazineName = [getText (EGVAR(common,configMagazines) >> _magazine >> "displayName")] call _fnc_singleRoundName;
    private _ammoName = getText (EGVAR(common,configAmmo) >> _ammo >> "displayName");
    if (_ammoName isEqualTo "") then {
        _ammoName = getText (EGVAR(common,configAmmo) >> _ammo >> "displayNameShort");
    };
    private _isCharge = (_magazine find "charge_mag") > -1 || {_magazineName regexMatch ".*\bCharge\b.*"};
    private _candidates = [
        ["", _magazineName] select _isCharge,
        _ammoName,
        _magazineName,
        getText (EGVAR(common,configWeapons) >> _weapon >> "displayName"),
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
