#include "script_component.hpp"
/*
    Author:
        LAxemann, Jokoho482, Tim Beswick

    Description:
        Fired Event for shockwave

    Parameters:
        0: Ammo name <STRING>
        1: Projectile <OBJECT>

    Return value:
        None
*/
params ["_ammo", "_projectile"];

private _function = [[QGVAR(shockwaveFunction_), _ammo] joinString "", {GVAR(ammoConfig) >> _ammo >> "shockwaveFunction"}] call FUNC(readCacheValues);
if (_function != "") then {
    GVAR(shockwaveArray) pushBack [_projectile, _function];
};
