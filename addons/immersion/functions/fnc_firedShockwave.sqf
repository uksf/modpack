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
params ["", "", "", "", "_ammo", "", "_projectile", "_ammoConfig"];

private _fncName = [_ammoConfig >> "shockwaveFunction", QGVAR(function) + _ammo, ""] call FUNC(readCacheValues);
if (_fncName != "") then {
    GVAR(shockwaveArray) pushBack [_projectile, _fncName];
};
