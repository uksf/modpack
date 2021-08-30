#include "script_component.hpp"

/*
    Author:
        Nicholas Clark (SENSEI)

    Description:
        find positionAGL at roadside

    Parameters:
        0: road <OBJECT>
        1: offset distance from roadside <NUMBER>

    Return value:
        position
*/
params [["_road", objNull, [objNull]], ["_offset", 0, [0]]];

private _info = getRoadInfo _road;
private _dir = (_info#6) getDir (_info#7);
_dir = _dir + (180 * round (random 1));

private _position = _road getRelPos [((_info#1) * 0.5) + _offset, _dir + 90];

[_position, _dir]
