#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs a drone task on the machine where the drone is local.
        An aircraft circles its task point. A ground drone drives to it and stops.
        Observe goes to the point. Escort follows the requester, checked every few seconds and moved only when the requester has moved far enough. Hold stays at the current position. Return goes to where the drone took its first task.

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
        _args params ["_drone", "_requester", "_target"];
        if (!alive _drone || {!alive _requester} || {!local _drone}) exitWith {
            [_handle] call CBA_fnc_removePerFrameHandler;
        };
        private _position = getPosASL _requester;
        if (_position distance2D _target < DRONE_ESCORT_MOVE) exitWith {};
        _args set [2, _position];
        [_drone, _position] call FUNC(droneMove);
    }, DRONE_ESCORT_INTERVAL, [_drone, _requester, _target]] call CBA_fnc_addPerFrameHandler];
};
