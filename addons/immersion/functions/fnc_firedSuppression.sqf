#include "script_component.hpp"
/*
    Author:
        LAxemann, Jokoho482, Tim Beswick

    Description:
        Fired event for suppression

    Parameters:
        0: Ammo name <STRING>
        1: Projectile <OBJECT>

    Return value:
        None
*/
params ["_ammo", "_projectile"];

private _hit = [[QGVAR(hit_), _ammo] joinString "", {GVAR(ammoConfig) >> _ammo >> "hit"}] call FUNC(readCacheValues);
if (_hit == 0) exitWith {};

private _detectionDistance = (7 + (_hit / 2)) min 28;

GVAR(suppressionArray) pushBack [_projectile, _detectionDistance, _hit];
