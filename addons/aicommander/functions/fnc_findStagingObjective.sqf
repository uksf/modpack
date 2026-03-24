#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Find nearest friendly secure objective for staging against a target objective.

    Parameters:
        0: Commander module <OBJECT>
        1: Target objective name <STRING>

    Return Value:
        Staging objective <OBJECT>
*/

params [
    ["_commander", objNull, [objNull]],
    ["_targetObjectiveName", "", [""]]
];

if (isNull _commander || {_targetObjectiveName isEqualTo ""}) exitWith {objNull};

private _commanderSide = _commander getVariable [QGVAR(side), sideUnknown];
private _syncedObjectives = synchronizedObjects _commander select {
    !isNull _x && {(_x getVariable [QGVAR(isObjective), false]) || {_x isKindOf QGVAR(objectiveModule)}}
};

private _targetObjective = objNull;
{
    if ((_x getVariable [QGVAR(objectiveName), ""]) isEqualTo _targetObjectiveName) exitWith {
        _targetObjective = _x;
    };
} forEach _syncedObjectives;

if (isNull _targetObjective) exitWith {objNull};

private _targetPos = getPosATL _targetObjective;
private _stagingCandidates = _syncedObjectives select {
    private _ownerSide = _x getVariable [QGVAR(ownerSide), sideUnknown];
    private _state = _x getVariable [QGVAR(currentState), "not_owned"];
    (_ownerSide isEqualTo _commanderSide) && {_state isEqualTo "owned_secure"}
};

if (_stagingCandidates isEqualTo []) exitWith {objNull};

private _sorted = [_stagingCandidates, [], {_targetPos distance2D (getPosATL _x)}, "ASCEND"] call BIS_fnc_sortBy;
_sorted#0

