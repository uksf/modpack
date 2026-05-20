#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Builds a cone as 3 polylines: top side, bottom side, and a
        far arc between the two side endpoints. Apex at origin, axis
        along local +X with given length, half-angle controls spread.

    Parameter(s):
        0: Apex position <ARRAY>
        1: Axis length in metres <NUMBER>
        2: Half angle in degrees <NUMBER>
        3: Rotation in degrees, axis from world +X <NUMBER>

    Return Value:
        Array of 3 polylines: [topSide, bottomSide, farArc] <ARRAY>

    Example:
        [[1000, 1000, 0], 800, 20, 45] call uksf_maptools_fnc_buildCone
*/
params [
    ["_apex", [0, 0, 0], [[]]],
    ["_axisLen", 0, [0]],
    ["_halfAngleDeg", 0, [0]],
    ["_rotationDeg", 0, [0]]
];

private _arcLength = abs (_axisLen * (_halfAngleDeg * 2 * pi / 180));
private _pointsOnArc = [_arcLength] call FUNC(segmentCount);

private _cosR = cos _rotationDeg;
private _sinR = sin _rotationDeg;
private _apexX = _apex#0;
private _apexY = _apex#1;

private _fnc_localToWorld = {
    params ["_localX", "_localY"];
    [
        _apexX + _localX * _cosR - _localY * _sinR,
        _apexY + _localX * _sinR + _localY * _cosR
    ]
};

private _topEndLocal = [_axisLen * (cos _halfAngleDeg), _axisLen * (sin _halfAngleDeg)];
private _botEndLocal = [_axisLen * (cos -_halfAngleDeg), _axisLen * (sin -_halfAngleDeg)];

(_topEndLocal call _fnc_localToWorld) params ["_topEndX", "_topEndY"];
(_botEndLocal call _fnc_localToWorld) params ["_botEndX", "_botEndY"];

private _topSide = [_apexX, _apexY, _topEndX, _topEndY];
private _botSide = [_apexX, _apexY, _botEndX, _botEndY];

private _farArc = [];
for "_i" from 0 to _pointsOnArc do {
    private _theta = -_halfAngleDeg + (_i * 2 * _halfAngleDeg / _pointsOnArc);
    private _localX = _axisLen * (cos _theta);
    private _localY = _axisLen * (sin _theta);
    ([_localX, _localY] call _fnc_localToWorld) params ["_wx", "_wy"];
    _farArc append [_wx, _wy];
};

[_topSide, _botSide, _farArc]
