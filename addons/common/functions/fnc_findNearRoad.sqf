#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Find the nearest road from a position
        Will shuffle road objects before selcting the first in the returned list

    Parameters:
        0: Position <ARRAY>

    Return value:
        Road <OBJECT>
*/
params ["_position"];

private _roads = [];
{
    _roads = _position nearRoads _x;
    if (_roads isNotEqualTo []) exitWith {};
} forEach [50, 100, 250, 500, 750, 1000, 1500, 2000];

if (_roads isEqualTo []) exitWith {objNull};

[_roads, true] call CBA_fnc_shuffle;
_roads#0
