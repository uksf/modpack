#include "script_component.hpp"
/*
    Author:
        Nicholas Clark (SENSEI), Tim Beswick

    Description:
        Get grid of safe positions (positionASL)

    Parameters:
        0: Centre position <ARRAY>
        1: Distance between positions <NUMBER>
        2: Maximum distance (radius) from centre <NUMBER>
        3: Minimum distance (radius) from centre <NUMBER>
        4: Minimum distance from objects <NUMBER>

    Return value:
        Array of safe positions
*/
params [["_centre", [], [[]]], ["_gridSpacing", 16, [0]], ["_maxRadius", 256, [0]], ["_minRadius", 0, [0]], ["_distObj", 0, [0]]];

private _positions = [];
private _origin = [(_centre#0) - _maxRadius, (_centre#1) - _maxRadius];
private _count = floor ((_maxRadius * 2) / _gridSpacing);
private _column = [];
private _row = [];

#ifdef DEBUG_MODE_FULL
{deleteMarker _x} forEach GVAR(debugGridPositionMarkers);
GVAR(debugGridPositionMarkers) = [];

private _marker = createMarker [str random 999999, _centre]; _marker setMarkerShape "ELLIPSE"; _marker setMarkerBrush "Solid"; _marker setMarkerColor "ColorYellow"; _marker setMarkerAlpha 0.5; _marker setMarkerSize [_maxRadius, _maxRadius];
GVAR(debugGridPositionMarkers) pushBack _marker;
#endif

for "_y" from 0 to _count do {
    _column = [_origin#0, (_origin#1) + (_gridSpacing * _y)];
    _positions pushBack _column;

    for "_x" from 1 to _count do {
        _row = [(_column#0) + (_gridSpacing * _x), _column#1];
        _positions pushBack _row;
    };
};

if (_minRadius > 0) then {
    _positions = _positions select {!(_x inArea [_centre, _minRadius, _minRadius, 0, false, -1])};

#ifdef DEBUG_MODE_FULL
    _marker = createMarker [str random 999999, _centre]; _marker setMarkerShape "ELLIPSE"; _marker setMarkerBrush "Solid"; _marker setMarkerColor "ColorBlack"; _marker setMarkerAlpha 0.25; _marker setMarkerSize [_minRadius, _minRadius];
    GVAR(debugGridPositionMarkers) pushBack _marker;
#endif
};

_positions = _positions select {_x inArea [_centre, _maxRadius, _maxRadius, 0, false, -1]};

#ifdef DEBUG_MODE_FULL
// {
    _marker = createMarker [str random 999999, _x]; _marker setMarkerShape "ICON"; _marker setMarkerType "hd_dot"; _marker setMarkerColor "ColorRed";
    GVAR(debugGridPositionMarkers) pushBack _marker;
} forEach _positions;
#endif

// Gets positions that are only not over water (isFlatEmpty returns emp;ty array if it fails)
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
