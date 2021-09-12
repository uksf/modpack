#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Serialize rating area for persistence

    Parameter(s):
        None

    Return Value:
        Serialized data <ARRAY>
        [[ID, Values], ...]
*/

if !(isServer) exitWith {};

GVAR(ratingAreas) apply {[_x#0, _x#4]}
