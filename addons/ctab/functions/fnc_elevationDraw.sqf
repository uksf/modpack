#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Draws the Elevation map on a cTab map while the Elevation app is open.
        In visible mode, ground the observer can see is green. In height mode, ground above the observer is red and ground below is blue, stronger with the difference.

    Parameter(s):
        0: Map control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_map] call uksf_ctab_fnc_elevationDraw
*/
params ["_map"];

if (GVAR(currentApp) != "elevation" || {GVAR(elevationObserver) isEqualTo []}) exitWith {};

private _half = GVAR(elevationCellHalf);
if (GVAR(elevationMode) == "visible") then {
    {
        _x params ["_centre", "_visible"];
        if (_visible) then {
            _map drawRectangle [_centre, _half, _half, 0, COLOUR_VISIBLE, FILL_SOLID];
        };
    } forEach GVAR(elevationCells);
} else {
    {
        _x params ["_centre", "", "_colour"];
        _map drawRectangle [_centre, _half, _half, 0, _colour, FILL_SOLID];
    } forEach GVAR(elevationCells);
};

_map drawEllipse [GVAR(elevationObserver), GVAR(elevationRadius), GVAR(elevationRadius), 0, [1, 1, 1, 1], ""];
_map drawIcon [ICON_MAN, [1, 1, 1, 1], GVAR(elevationObserver), 24, 24, 0, "", 2];
