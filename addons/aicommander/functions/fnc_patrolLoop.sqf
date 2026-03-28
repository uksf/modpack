#include "script_component.hpp"

/*
    Author:
        Codex

    Description:
        Patrol commander loop. Spawns patrol groups toward enemy objectives.
*/

params [["_commander", objNull, [objNull]]];

if (!isServer || {isNull _commander}) exitWith {};
if !([_commander] call FUNC(patrolCanSpawn)) exitWith {};

private _syncedObjectives = synchronizedObjects _commander select {
    !isNull _x && {
        (_x getVariable [QGVAR(isObjective), false]) || {_x isKindOf QGVAR(objectiveModule)}
    }
};
if (_syncedObjectives isEqualTo []) exitWith {};

private _commanderSide = _commander getVariable [QGVAR(side), sideUnknown];

private _enemyObjectives = _syncedObjectives select {
    private _owner = _x getVariable [QGVAR(ownerSide), sideUnknown];
    (_owner isNotEqualTo sideUnknown) && {_owner isNotEqualTo _commanderSide}
};
if (_enemyObjectives isEqualTo []) exitWith {};

private _requestedQueue = _commander getVariable [QGVAR(patrolTaskRequests), []];
private _targetObjective = objNull;

if (_requestedQueue isNotEqualTo []) then {
    private _request = _requestedQueue deleteAt 0;
    _commander setVariable [QGVAR(patrolTaskRequests), _requestedQueue];

    private _targetObjectiveName = _request getOrDefault ["targetObjectiveName", ""];
    if (_targetObjectiveName isNotEqualTo "") then {
        {
            if ((_x getVariable [QGVAR(objectiveName), ""]) isEqualTo _targetObjectiveName) exitWith {
                _targetObjective = _x;
            };
        } forEach _enemyObjectives;
    };

    if (isNull _targetObjective) then {
        private _requestPos = _request getOrDefault ["targetPosition", []];
        if (_requestPos isEqualType [] && {count _requestPos >= 2}) then {
            private _ranked = _enemyObjectives apply {[_x distance2D _requestPos, _x]};
            _ranked sort true;
            if (_ranked isNotEqualTo []) then {
                _targetObjective = (_ranked#0)#1;
            };
        };
    };
};

if (isNull _targetObjective) then {
    private _rankedByPriority = _enemyObjectives apply {[_x getVariable [QGVAR(priority), 0], _x]};
    _rankedByPriority sort false;
    if (_rankedByPriority isNotEqualTo []) then {
        _targetObjective = (_rankedByPriority#0)#1;
    };
};

if (isNull _targetObjective) exitWith {};
private _targetObjectiveName = _targetObjective getVariable [QGVAR(objectiveName), ""];
if !([_commander, _targetObjectiveName] call FUNC(patrolCanSpawn)) exitWith {};

private _stagingObjective = [_commander, _targetObjectiveName] call FUNC(findStagingObjective);
if (isNull _stagingObjective) exitWith {};

private _catalogEntry = [_commander, "patrol", format ["PATROL|%1", _targetObjectiveName]] call FUNC(selectCatalogGroup);
if (_catalogEntry isEqualTo createHashMap) exitWith {};

private _spawnResult = [_commander, _targetObjective, _stagingObjective, _catalogEntry] call FUNC(spawnPatrolTasking);
_spawnResult params ["_okPatrol", "_reasonPatrol"];

if (_okPatrol) then {
    ["PATROL", _commander, createHashMapFromArray [
        ["actionId", format ["PATROL|%1", _targetObjectiveName]],
        ["reason", "spawned"],
        ["message", format ["objective=%1", _targetObjectiveName]]
    ]] call FUNC(logExecution);
} else {
    ["PATROL", _commander, createHashMapFromArray [
        ["actionId", format ["PATROL|%1", _targetObjectiveName]],
        ["reason", _reasonPatrol],
        ["message", format ["objective=%1", _targetObjectiveName]]
    ]] call FUNC(logExecution);
};
