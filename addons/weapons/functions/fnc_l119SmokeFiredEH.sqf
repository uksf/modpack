#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Fired EH for L119 smoke rounds.
        Reads fuse time from vehicle, clears it, then triggers submunition after delay.

    Parameter(s):
        0: Vehicle <OBJECT>
        1: Weapon <STRING>
        2: Muzzle <STRING>
        3: Mode <STRING>
        4: Ammo <STRING>
        5: Magazine <STRING>
        6: Projectile <OBJECT>
        7: Gunner <OBJECT>

    Return Value:
        Nothing

    Example:
        Registered via CBA XEH - not called directly
*/
params ["_vehicle", "", "", "", "_ammo", "", "_projectile", ""];

if (!local _vehicle) exitWith {};

if (_ammo isNotEqualTo "tbd_mortars_105mm_shell_ammo_smoke") exitWith {};

private _fuseTime = _vehicle getVariable [QGVAR(smokeFuseTime), -1];
if (_fuseTime < 0) exitWith {};

_vehicle setVariable [QGVAR(smokeFuseTime), -1, true];

[{
    params ["_projectile"];
    triggerAmmo _projectile;
}, [_projectile], _fuseTime] call CBA_fnc_waitAndExecute;
