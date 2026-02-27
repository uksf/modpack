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

if (!isMultiplayer) exitWith {deleteVehicle _logic;};

deleteVehicle _logic;

[QGVAR(fps)] call FUNC(debugToggle);
private _active = GVAR(debugActiveToggles) getOrDefault [QGVAR(fps), false];
[["FPS Disabled", "FPS Active"] select _active] call ace_common_fnc_displayTextStructured;

