#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds module to add units to the counter battery array

    Parameters:
        0: The module object <OBJECT>

    Return value:
        Nothing
*/

params ["_module"];

if (!(local _module)) exitWith {};

{
    GVAR(counterBatteryUnits) pushBack [_x];
} forEach synchronizedObjects _module;
