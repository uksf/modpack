#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Build commander objective picture and emit change-driven logs.

    Parameters:
        0: Commander module <OBJECT>

    Return Value:
        None
*/

params [["_commander", objNull, [objNull]]];

if (!isServer || {isNull _commander}) exitWith {};

private _commanderSide = _commander getVariable [QGVAR(side), sideUnknown];
private _gridCellSize = _commander getVariable [QGVAR(gridCellSize), 500];
private _frameBottomLeft = [0, 0];
private _frameTopRight = [floor (worldSize / (_gridCellSize max 1)), floor (worldSize / (_gridCellSize max 1))];

private _syncedObjectives = synchronizedObjects _commander select {
    !isNull _x && {
        (_x getVariable [QGVAR(isObjective), false]) || {_x isKindOf QGVAR(objectiveModule)}
    }
};

private _debugAssessments = [];
private _objectiveRows = [];
private _urgentObjectives = [];

{
    private _objective = _x;
    private _snapshot = _objective getVariable [QGVAR(snapshot), createHashMap];
    if !(_snapshot isEqualType createHashMap) then {continue};

    private _objectiveName = _snapshot getOrDefault ["objectiveName", "FALLBACK-OBJ-NAME"];
    private _priority = _snapshot getOrDefault ["priority", _objective getVariable [QGVAR(priority), 5]];
    private _position2D = _snapshot getOrDefault ["position2D", [0, 0]];
    private _ownerSide = _snapshot getOrDefault ["ownerSide", sideUnknown];
    private _ownerLabel = [_ownerSide] call FUNC(getSideLabel);
    private _baseState = _snapshot getOrDefault ["state", "not_owned"];
    private _counts = _snapshot getOrDefault ["counts", [0, 0, 0]];
    _counts params [
        ["_westCount", 0, [0]],
        ["_eastCount", 0, [0]],
        ["_indCount", 0, [0]]
    ];

    private _friendlyCount = switch (_commanderSide) do {
        case west: {_westCount};
        case east: {_eastCount};
        case independent: {_indCount};
        default {0};
    };

    private _enemyCount = (_westCount + _eastCount + _indCount) - _friendlyCount;
    private _state = _baseState;

    // Commander-relative state view.
    if (_baseState isEqualTo "owned_secure") then {
        if (_ownerSide isEqualTo sideUnknown) then {
            _state = "not_owned";
        } else {
            if (_ownerSide isNotEqualTo _commanderSide) then {
                _state = "enemy_owned";
            };
        };
    };

    if (_baseState isEqualTo "contested_losing" && {_ownerSide isNotEqualTo _commanderSide}) then {
        _state = "contested";
    };

    private _grid = [_position2D, _gridCellSize] call FUNC(getGridCoord);
    private _forcePoolCurrent = _objective getVariable [QGVAR(forcePoolGroups), _snapshot getOrDefault ["forcePoolGroups", 0]];
    private _forcePoolStart = _objective getVariable [QGVAR(forcePoolStartGroups), _forcePoolCurrent];

    _objectiveRows pushBack [
        _objectiveName,
        _state,
        _ownerLabel,
        _forcePoolCurrent,
        _forcePoolStart,
        _priority,
        _grid,
        _position2D,
        _friendlyCount,
        _enemyCount
    ];

    _debugAssessments pushBack [
        _objectiveName,
        _position2D,
        _grid,
        _ownerLabel,
        _state,
        _forcePoolCurrent,
        _friendlyCount,
        _enemyCount
    ];

    if (_baseState isEqualTo "contested_losing" && {_ownerSide isEqualTo _commanderSide}) then {
        _urgentObjectives pushBack _objectiveName;
    };
} forEach _syncedObjectives;

_commander setVariable [QGVAR(debugAssessments), _debugAssessments];

private _assessment = createHashMapFromArray [
    ["objectives", _objectiveRows],
    ["urgentObjectives", _urgentObjectives],
    ["gridCellSize", _gridCellSize],
    ["gridFrameBL", _frameBottomLeft],
    ["gridFrameTR", _frameTopRight]
];

["ASSESS", _commander, _assessment] call FUNC(logAssessment);
if (_urgentObjectives isNotEqualTo []) then {
    ["CONTACT_URGENT", _commander, _assessment] call FUNC(logAssessment);
};
