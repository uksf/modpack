#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Formats the current surface wind as its speed and the bearing it blows from.

    Parameter(s):
        None

    Return Value:
        Wind text <STRING>

    Example:
        call uksf_ctab_fnc_formatWind
*/
wind params ["_east", "_north"];

format ["Wind: %1 m/s from %2", (vectorMagnitude [_east, _north]) toFixed 1, round ((((-_east) atan2 (-_north)) + 360) mod 360)]
