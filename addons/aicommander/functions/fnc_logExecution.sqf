#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Emit commander execution line to RPT.

    Parameters:
        0: Event type <STRING>
        1: Commander module <OBJECT>
        2: Data <HASHMAP>

    Return Value:
        None
*/

params [
    ["_eventType", "", [""]],
    ["_commander", objNull, [objNull]],
    ["_data", createHashMap, [createHashMap]]
];

if (_eventType isEqualTo "" || {isNull _commander}) exitWith {};

private _commanderName = vehicleVarName _commander;
if (_commanderName isEqualTo "") then {
    _commanderName = str _commander;
};

private _missionTime = if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time};
private _message = _data getOrDefault ["message", "none"];
private _actionId = _data getOrDefault ["actionId", "none"];
private _reason = _data getOrDefault ["reason", "none"];

diag_log format [
    "[AIC][EXEC][%1] cmd=%2 action=%3 reason=%4 msg=%5 t=%6",
    _eventType,
    _commanderName,
    _actionId,
    _reason,
    _message,
    round _missionTime
];

