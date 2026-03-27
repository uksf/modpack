#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Applies the local jam effects to a drone.

    Parameters:
        0: Drone <OBJECT>

    Return value:
        None
*/
params [["_drone", objNull]];

if (isNull _drone || {!local _drone} || {!alive _drone}) exitWith {};

_drone setFuel 0;
_drone engineOn false;

if (_drone getVariable [QGVAR(ecmExplosionScheduled), false]) exitWith {};
_drone setVariable [QGVAR(ecmExplosionScheduled), true];

[{
    params ["_drone"];

    if (!isNull _drone && {alive _drone}) then {
        _drone setDamage 1;
    };
}, [_drone], GVAR(ecmExplosionDelay)] call CBA_fnc_waitAndExecute;
