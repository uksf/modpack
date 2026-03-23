#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Emit commander assessment lines to RPT.

    Parameters:
        0: Event type <STRING>
        1: Commander module <OBJECT>
        2: Assessment data <HASHMAP>

    Return Value:
        None
*/

params [
    ["_eventType", "", [""]],
    ["_commander", objNull, [objNull]],
    ["_assessment", createHashMap, [createHashMap]]
];

if (_eventType isEqualTo "" || {isNull _commander}) exitWith {};

private _commanderName = vehicleVarName _commander;
if (_commanderName isEqualTo "") then {
    _commanderName = str _commander;
};

private _commanderSide = _commander getVariable [QGVAR(side), sideUnknown];
private _commanderSideLabel = [_commanderSide] call FUNC(getSideLabel);

private _missionTime = if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time};
private _objectiveRows = _assessment getOrDefault ["objectives", []];
private _urgentObjectives = _assessment getOrDefault ["urgentObjectives", []];
private _gridCellSize = _assessment getOrDefault ["gridCellSize", 500];
private _gridFrameBL = _assessment getOrDefault ["gridFrameBL", [0, 0]];
private _gridFrameTR = _assessment getOrDefault ["gridFrameTR", [0, 0]];
private _tickId = _assessment getOrDefault ["tickId", round _missionTime];

private _objectiveSummary = "none";
if (_objectiveRows isNotEqualTo []) then {
    _objectiveSummary = (_objectiveRows apply {
        _x params [
            ["_name", "OBJ", [""]],
            ["_state", "not_owned", [""]],
            ["_ownerLabel", "NONE", [""]],
            ["_poolCurrent", 0, [0]],
            ["_poolStart", 0, [0]],
            ["_priority", 0, [0]],
            ["_gridCenter", [0, 0], [[]]],
            ["_position2D", [0, 0], [[]]],
            ["_friendly", 0, [0]],
            ["_enemy", 0, [0]]
        ];
        format [
            "%1{p%2|%3|owner:%4|pool:%5/%6|pos:%7,%8|g:%9,%10|f:%11|e:%12}",
            _name,
            _priority,
            _state,
            _ownerLabel,
            _poolCurrent,
            _poolStart,
            round (_position2D#0),
            round (_position2D#1),
            _gridCenter#0,
            _gridCenter#1,
            _friendly,
            _enemy
        ]
    }) joinString "; ";
};

private _urgentSummary = if (_urgentObjectives isEqualTo []) then {"none"} else {_urgentObjectives joinString ","};

diag_log format [
    "[AIC][ASSESS][%1] cmd=%2 side=%3 tickId=%4 grid_frame{cell:%5|bl:%6,%7|tr:%8,%9} aware=%10 urgent=%11 objs=%12 t=%13",
    _eventType,
    _commanderName,
    _commanderSideLabel,
    _tickId,
    _gridCellSize,
    _gridFrameBL#0,
    _gridFrameBL#1,
    _gridFrameTR#0,
    _gridFrameTR#1,
    count _objectiveRows,
    _urgentSummary,
    _objectiveSummary,
    round _missionTime
];
