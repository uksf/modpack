#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Builds a circle as 4 quadrant polylines. Adjacent quadrants
        share their joining point so the circle renders without seams.

    Parameter(s):
        0: Centre position <ARRAY>
        1: Radius in metres <NUMBER>

    Return Value:
        Array of 4 polylines, each a flat [x0, y0, x1, y1, ...] array <ARRAY>

    Example:
        [getPosASL player, 250] call uksf_maptools_fnc_buildCircle
*/
params [["_centre", [0, 0, 0], [[]]], ["_radius", 0, [0]]];

private _arcLength = _radius * pi / 2;
private _pointsPerQuadrant = [_arcLength] call FUNC(segmentCount);
private _polylines = [];
private _centreX = _centre#0;
private _centreY = _centre#1;

for "_quadrant" from 0 to 3 do {
    private _polyline = [];
    private _angleStart = _quadrant * 90;
    for "_i" from 0 to _pointsPerQuadrant do {
        private _theta = _angleStart + (_i * 90 / _pointsPerQuadrant);
        _polyline append [_centreX + _radius * (cos _theta), _centreY + _radius * (sin _theta)];
    };
    _polylines pushBack _polyline;
};

_polylines
