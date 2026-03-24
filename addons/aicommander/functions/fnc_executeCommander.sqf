#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Translate decision output into per-commander action requests and queue entries.

    Parameters:
        0: Commander module <OBJECT>
        1: Assessment <HASHMAP>
        2: Decision <HASHMAP>

    Return Value:
        None
*/

params [
    ["_commander", objNull, [objNull]],
    ["_assessment", createHashMap, [createHashMap]],
    ["_decision", createHashMap, [createHashMap]]
];

if (!isServer || {isNull _commander}) exitWith {};

private _managedGroups = [_commander] call FUNC(refreshManagedGroups);
private _managedCount = count _managedGroups;
private _managedCap = (_commander getVariable [QGVAR(managedGroupsCap), 9]) max 1;
private _queue = _commander getVariable [QGVAR(spawnQueue), []];

private _activeActions = _decision getOrDefault ["activeActions", []];
private _slotCap = ((_commander getVariable [QGVAR(maxConcurrentActions), 3]) max 1) min 3;
private _waveLimit = ((_commander getVariable [QGVAR(maxWave), 3]) max 1) min 3;

private _requests = [];
{
    if (_forEachIndex >= _slotCap) then {continue};

    _x params [
        ["_objName", "", [""]],
        ["_actionType", "hold", [""]],
        ["_score", 0, [0]]
    ];

    if (_objName isEqualTo "" || {_actionType isEqualTo "hold"}) then {continue};

    private _request = createHashMapFromArray [
        ["actionId", format ["%1|%2", _objName, _actionType]],
        ["actionType", _actionType],
        ["targetObjectiveName", _objName],
        ["priority", round _score],
        ["desiredGroups", _waveLimit],
        ["waveSize", _waveLimit],
        ["source", "internal_assess"]
    ];

    private _submitResult = [_commander, _request] call FUNC(submitCommanderAction);
    if (_submitResult#0) then {
        _requests pushBack (_submitResult#1);
    };
} forEach _activeActions;

_commander setVariable [QGVAR(actionRequests), _requests];

private _activeActionIds = _requests apply {_x getOrDefault ["actionId", ""]};
if (_activeActionIds isNotEqualTo []) then {
    _queue = _queue select {(_x getOrDefault ["actionId", ""]) in _activeActionIds};
} else {
    _queue = [];
};

private _availableGlobal = (_managedCap - _managedCount - (count _queue)) max 0;
if (_availableGlobal <= 0) exitWith {
    _commander setVariable [QGVAR(spawnQueue), _queue];
};

{
    if (_availableGlobal <= 0) then {continue};

    private _actionId = _x getOrDefault ["actionId", ""];
    private _desiredGroups = _x getOrDefault ["desiredGroups", 1];
    if (_actionId isEqualTo "") then {continue};

    private _alreadyManaged = {
        (_x getOrDefault ["actionId", ""]) isEqualTo _actionId
    } count _managedGroups;

    private _alreadyQueued = {
        (_x getOrDefault ["actionId", ""]) isEqualTo _actionId
    } count _queue;

    private _needed = (_desiredGroups - _alreadyManaged - _alreadyQueued) max 0;
    if (_needed <= 0) then {continue};

    private _allocate = _needed min _availableGlobal;
    for "_i" from 1 to _allocate do {
        _queue pushBack (createHashMapFromArray [
            ["actionId", _actionId],
            ["actionType", _x getOrDefault ["actionType", "reinforce"]],
            ["targetObjectiveName", _x getOrDefault ["targetObjectiveName", ""]],
            ["priority", _x getOrDefault ["priority", 0]],
            ["waveIndex", 1 + floor (((_alreadyQueued + _i) - 1) / ((_x getOrDefault ["waveSize", 1]) max 1))]
        ]);
    };

    _availableGlobal = _availableGlobal - _allocate;
} forEach _requests;

_commander setVariable [QGVAR(spawnQueue), _queue];
