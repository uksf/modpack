#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Sets the active shape-draw mode.

    Parameter(s):
        0: Mode key, one of GVAR(modes) <STRING>

    Return Value:
        None

    Example:
        ["ellipse"] call uksf_maptools_fnc_setMode
*/
params [["_mode", "circle", [""]]];

if (!(_mode in GVAR(modes))) exitWith {};

GVAR(currentMode) = _mode;
