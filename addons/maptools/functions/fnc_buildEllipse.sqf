#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Builds an ellipse as 4 quadrant polylines. Uses the Ramanujan
        approximation for full perimeter to size each quadrant arc,
        then samples the parametric (a*cos, b*sin) curve.

    Parameter(s):
        0: Centre position <ARRAY>
        1: Semi-major axis in metres <NUMBER>
        2: Semi-minor axis in metres <NUMBER>
        3: Rotation in degrees, semi-major axis from world +X <NUMBER>

    Return Value:
        Array of 4 polylines <ARRAY>

    Example:
        [[1000, 1000, 0], 500, 200, 30] call uksf_maptools_fnc_buildEllipse
*/
params [
    ["_centre", [0, 0, 0], [[]]],
    ["_semiMajor", 0, [0]],
    ["_semiMinor", 0, [0]],
    ["_rotationDeg", 0, [0]]
];

private _a = (abs _semiMajor) max 0.0001;
private _b = (abs _semiMinor) max 0.0001;
private _h = ((_a - _b) ^ 2) / ((_a + _b) ^ 2);
private _perimeter = pi * (_a + _b) * (1 + (3 * _h) / (10 + sqrt (4 - 3 * _h)));
private _arcLength = _perimeter / 4;
private _pointsPerQuadrant = [_arcLength] call FUNC(segmentCount);

private _cosR = cos _rotationDeg;
private _sinR = sin _rotationDeg;
private _centreX = _centre#0;
private _centreY = _centre#1;

private _polylines = [];
for "_quadrant" from 0 to 3 do {
    private _polyline = [];
    private _angleStart = _quadrant * 90;
    for "_i" from 0 to _pointsPerQuadrant do {
        private _theta = _angleStart + (_i * 90 / _pointsPerQuadrant);
        private _localX = _a * (cos _theta);
        private _localY = _b * (sin _theta);
        private _worldX = _centreX + _localX * _cosR - _localY * _sinR;
        private _worldY = _centreY + _localX * _sinR + _localY * _cosR;
        _polyline append [_worldX, _worldY];
    };
    _polylines pushBack _polyline;
};

_polylines
