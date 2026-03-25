#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Update commander grid-intel cell state and metadata.

    Parameters:
        0: Commander module <OBJECT>
        1: Grid coordinate [x,y] <ARRAY>
        2: State <STRING>
        3: Data <HASHMAP>

    Return Value:
        Updated cell <HASHMAP>
*/

params [
    ["_commander", objNull, [objNull]],
    ["_grid", [0, 0], [[]]],
    ["_state", "unknown", [""]],
    ["_data", createHashMap, [createHashMap]]
];

if (isNull _commander || {count _grid < 2}) exitWith {createHashMap};

private _now = if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time};
private _intelGrid = _commander getVariable [QGVAR(intelGrid), createHashMap];
if !(_intelGrid isEqualType createHashMap) then {_intelGrid = createHashMap;};

private _cellKey = format ["%1:%2", _grid#0, _grid#1];
private _cell = _intelGrid getOrDefault [_cellKey, createHashMapFromArray [
    ["grid", _grid],
    ["state", "unknown"],
    ["lastSeenAt", -1],
    ["lastUpdatedAt", -1],
    ["enemyUnits", 0],
    ["enemyGroups", 0]
]];

_cell set ["state", _state];
_cell set ["lastUpdatedAt", _now];
if (_state isEqualTo "enemy_present") then {
    _cell set ["lastSeenAt", _now];
};

if (_data getOrDefault ["enemyUnits", -1] >= 0) then {
    _cell set ["enemyUnits", _data getOrDefault ["enemyUnits", 0]];
};
if (_data getOrDefault ["enemyGroups", -1] >= 0) then {
    _cell set ["enemyGroups", _data getOrDefault ["enemyGroups", 0]];
};
if ((_data getOrDefault ["source", ""]) isNotEqualTo "") then {
    _cell set ["source", _data getOrDefault ["source", ""]];
};

_intelGrid set [_cellKey, _cell];
_commander setVariable [QGVAR(intelGrid), _intelGrid];

_cell
