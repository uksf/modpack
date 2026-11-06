#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Draws the position chosen in the Markers app editor while the app is open.

    Parameter(s):
        0: Map control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_map] call uksf_ctab_fnc_markersDraw
*/
params ["_map"];

if (GVAR(currentApp) != "markers" || {GVAR(markerPoint) isEqualTo []}) exitWith {};

_map drawIcon ["\A3\ui_f\data\map\markers\military\pickup_ca.paa", COLOUR_ROUTE, GVAR(markerPoint), 24, 24, 0, "", 0, 0.05, "RobotoCondensedBold", "right"];
