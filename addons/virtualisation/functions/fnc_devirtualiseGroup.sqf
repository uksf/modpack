#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Removes one virtual group from every virtualisation registry and sends it to be recreated
        at its simulated position. Server only.

    Parameter(s):
        0: Index in groupPositionMap <SCALAR>
        1: Exclude the recreated group from virtualisation <BOOLEAN> (default: false)

    Return Value:
        None

    Example:
        [0] call uksf_virtualisation_fnc_devirtualiseGroup
*/
params ["_groupIndex", ["_exclude", false]];

private _id = (GVAR(groupPositionMap) deleteAt _groupIndex)#0;
TRACE_1("requesting recreate group",_id);

private _simulatedIndex = GVAR(simulatedGroupIds) findIf {_x == _id};
if (_simulatedIndex >= 0) then { GVAR(simulatedGroupIds) deleteAt _simulatedIndex };
GVAR(simPhases) deleteAt _id;

private _entry = GVAR(groupDataMap) deleteAt _id;
_entry params ["_side", "_vehicles", "_infantry", "_waypoints", "_combatMode", "_formationDirection",
               "_simState", "", "", "", "_originalLeaderPos"];

private _simPosition = _simState#1;
private _rebaseDelta = [_simPosition#0 - _originalLeaderPos#0, _simPosition#1 - _originalLeaderPos#1, 0];

private _payload = [_side, _vehicles, _infantry, _waypoints, _combatMode, _formationDirection, _rebaseDelta];
[QGVAR(recreateGroup), [_payload, _exclude]] call EFUNC(common,headlessEvent);
