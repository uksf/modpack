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

if (!(isNull (ACE_controlledUAV#0)) || {GVAR(zeusOpen)}) exitWith {};

if ((toLower _weapon) isEqualTo "put") exitWith {};

if (isNull _projectile) then {
    _projectile = nearestObject [_shooter, _ammo];
    _this set [6, _projectile];
};

private _ammoConfig = GVAR(ammoConfig) >> _ammo;
_this set [7, _ammoConfig];

call FUNC(firedShockwave);
call FUNC(firedTwitch);
