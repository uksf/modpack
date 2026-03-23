#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Emit commander decision line to RPT.

    Parameters:
        0: Event type <STRING>
        1: Commander module <OBJECT>
        2: Decision data <HASHMAP>

    Return Value:
        None
*/

params [
    ["_eventType", "", [""]],
    ["_commander", objNull, [objNull]],
    ["_decision", createHashMap, [createHashMap]]
];

if (_eventType isEqualTo "" || {isNull _commander}) exitWith {};

private _commanderName = vehicleVarName _commander;
if (_commanderName isEqualTo "") then {
    _commanderName = str _commander;
};

private _commanderSide = _commander getVariable [QGVAR(side), sideUnknown];
private _commanderSideLabel = [_commanderSide] call FUNC(getSideLabel);
private _missionTime = if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time};

private _slotsMax = _decision getOrDefault ["slotsMax", 0];
private _slotsUsed = _decision getOrDefault ["slotsUsed", 0];
private _decisionState = _decision getOrDefault ["decisionState", "none"];
private _activeActions = _decision getOrDefault ["activeActions", []];
private _preemptedActions = _decision getOrDefault ["preemptedActions", []];
private _urgentInputs = _decision getOrDefault ["urgentInputs", []];
private _why = _decision getOrDefault ["why", "none"];
private _tickId = _decision getOrDefault ["tickId", round _missionTime];

private _activeSummary = "none";
if (_activeActions isNotEqualTo []) then {
    _activeSummary = (_activeActions apply {
        _x params [
            ["_objName", "OBJ", [""]],
            ["_action", "hold", [""]],
            ["_score", 0, [0]],
            ["_reason", "none", [""]]
        ];
        format ["%1{%2|score:%3|reason:%4}", _objName, _action, round _score, _reason]
    }) joinString "; ";
};

private _preemptedSummary = if (_preemptedActions isEqualTo []) then {"none"} else {_preemptedActions joinString ","};
private _urgentSummary = if (_urgentInputs isEqualTo []) then {"none"} else {_urgentInputs joinString ","};

diag_log format [
    "[AIC][DECIDE][%1] cmd=%2 side=%3 tickId=%4 slots{max:%5|used:%6} decision_state=%7 active_actions=%8 preempted_actions=%9 urgent_inputs=%10 why=%11 t=%12",
    _eventType,
    _commanderName,
    _commanderSideLabel,
    _tickId,
    _slotsMax,
    _slotsUsed,
    _decisionState,
    _activeSummary,
    _preemptedSummary,
    _urgentSummary,
    _why,
    round _missionTime
];
