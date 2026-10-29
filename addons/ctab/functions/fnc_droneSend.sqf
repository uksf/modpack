#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Stores a task for the selected drone in the Drones app on the drone for every machine, and asks the server to run it where the drone's crew group is local.
        The drone's position when it takes its first task is stored as its home.

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

if (isNil {_drone getVariable QGVAR(droneHome)}) then {
    _drone setVariable [QGVAR(droneHome), getPosASL _drone, true];
};
_drone setVariable [QGVAR(droneTask), [_task, GVAR(dronePoint), cTab_player], true];
[QGVAR(droneRoute), [_drone]] call CBA_fnc_serverEvent;
call FUNC(droneRefresh);
