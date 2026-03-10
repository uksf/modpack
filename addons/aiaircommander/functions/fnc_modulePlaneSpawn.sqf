#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Pushes back the module entity to the mentioned array

    Parameters:
        0: module <OBJECT>

    Return value:
        Nothing

    Example:
        [_module] call uksf_aiaircommander_fnc_modulePlaneSpawn
*/
(_this select 1) params ["_module"];

GVAR(planeSpawns) pushBack _module;
