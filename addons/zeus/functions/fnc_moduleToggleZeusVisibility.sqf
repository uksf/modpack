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

if (!local _logic) exitWith {};

private _text = "Zeus is now hidden";
if (!(isObjectHidden player)) then  {
    [player, true] remoteExec ["hideObjectGlobal",2];
    player allowDamage false;
    player setCaptive true;
} else {
    if (isObjectHidden player) then {
        [player, false] remoteExec ["hideObjectGlobal",2];
        player allowDamage true;
        player setCaptive false;
        _text = "Zeus is now visible";
    };
};

[_text] call ace_common_fnc_displayTextStructured;

deleteVehicle _logic;
