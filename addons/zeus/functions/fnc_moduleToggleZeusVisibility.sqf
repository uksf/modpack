#include "script_component.hpp"
/*
    Author:
        Anton Struyk, Kex, Tim Beswick

    Description:
        Toggles visibility of curator

    Parameter(s):
        0: The module logic <OBJECT>

    Return Value:
        None
*/
params ["_logic"];

deleteVehicle _logic;

private _state = isObjectHidden player;
player allowDamage _state;
player setCaptive !_state;
["zen_common_hideObjectGlobal", [player, !_state]] call CBA_fnc_serverEvent;
[["Zeus Hidden", "Zeus Shown"] select _state] call ace_common_fnc_displayTextStructured;
