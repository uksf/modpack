#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creates an intel ID
    Parameters:
        0: _logic <OBJECT>

    Return value:
        Nothing
*/

params ["_logic"];

private _intelID = format['intelID_%1', random 1000];

_logic setVariable [QGVAR(intelID), _intelID, true];
