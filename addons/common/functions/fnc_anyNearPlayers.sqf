#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns true if any near players to given centre

    Parameters:
        0: Centre position <ARRAY>
        1: Radius <SCALAR>

    Return value:
        True if any players are near <BOOLEAN>
*/
params ["_centre", "_radius"];

[ALL_PLAYERS, {_x distance _centre <= _radius}] call FUNC(arrayAny)
