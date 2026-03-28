#include "script_component.hpp"

/*
    Author:
        Codex

    Description:
        Checks patrol capacity constraints.
*/

params [
    ["_commander", objNull, [objNull]],
    ["_targetObjectiveName", "", [""]]
];

if (isNull _commander) exitWith {false};

private _managed = [_commander] call FUNC(refreshManagedGroups);
private _patrolMax = (_commander getVariable [QGVAR(patrolMaxGroups), 3]) max 0;
private _patrolPerObjectiveCap = (_commander getVariable [QGVAR(patrolPerObjectiveCap), 1]) max 0;

private _activePatrols = _managed select {
    (_x getOrDefault ["actionType", ""]) isEqualTo "patrol"
};
if ((count _activePatrols) >= _patrolMax) exitWith {false};

if (_targetObjectiveName isEqualTo "") exitWith {true};

private _activeForObjective = _activePatrols select {
    (_x getOrDefault ["targetObjectiveName", ""]) isEqualTo _targetObjectiveName
};
(count _activeForObjective) < _patrolPerObjectiveCap
