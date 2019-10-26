#include "script_component.hpp"
/*
    Author:
        joko, Tim Beswick

    Description:
        Fired Event

    Parameters:
        Fired Event Parameters

    Return value:
        None
*/
params ["_shooter", "_weapon", "", "", "_ammo", "", "_projectile"];

if ((toLower _weapon) isEqualTo "put") exitWith {};

if (isNull _projectile) then {
     _projectile = nearestObject [_shooter, _ammo];
     _this set [6, _projectile];
};

private _fncName = [configFile >> "CfgAmmo" >> _ammo >> "shockwaveFunction", QGVAR(function) + _ammo, ""] call FUNC(readCacheValues);
if (_fncName != "") then {
    GVAR(shockwaveArray) pushBack [_projectile, _weapon, _ammo, _fncName, getPosATL _projectile];
};
