#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Spawns a small explosion on module position

    Parameter(s):
        0: The module logic <OBJECT>

    Return Value:
        None
*/
params ["_logic"];

if (!local _logic) exitWith {};

private _pos = getPos _logic;
private _bomb = "DemoCharge_Remote_Ammo" createVehicle [_pos select 0, _pos select 1, (_pos select 2) + 0.1];
_bomb setDamage 1;

deleteVehicle _logic;
