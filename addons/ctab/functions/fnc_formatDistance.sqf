#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Formats a distance in metres, in kilometres from 1 km.

    Parameter(s):
        0: Distance in metres <NUMBER>

    Return Value:
        Distance text <STRING>

    Example:
        1234 call uksf_ctab_fnc_formatDistance
*/
params ["_distance"];

if (_distance < 1000) exitWith {format ["%1 m", round _distance]};
format ["%1 km", (_distance / 1000) toFixed 1]
