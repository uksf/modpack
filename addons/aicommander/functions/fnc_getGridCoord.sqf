#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Convert 2D world position to commander grid coordinates.

    Parameters:
        0: Position2D <ARRAY>
        1: Cell size <NUMBER>

    Return Value:
        Grid coordinate [x,y] <ARRAY>
*/

params [
    ["_position2D", [0, 0], [[]]],
    ["_cellSize", 500, [0]]
];

private _cell = (_cellSize max 1);

[
    floor ((_position2D#0) / _cell),
    floor ((_position2D#1) / _cell)
];
