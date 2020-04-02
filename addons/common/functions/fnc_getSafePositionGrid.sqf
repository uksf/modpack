#include "script_component.hpp"
/*
    Author:
        Nicholas Clark (SENSEI), Tim Beswick

    Description:
        Get grid of safe positions (positionASL)

    Parameters:
        0: Centre position <ARRAY>
        1: Distance between positions <NUMBER>
        2: Diameter of grid <NUMBER>
        3: Minimum distance from centre to find positions <NUMBER>
        4: Minimum distance from objects <NUMBER>

    Return value:
        Array of safe positions
*/
params [["_centre", [], [[]]], ["_gridSpacing", 64, [0]], ["_distMax", 256, [0]], ["_distMin", 0, [0]], ["_distObj", 0, [0]]];

private _positions = [];
private _origin = [(_centre#0) - (_distMax * 0.5), (_centre#1) - (_distMax * 0.5)];
private _count = floor (_distMax / _gridSpacing);
private _column = [];
private _row = [];

for "_y" from 0 to _count do {
    _column = [_origin#0, (_origin#1) + (_gridSpacing * _y)];
    _positions pushBack _column;

    for "_x" from 1 to _count do {
        _row = [(_column#0) + (_gridSpacing * _x), _column#1];
        _positions pushBack _row;
    };
};

if (_distMin > 0) then {
    _positions = _positions select {!(_x inArea [_centre, _distMin, _distMin, 0, false, -1])};
};

_positions = _positions select {(_x isFlatEmpty [-1, -1, -1, 1, 2]) isEqualTo []};
// _positions = _positions select {[_x, _distObj] call FUNC(isPositionSafe)};

{
    _x set [2, ((getTerrainHeightASL _x) max 0)];
} forEach _positions;

[_positions, true] call CBA_fnc_shuffle;
_positions
