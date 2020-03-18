#include "script_component.hpp"
/*
    Author:
        LAxemann, Jokoho482, Tim Beswick

    Description:
        Fired event for suppression

    Parameters:
        Fired Event Parameters

    Return value:
        None
*/
params ["", "", "", "", "_ammo", "", "_projectile", "_ammoConfig"];

private _hit = [_ammoConfig >> "hit", format [QGVAR(suppression_hit_%1), _ammo]] call FUNC(readCacheValues);
if (_hit == 0) exitWith {};

private _detectionDistance = (7 + (_hit / 2)) min 28;
private _pPos = getPosATL _projectile;

GVAR(suppressionArray) pushBack [_projectile, _detectionDistance, _hit];
