#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Draws every registered app overlay on a cTab Android map, or only the plan overlays on the small display.
        Runs from the map's Draw event, so it runs only while that map is visible.

    Parameter(s):
        0: Map control <CONTROL>
        1: Small display <BOOL> (default: false)

    Return Value:
        Nothing

    Example:
        _map ctrlAddEventHandler ["Draw", {call uksf_ctab_fnc_drawOverlays}]
*/
params ["_map", ["_mini", false]];

{
    [_map, _mini] call _x;
} forEach ([GVAR(overlays), GVAR(miniOverlays)] select _mini);
