#include "script_component.hpp"
/*
    Author:
        Nicholas Clark (SENSEI), Tim Beswick

    Description:
        Get grid of safe positions (positionASL). Candidates are generated directly inside the target shape
        so no post-filter is needed to clip to the shape: rectangle mode walks the rotated a*2 x b*2 box,
        ellipse/circle mode clamps each column's y range to the ellipse slice. Positions are filtered
        against water and optionally against a minimum radius from the centre.

    Parameters:
        0: Centre position <ARRAY>
        1: Distance between positions <NUMBER>
        2: Maximum distance (radius) from centre <NUMBER>
        3: Minimum distance (radius) from centre <NUMBER>
        4: Minimum distance from objects <NUMBER>
        5: Area array [a, b, angle, isRectangle] <ARRAY> (Optional) — when set, overrides _maxRadius bounds

    Return value:
        Array of safe positions

    Example:
        [_centre, _gridSpacing, _maxRadius, _minRadius, _distObj] call uksf_common_fnc_getSafePositionGrid
        [_centre, _gridSpacing, 0, 0, _distObj, _area] call uksf_common_fnc_getSafePositionGrid
*/
params [["_centre", [], [[]]], ["_gridSpacing", 16, [0]], ["_maxRadius", 256, [0]], ["_minRadius", 0, [0]], ["_distObj", 0, [0]], ["_area", [], [[]]]];

private _areaA = _maxRadius;
private _areaB = _maxRadius;
private _areaAngle = 0;
private _areaIsRectangle = false;
private _useArea = _area isNotEqualTo [];

if (_useArea) then {
    _area params ["_a", "_b", "_angle", "_isRectangle"];
    _areaA = _a;
    _areaB = _b;
    _areaAngle = _angle;
    _areaIsRectangle = _isRectangle;
};

private _positions = [];
private _xCount = floor ((_areaA * 2) / _gridSpacing);
private _cosAngle = cos _areaAngle;
private _sinAngle = sin _areaAngle;

for "_x" from 0 to _xCount do {
    private _localX = (_gridSpacing * _x) - _areaA;

    private _yHalf = _areaB;
    if (!_areaIsRectangle) then {
        private _normX = _localX / _areaA;
        _yHalf = _areaB * sqrt ((1 - (_normX * _normX)) max 0);
    };

    private _ySteps = floor ((_yHalf * 2) / _gridSpacing);
    for "_y" from 0 to _ySteps do {
        private _localY = (_gridSpacing * _y) - _yHalf;
        private _rotatedX = (_localX * _cosAngle) - (_localY * _sinAngle);
        private _rotatedY = (_localX * _sinAngle) + (_localY * _cosAngle);
        _positions pushBack [(_centre#0) + _rotatedX, (_centre#1) + _rotatedY];
    };
};

#ifdef DEBUG_MODE_FULL
{deleteMarker _x} forEach GVAR(debugGridPositionMarkers);
GVAR(debugGridPositionMarkers) = [];

private _marker = createMarker [str random 999999, _centre]; _marker setMarkerShape (["ELLIPSE", "RECTANGLE"] select _areaIsRectangle); _marker setMarkerBrush "Solid"; _marker setMarkerColor "ColorYellow"; _marker setMarkerAlpha 0.5; _marker setMarkerSize [_areaA, _areaB]; _marker setMarkerDir _areaAngle;
GVAR(debugGridPositionMarkers) pushBack _marker;
#endif

if (_minRadius > 0) then {
    _positions = _positions select {!(_x inArea [_centre, _minRadius, _minRadius, 0, false, -1])};

#ifdef DEBUG_MODE_FULL
    _marker = createMarker [str random 999999, _centre]; _marker setMarkerShape "ELLIPSE"; _marker setMarkerBrush "Solid"; _marker setMarkerColor "ColorBlack"; _marker setMarkerAlpha 0.25; _marker setMarkerSize [_minRadius, _minRadius];
    GVAR(debugGridPositionMarkers) pushBack _marker;
#endif
};

#ifdef DEBUG_MODE_FULL
{
    _marker = createMarker [str random 999999, _x]; _marker setMarkerShape "ICON"; _marker setMarkerType "hd_dot"; _marker setMarkerColor "ColorRed";
    GVAR(debugGridPositionMarkers) pushBack _marker;
} forEach _positions;
#endif

// Gets positions that are only not over water (isFlatEmpty returns empty array if it fails)
_positions = _positions select {(_x isFlatEmpty [-1, -1, -1, 1, 0]) isNotEqualTo []};

{
    _x set [2, ((getTerrainHeightASL _x) max 0)];

#ifdef DEBUG_MODE_FULL
    _marker = createMarker [str random 999999, _x]; _marker setMarkerShape "ICON"; _marker setMarkerType "hd_dot"; _marker setMarkerColor "ColorBlue";
    GVAR(debugGridPositionMarkers) pushBack _marker;
#endif
} forEach _positions;

[_positions, true] call CBA_fnc_shuffle;
_positions
