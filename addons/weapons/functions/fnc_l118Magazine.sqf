#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Changes a gun magazine on the turret owner and acknowledges the result.

    Parameters:
        0: Gun <OBJECT>
        1: Transaction <NUMBER>
        2: New magazine, or empty to unload <STRING>

    Return value:
        Nothing

    Example:
        [_gun, 1, ""] remoteExecCall ["uksf_weapons_fnc_l118Magazine", 2]
*/
params ["_gun", "_token", "_magazine"];
if (isNull _gun || {!(_gun turretLocal [0])}) exitWith {};
{_gun removeMagazinesTurret [_x, [0]]} forEach (_gun magazinesTurret [0]);
if (_magazine isNotEqualTo "") then {_gun addMagazineTurret [_magazine, [0], 1]};
[_gun, _token] remoteExecCall [QFUNC(l118Acknowledge), 2];
