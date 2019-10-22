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
*/
params ["_object"];

GVAR(artillerySupportUnits) pushBackUnique _object;
