#include "script_component.hpp"
/*
    Author:
        Adam Bridgford

    Description:
        Adds an air spawn location to the array

    Parameters:
        0: The module object <OBJECT>

    Return value:
        Nothing

    Example:
        [_module] call uksf_aicountermortar_fnc_moduleAirSpawn
*/

(_this select 1) params ["_module"];

if (!isServer) exitWith {};

GVAR(airSpawns) pushBack _module;

