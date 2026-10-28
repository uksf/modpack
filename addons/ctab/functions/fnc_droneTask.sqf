#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs a drone task on the machine where the drone is local.
        An aircraft circles its task point. A ground drone drives to it and stops.
        Observe goes to the point. Escort follows the requester, updated every few seconds. Hold stays at the current position. Return goes to where the drone took its first task.

    Parameter(s):
        0: Drone <OBJECT>
        1: Task: "observe", "escort", "hold", or "return" <STRING>
        2: Task point <ARRAY>
        3: Requester <OBJECT>

    Return Value:
        Nothing

    Example:
        [_drone, "hold", [], player] call uksf_ctab_fnc_droneTask
*/
params ["_drone", "_task", "_point", "_requester"];

if (!alive _drone || {!local _drone}) exitWith {};

[_drone getVariable [QGVAR(droneEscort), -1]] call CBA_fnc_removePerFrameHandler;
_drone setVariable [QGVAR(droneEscort), -1];
if (isNil {_drone getVariable QGVAR(droneHome)}) then {
    _drone setVariable [QGVAR(droneHome), getPosASL _drone];
};

private _target = switch (_task) do {
    case "observe": {_point};
    case "escort": {getPosASL _requester};
    case "return": {_drone getVariable QGVAR(droneHome)};
    default {getPosASL _drone};
};
[_drone, _target] call FUNC(droneMove);

if (_task == "escort") then {
    _drone setVariable [QGVAR(droneEscort), [{
        params ["_args", "_handle"];
        _args params ["_drone", "_requester"];
        if (!alive _drone || {!alive _requester} || {!local _drone}) exitWith {
            [_handle] call CBA_fnc_removePerFrameHandler;
        };
        [_drone, getPosASL _requester] call FUNC(droneMove);
    }, DRONE_ESCORT_INTERVAL, [_drone, _requester]] call CBA_fnc_addPerFrameHandler];
};
