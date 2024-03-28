#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Sets the settings from the module up as global vars

    Parameters:
        0: The module object <OBJECT>

    Return value:
        Nothing
*/

(_this select 1) params ["_module"];

if (!isServer) exitWith {};

[_module] call FUNC(getValidPositions);
