#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Removes compass handler if visible upon death

    Parameter(s):
        0: UAV <OBJECT>

    Return Value:
        Nothing
*/

[QGVAR(droneKilled), []] call CBA_fnc_globalEvent;
