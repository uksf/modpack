#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Updates the Drones app panel with the selected drone's position, task, and the task point.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_ctab_fnc_droneRefresh
*/
if (isNull APP_CTRL(droneInfo)) exitWith {};

private _drone = GVAR(drones) param [lbCurSel APP_CTRL(droneList), objNull];
private _lines = [];
if (isNull _drone) then {
    _lines pushBack "No friendly drones.";
} else {
    _lines pushBack format ["Grid: %1, %2 m AGL", [getPosASL _drone] call ctab_core_fnc_gridPosition, round ((getPosATL _drone) select 2)];
    _lines pushBack format ["Task: %1", (_drone getVariable [QGVAR(droneTask), []]) param [0, "none"]];
};
_lines pushBack (if (GVAR(dronePoint) isEqualTo []) then {
    "Click the map to set the task point."
} else {
    format ["Point: %1", [GVAR(dronePoint)] call ctab_core_fnc_gridPosition]
});

[APP_CTRL(droneInfo), _lines] call FUNC(setInfo);
