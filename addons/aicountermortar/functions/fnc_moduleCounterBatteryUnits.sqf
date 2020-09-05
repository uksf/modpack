#include "script_component.hpp"
/*
    Author:
        Adam Bridgford

    Description:
        Adds module to add units to the counter battery array

    Parameters:
        0: The module object <OBJECT>

    Return value:
        Nothing
*/

(_this select 1) params ["_module"];

if (!isServer) exitWith {};

{
    GVAR(counterBatteryUnits) pushBack _x;
} forEach synchronizedObjects _module;
