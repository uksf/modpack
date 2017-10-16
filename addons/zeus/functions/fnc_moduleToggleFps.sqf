/*
    Author:
        Tim Beswick

    Description:
        Toggles the player FPS display

    Parameter(s):
        0: The module logic <OBJECT>
        1: Synchronized units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_logic", "_units", "_activated"];

if !(_activated && local _logic) exitWith {
    deleteVehicle _logic;
};
deleteVehicle _logic;

private _message = "FPS active";
GVAR(fpsEnabled) = !GVAR(fpsEnabled);
if (!GVAR(fpsEnabled)) then {
    _message = "FPS disabled";
};

[_message] call ace_common_fnc_displayTextStructured;
