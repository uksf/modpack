#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Evaluate objective area state and cache snapshot.

    Parameters:
        0: Objective module <OBJECT>

    Return Value:
        Snapshot <HASHMAP>
*/

params [["_objective", objNull, [objNull]]];

if (!isServer || {isNull _objective}) exitWith {createHashMap};

private _objectiveName = _objective getVariable [QGVAR(objectiveName), "OBJ"];
private _priority = _objective getVariable [QGVAR(priority), 5];
private _position = getPosATL _objective;
private _position2D = [_position#0, _position#1];
private _area = _objective getVariable ["objectArea", [300, 300, 0, false]];
_area params [
    ["_halfWidth", 300, [0]],
    ["_halfHeight", 300, [0]],
    ["_angle", 0, [0]],
    ["_isRectangle", false, [true]]
];

private _areaDef = [_position#0, _position#1, _halfWidth, _halfHeight, _angle, _isRectangle];

private _westCount = 0;
private _eastCount = 0;
private _indCount = 0;

private _searchRadius = sqrt ((_halfWidth * _halfWidth) + (_halfHeight * _halfHeight));
private _unitsInArea = (_objective nearEntities ["CAManBase", _searchRadius]) select {
    alive _x && {((getPosATL (vehicle _x)) inArea _areaDef)}
};

{
    private _unit = _x;
    private _unitSide = side _unit;
    if !(_unitSide in [west, east, independent]) then {continue};

    switch (_unitSide) do {
        case west: {_westCount = _westCount + 1};
        case east: {_eastCount = _eastCount + 1};
        case independent: {_indCount = _indCount + 1};
    };
} forEach _unitsInArea;

private _presentSides = [];
if (_westCount > 0) then {_presentSides pushBack west};
if (_eastCount > 0) then {_presentSides pushBack east};
if (_indCount > 0) then {_presentSides pushBack independent};

private _ownerSide = _objective getVariable [QGVAR(ownerSide), sideUnknown];
private _state = "not_owned";
private _threshold = (_objective getVariable [QGVAR(contestedLosingThreshold), 2]) max 1;
private _friendlyCount = 0;
private _enemyCount = 0;

switch (count _presentSides) do {
    case 0: {
        // No units in area: preserve configured/current owner if one exists.
        if (_ownerSide isEqualTo sideUnknown) then {
            _state = "not_owned";
        } else {
            _state = "owned_secure";
        };
    };
    case 1: {
        _ownerSide = _presentSides#0;
        _state = "owned_secure";
    };
    default {
        _state = "contested";

        // Objective-owned state: evaluate losing from current owner perspective.
        if (_ownerSide isNotEqualTo sideUnknown) then {
            _friendlyCount = switch (_ownerSide) do {
                case west: {_westCount};
                case east: {_eastCount};
                case independent: {_indCount};
                default {0};
            };
            _enemyCount = (_westCount + _eastCount + _indCount) - _friendlyCount;

            if (_enemyCount > 0 && {(_friendlyCount <= 0) || {(_enemyCount / (_friendlyCount max 1)) >= _threshold}}) then {
                _state = "contested_losing";
            };
        };
    };
};

private _forcePool = _objective getVariable [QGVAR(forcePoolGroups), 0];
private _snapshot = createHashMapFromArray [
    ["objectiveName", _objectiveName],
    ["priority", _priority],
    ["position2D", _position2D],
    ["area", [_halfWidth, _halfHeight, _angle, _isRectangle]],
    ["ownerSide", _ownerSide],
    ["state", _state],
    ["forcePoolGroups", _forcePool],
    ["counts", [_westCount, _eastCount, _indCount]],
    ["ownerFriendlyCount", _friendlyCount],
    ["ownerEnemyCount", _enemyCount],
    ["timestamp", if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time}]
];

_objective setVariable [QGVAR(snapshot), _snapshot];
_objective setVariable [QGVAR(ownerSide), _ownerSide];
_objective setVariable [QGVAR(currentState), _state];

_snapshot
