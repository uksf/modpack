#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sends a task for the selected drone in the Drones app to the machine where the drone is local.

    Parameter(s):
        0: Task: "observe", "escort", "hold", or "return" <STRING>

    Return Value:
        Nothing

    Example:
        ["hold"] call uksf_ctab_fnc_droneSend
*/
params ["_task"];

private _drone = GVAR(drones) param [lbCurSel APP_CTRL(droneList), objNull];
if (!alive _drone) exitWith {
    [APP_CTRL(droneInfo), ["Select a drone."]] call FUNC(setInfo);
};
if (_task == "observe" && {GVAR(dronePoint) isEqualTo []}) exitWith {
    [APP_CTRL(droneInfo), ["Click the map to set the task point first."]] call FUNC(setInfo);
};

[QGVAR(droneTask), [_drone, _task, GVAR(dronePoint), cTab_player], _drone] call CBA_fnc_targetEvent;
_drone setVariable [QGVAR(droneTask), _task, true];
call FUNC(droneRefresh);
