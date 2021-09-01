#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Serialize rating area values for persistence data

    Parameter(s):
        None

    Return Value:
        Persistence data <ARRAY>
        [[Persistence ID, Values], ...]
*/

if !(isServer) exitWith {};

GVAR(ratingAreas) apply {[_x#0, _x#3]}
