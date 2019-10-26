#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles the player FPS display

    Parameter(s):
        0: The module logic <OBJECT>

    Return Value:
        None
*/
params ["_logic"];

if (!local _logic) exitWith {};
if (!isMultiplayer) exitWith {deleteVehicle _logic;};

GVAR(fpsEnabled) = !GVAR(fpsEnabled);
[["FPS Disabled", "FPS Active"] select GVAR(fpsEnabled)] call ace_common_fnc_displayTextStructured;

deleteVehicle _logic;
