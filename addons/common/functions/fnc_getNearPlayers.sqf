#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets near players

    Parameters:
        0: Center position <ARRAY>
        1: Radius <SCALAR>

    Return value:
        Players within radius from center <ARRAY>
*/

params ["_pos", "_radius"];
private _players = [];

{
    if (_x distance _pos <= _radius) then {
        _players pushBack _x;
    };
} forEach allPlayers;

_players
