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

[_commander] call FUNC(refreshManagedGroups);
private _managedGroups = _commander getVariable [QGVAR(managedGroups), []];
private _managedGroupsCurrent = count _managedGroups;
private _managedGroupsCap = _commander getVariable [QGVAR(managedGroupsCap), 9];
private _spawnQueueDepth = count (_commander getVariable [QGVAR(spawnQueue), []]);

// Decision logic: rank objectives by state and priority, then pick top N to act on.

private _maxConcurrentActions = (_commander getVariable [QGVAR(maxConcurrentActions), 3]) max 1;
private _rankedActions = [];
{
    _x params [
        ["_objName", "OBJ", [""]],
        ["_state", "not_owned", [""]],
        ["_ownerLabel", "NONE", [""]],
        ["_poolCurrent", 0, [0]],
        ["_poolStart", 0, [0]],
        ["_priority", 0, [0]]
    ];

    private _action = "hold";
    private _score = 10 + (_priority * 2);
    private _reason = "steady";

    switch (_state) do {
        case "contested_losing": {
            _action = "reinforce";
            _score = 100 + (_priority * 10);
            _reason = "urgent_contested_losing";
        };
        case "contested": {
            _action = "reinforce";
            _score = 80 + (_priority * 8);
            _reason = "contested_pressure";
        };
        case "not_owned": {
            _action = "defend";
            _score = 50 + (_priority * 5);
            _reason = "maintain_control";
        };
        case "enemy_owned": {
            _action = "attack";
            _score = 60 + (_priority * 6);
            _reason = "recover_objective";
        };
        case "owned_secure": {
            _action = "recon";
            _score = 30 + (_priority * 4);
            _reason = "build_intel";
        };
        default {
            _action = "hold";
            _score = 10 + (_priority * 2);
            _reason = "default_hold";
        };
    };

    if (_poolCurrent < 2 && {_action in ["attack", "flank_left", "flank_right"]}) then {
        _action = "recon";
        _score = _score - 20;
        _reason = "pool_guard";
    };

    _rankedActions pushBack [_objName, _action, _score, _reason];
} forEach _objectiveRows;

private _sortedActions = +_rankedActions;
_sortedActions = [_sortedActions, [], {_x#2}, "DESCEND"] call BIS_fnc_sortBy;

private _activeActions = [];
{
    if (_forEachIndex < _maxConcurrentActions) then {
        _activeActions pushBack _x;
    };
} forEach _sortedActions;

private _decisionState = if (_activeActions isEqualTo []) then {"observe"} else {(_activeActions#0)#1};
private _tickId = round (if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time});

private _assessment = createHashMapFromArray [
    ["objectives", _objectiveRows],
    ["urgentObjectives", _urgentObjectives],
    ["gridCellSize", _gridCellSize],
    ["gridFrameBL", _frameBottomLeft],
    ["gridFrameTR", _frameTopRight],
    ["managedGroupsCurrent", _managedGroupsCurrent],
    ["managedGroupsCap", _managedGroupsCap],
    ["spawnQueueDepth", _spawnQueueDepth],
    ["tickId", _tickId]
];

private _decision = createHashMapFromArray [
    ["slotsMax", _maxConcurrentActions],
    ["slotsUsed", count _activeActions],
    ["decisionState", _decisionState],
    ["activeActions", _activeActions],
    ["preemptedActions", []],
    ["urgentInputs", _urgentObjectives],
    ["why", "deterministic_state_projection_v1"],
    ["tickId", _tickId]
];

["ASSESS", _commander, _assessment] call FUNC(logAssessment);
["TICK", _commander, _decision] call FUNC(logDecision);
[_commander, _assessment, _decision] call FUNC(executeCommander);
