#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Advances the active shape-draw mode to the next entry in
        GVAR(modes), wrapping around.

    Parameter(s):
        None

    Return Value:
        New mode key <STRING>

    Example:
        call uksf_maptools_fnc_cycleMode
*/
private _index = GVAR(modes) find GVAR(currentMode);
private _next = GVAR(modes) select ((_index + 1) mod (count GVAR(modes)));
[_next] call FUNC(setMode);
_next
