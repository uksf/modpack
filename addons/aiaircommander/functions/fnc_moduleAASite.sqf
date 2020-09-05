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
*/
(_this select 1) params ["_module"];

GVAR(aaSites) pushBack _module;
