#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Asks the server to store and run a task for the selected drone where the drone's crew group is local.
        The task point is the map point for Observe, the requester for Escort, the drone's current position for Hold, and the handset holder's position for Return.

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

private _point = switch (_task) do {
    case "escort";
    case "return": {getPosASL cTab_player};
    case "hold": {getPosASL _drone};
    default {GVAR(dronePoint)};
};
[QGVAR(droneRoute), [_drone, [_task, _point, cTab_player]]] call CBA_fnc_serverEvent;
call FUNC(droneRefresh);
