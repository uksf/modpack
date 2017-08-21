/*
    Author:
        Tim Beswick

    Description:
        Checks if work on vehicle is possible.

    Parameter(s):
        0: Vehicle <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_veh"];

(alive player) && (player == (vehicle player)) && ((vectorMagnitudeSqr (velocity _veh)) < 1) && ((vectorMagnitudeSqr (velocity player)) < 1)
