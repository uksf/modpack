#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets near players to given centre

    Parameters:
        0: Centre position <ARRAY>
        1: Radius <SCALAR>

    Return value:
        Players within radius from center <ARRAY>

    Example:
        [_centre, _radius] call uksf_common_fnc_getNearPlayers
*/
params ["_centre", "_radius"];

ALL_PLAYERS select {(_x distance _centre) <= _radius}
