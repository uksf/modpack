#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Emit status event for a managed group.

    Parameters:
        0: Commander module <OBJECT>
        1: Group <GROUP>
        2: Status <STRING>

    Return Value:
        None
*/

params [
    ["_commander", objNull, [objNull]],
    ["_group", grpNull, [grpNull]],
    ["_status", "unknown", [""]]
];

if (isNull _commander || {isNull _group}) exitWith {};

private _actionId = _group getVariable [QGVAR(actionId), "none"];
private _targetObjectiveName = _group getVariable [QGVAR(targetObjectiveName), "none"];

["GROUP_STATUS", _commander, createHashMapFromArray [
    ["actionId", _actionId],
    ["reason", _status],
    ["message", format ["group=%1 target=%2", str _group, _targetObjectiveName]]
]] call FUNC(logExecution);
