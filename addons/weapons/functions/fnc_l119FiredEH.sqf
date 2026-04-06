#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Fired EH for L119 submunition rounds (smoke, illumination).
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

if !(_ammo in GVAR(l119SubmunitionAmmos)) exitWith {};

private _fuseTime = _vehicle getVariable [QGVAR(fuseTime), -1];
if (_fuseTime < 0) exitWith {};

_vehicle setVariable [QGVAR(fuseTime), -1, true];

[{
    params ["_projectile"];

    if (isNull _projectile) exitWith {};

    private _position = getPosASL _projectile;
    private _velocity = velocity _projectile;

    triggerAmmo _projectile;

    private _emptyShell = createVehicle [QGVAR(105mm_shell_empty), ASLToATL _position, [], 0, "CAN_COLLIDE"];
    _emptyShell setPosASL _position;
    _emptyShell setVelocity _velocity;
}, [_projectile], _fuseTime] call CBA_fnc_waitAndExecute;
