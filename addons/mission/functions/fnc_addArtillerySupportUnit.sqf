#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds an object to be considered for artillery support

    Parameters:
        0: Object <OBJECT>

    Return value:
        Nothing

    Example:
        [_object] call uksf_mission_fnc_addArtillerySupportUnit
*/
params ["_object"];

GVAR(artillerySupportUnits) pushBackUnique _object;
