#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if ammo classname is a heavy projectile (missile, shell, rocket, bomb).
        Caches result, display name, and icon in hashmaps for performance.

    Parameter(s):
        0: Ammo classname <STRING>

    Return Value:
        Is heavy projectile <BOOL>
*/
params ["_ammo"];

private _cached = GVAR(ammoTypeCache) getOrDefault [_ammo, -1];
if (_cached != -1) exitWith {_cached};

private _cfgAmmo = configFile >> "CfgAmmo";
private _isHeavy = false;
private _icon = "";

if (_ammo isKindOf ["MissileBase", _cfgAmmo]) then {
    _isHeavy = true;
    _icon = "\a3\ui_f\data\map\markers\military\triangle_ca.paa";
} else {
    if (_ammo isKindOf ["ShellBase", _cfgAmmo]) then {
        _isHeavy = true;
        _icon = "\a3\ui_f\data\map\markers\military\dot_ca.paa";
    } else {
        if (_ammo isKindOf ["RocketBase", _cfgAmmo]) then {
            _isHeavy = true;
            _icon = "\a3\ui_f\data\map\markers\military\diamond_ca.paa";
        } else {
            if (_ammo isKindOf ["BombCore", _cfgAmmo]) then {
                _isHeavy = true;
                _icon = "\a3\ui_f\data\map\markers\military\box_ca.paa";
            };
        };
    };
};

GVAR(ammoTypeCache) set [_ammo, _isHeavy];

if (_isHeavy) then {
    private _name = getText (_cfgAmmo >> _ammo >> "displayName");
    if (_name == "") then { _name = _ammo };
    GVAR(ammoNameCache) set [_ammo, _name];
    GVAR(ammoIconCache) set [_ammo, _icon];
};

_isHeavy
