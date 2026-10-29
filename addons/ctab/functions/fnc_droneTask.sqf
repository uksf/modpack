#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs the task stored on a drone, on the machine where the drone's crew group is local.
        An aircraft circles its task point. A ground drone drives to it and stops.
        Observe goes to the point. Escort follows the requester, checked every few seconds and moved only when the requester has moved far enough. Hold stays at the current position. Return goes to where the drone took its first task.
        When the crew group is not local, or stops being local during an escort, the task goes back to the server, which sends it to the new owner.
        When the escort requester dies or disconnects, the task becomes Observe at the last escort point.

    Parameter(s):
        0: Drone <OBJECT>

    Return Value:
        Nothing

    Example:
        [_drone] call uksf_ctab_fnc_droneTask
*/
params ["_drone"];

private _group = _drone call FUNC(droneGroup);
if (!alive _drone || {isNull _group}) exitWith {};
if (!local _group) exitWith {
    [{[QGVAR(droneRoute), _this] call CBA_fnc_serverEvent}, [_drone], DRONE_REROUTE_DELAY] call CBA_fnc_waitAndExecute;
};

[_drone getVariable [QGVAR(droneEscort), -1]] call CBA_fnc_removePerFrameHandler;
_drone setVariable [QGVAR(droneEscort), -1];

(_drone getVariable [QGVAR(droneTask), []]) params [["_task", ""], ["_point", []], ["_requester", objNull]];
if (_task == "escort" && {!alive _requester}) then {
    _task = "observe";
    _point = getPosASL _drone;
    _drone setVariable [QGVAR(droneTask), [_task, _point, objNull], true];
};
private _target = switch (_task) do {
    case "observe": {_point};
    case "escort": {getPosASL _requester};
    case "return": {_drone getVariable [QGVAR(droneHome), getPosASL _drone]};
    default {getPosASL _drone};
};
[_drone, _target] call FUNC(droneMove);

if (_task == "escort") then {
    _drone setVariable [QGVAR(droneEscort), [{
        params ["_args", "_handle"];
        _args params ["_drone", "_requester", "_target"];
        if (!alive _drone || {(_drone getVariable [QGVAR(droneTask), []]) param [0, ""] != "escort"}) exitWith {
            [_handle] call CBA_fnc_removePerFrameHandler;
        };
        if (!alive _requester) exitWith {
            [_handle] call CBA_fnc_removePerFrameHandler;
            _drone setVariable [QGVAR(droneTask), ["observe", _target, objNull], true];
        };
        if (!local (_drone call FUNC(droneGroup))) exitWith {
            [_handle] call CBA_fnc_removePerFrameHandler;
            [QGVAR(droneRoute), [_drone]] call CBA_fnc_serverEvent;
        };
        private _position = getPosASL _requester;
        if (_position distance2D _target < DRONE_ESCORT_MOVE) exitWith {};
        _args set [2, _position];
        [_drone, _position] call FUNC(droneMove);
    }, DRONE_ESCORT_INTERVAL, [_drone, _requester, _target]] call CBA_fnc_addPerFrameHandler];
};
