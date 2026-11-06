#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs on the server. Sends a drone's stored task to the machine where the drone's crew group is local, because waypoints belong to the group and the group can be local to a different machine than the vehicle.
        Records which machine runs each escort, so the escort can be sent again when that machine disconnects.

    Parameter(s):
        0: Drone <OBJECT>
        1: Requested task data <ARRAY> (optional; defaults to the stored task)

    Return Value:
        Nothing

    Example:
        [_drone] call uksf_ctab_fnc_droneRoute
*/
params ["_drone", ["_requestedTask", []]];

if !(_drone isEqualType objNull) exitWith {};
if (isNull _drone || {!alive _drone} || {!unitIsUAV _drone && {!(_drone in (missionNamespace getVariable ["cTabUAVlist", []]))}}) exitWith {};
private _taskData = if (_requestedTask isEqualTo []) then {_drone getVariable [QGVAR(droneTask), []]} else {_requestedTask};
if !(_taskData isEqualType [] && {count _taskData >= 3}) exitWith {};
_taskData params ["_task", "_point", "_requester"];
if !(_task isEqualType "" && {_task in ["observe", "escort", "hold", "return"]}) exitWith {};
if !(_point isEqualType [] && {count _point in [2, 3]} && {_point isEqualTypeAll 0} && {_requester isEqualType objNull}) exitWith {};
if (_point findIf {abs _x > 10000000 || {_x != _x}} != -1) exitWith {};

private _group = _drone call FUNC(droneGroup);
if (isNull _group) exitWith {};

if (_requestedTask isNotEqualTo []) then {_drone setVariable [QGVAR(droneTask), _taskData, true]};
GVAR(escorts) = GVAR(escorts) select {alive (_x select 0) && {_x select 0 != _drone}};

private _owner = groupOwner _group;
if ((_drone getVariable [QGVAR(droneTask), []]) param [0, ""] == "escort") then {
    GVAR(escorts) pushBack [_drone, _owner];
};
[QGVAR(droneTask), [_drone], _owner] call CBA_fnc_ownerEvent;
