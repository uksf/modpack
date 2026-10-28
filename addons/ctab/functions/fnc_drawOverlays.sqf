#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Draws every registered app overlay on a cTab Android map.
        Runs from the map's Draw event, so it runs only while that map is visible.

    Parameter(s):
        0: Map control <CONTROL>

    Return Value:
        Nothing

    Example:
        _map ctrlAddEventHandler ["Draw", {call uksf_ctab_fnc_drawOverlays}]
*/
params ["_map"];

{
    [_map] call _x;
} forEach GVAR(overlays);
