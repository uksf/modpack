#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Builds a race-track (rounded-rectangle / stadium) shape as
        4 polylines: top straight, bottom straight, right cap arc,
        left cap arc. Centreline runs along local +X.

    Parameter(s):
        0: Centre position <ARRAY>
        1: Half length (centre to cap centre, metres) <NUMBER>
        2: Half width (centreline to straight edge, metres) <NUMBER>
        3: Rotation in degrees, centreline from world +X <NUMBER>

    Return Value:
        Array of 4 polylines: [topStraight, bottomStraight, rightCap, leftCap] <ARRAY>

    Example:
        [[1000, 1000, 0], 400, 100, 0] call uksf_maptools_fnc_buildRaceTrack
*/
params [
    ["_centre", [0, 0, 0], [[]]],
    ["_halfLength", 0, [0]],
    ["_halfWidth", 0, [0]],
    ["_rotationDeg", 0, [0]]
];

private _capArc = pi * _halfWidth;
private _pointsPerCap = [_capArc] call FUNC(segmentCount);

private _cosR = cos _rotationDeg;
private _sinR = sin _rotationDeg;
private _centreX = _centre#0;
private _centreY = _centre#1;

private _fnc_localToWorld = {
    params ["_localX", "_localY"];
    [
        _centreX + _localX * _cosR - _localY * _sinR,
        _centreY + _localX * _sinR + _localY * _cosR
    ]
};

private _topStraight = [];
([-_halfLength, _halfWidth] call _fnc_localToWorld) params ["_topLeftX", "_topLeftY"];
([_halfLength, _halfWidth] call _fnc_localToWorld) params ["_topRightX", "_topRightY"];
_topStraight append [_topLeftX, _topLeftY, _topRightX, _topRightY];

private _bottomStraight = [];
([-_halfLength, -_halfWidth] call _fnc_localToWorld) params ["_botLeftX", "_botLeftY"];
([_halfLength, -_halfWidth] call _fnc_localToWorld) params ["_botRightX", "_botRightY"];
_bottomStraight append [_botLeftX, _botLeftY, _botRightX, _botRightY];

private _rightCap = [];
for "_i" from 0 to _pointsPerCap do {
    private _theta = -90 + (_i * 180 / _pointsPerCap);
    private _localX = _halfLength + _halfWidth * (cos _theta);
    private _localY = _halfWidth * (sin _theta);
    ([_localX, _localY] call _fnc_localToWorld) params ["_wx", "_wy"];
    _rightCap append [_wx, _wy];
};

private _leftCap = [];
for "_i" from 0 to _pointsPerCap do {
    private _theta = 90 + (_i * 180 / _pointsPerCap);
    private _localX = -_halfLength + _halfWidth * (cos _theta);
    private _localY = _halfWidth * (sin _theta);
    ([_localX, _localY] call _fnc_localToWorld) params ["_wx", "_wy"];
    _leftCap append [_wx, _wy];
};

[_topStraight, _bottomStraight, _rightCap, _leftCap]
