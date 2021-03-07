#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Assign the route pickets their patrol routes

    Parameters:
        0: _group <GROUP>

    Return value:
        Nothing
*/

params ["_group"];

[_group, getPos (leader _group), 150, 5, "MOVE", "SAFE"] call CBA_fnc_taskPatrol;

