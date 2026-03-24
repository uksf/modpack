#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Generate objective safe spawn points away from nearby structures/obstacles.

    Parameters:
        0: Objective module <OBJECT>

    Return Value:
        Safe spawn points <ARRAY>
*/

params [["_objective", objNull, [objNull]]];

if (!isServer || {isNull _objective}) exitWith {[]};

private _position = getPosATL _objective;
private _position2D = [_position#0, _position#1];
private _area = _objective getVariable ["objectArea", [300, 300, 0, false]];
_area params [
    ["_halfWidth", 300, [0]],
    ["_halfHeight", 300, [0]],
    ["_angle", 0, [0]],
    ["_isRectangle", false, [true]]
];

private _areaDef = [_position2D, _halfWidth, _halfHeight, _angle, _isRectangle];
private _maxRadius = ((_halfWidth min _halfHeight) max 80) * 0.9;
private _safePoints = [];

for "_i" from 1 to 240 do {
    if ((count _safePoints) >= 24) exitWith {};

    private _testPos = [[_position2D#0, _position2D#1, 0], random _maxRadius, random 360] call BIS_fnc_relPos;
    if !(_testPos isEqualType []) then {continue};
    if ((count _testPos) < 2) then {continue};

    private _testPos2D = [_testPos#0, _testPos#1];
    if !(_testPos2D inArea _areaDef) then {continue};
    if (surfaceIsWater _testPos2D) then {continue};

    private _nearTerrain = nearestTerrainObjects [
        _testPos2D,
        ["HOUSE", "BUILDING", "WALL", "FENCE", "ROCK", "TREE", "SMALL TREE", "BUSH"],
        12,
        false,
        true
    ];

    if (_nearTerrain isNotEqualTo []) then {continue};

    private _nearAccepted = _safePoints select {_x distance2D _testPos2D < 20};
    if (_nearAccepted isNotEqualTo []) then {continue};

    _safePoints pushBack _testPos2D;
};

_objective setVariable [QGVAR(safeSpawnPoints), _safePoints, true];
_objective setVariable [QGVAR(safeSpawnUpdatedAt), if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time}];

_safePoints
