//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
// AUTHOR: by 
// DATE: 1/4/17
// VERSION: 2.0
// DESCRIPTION: Function for module "hide zeus"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
/*
    Author:
        Anton Struyk, Kex, Tim Beswick

    Description:
        Toggles visibility of curator

    Parameter(s):
        0: The module logic <OBJECT>
        1: Synchronized units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_logic", "", "_activated"];

if !(_activated && local _logic) exitWith {
    deleteVehicle _logic;
};
deleteVehicle _logic;

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
