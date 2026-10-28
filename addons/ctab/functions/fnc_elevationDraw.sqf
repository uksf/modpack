#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Draws the Elevation map on a cTab map.
        In visible mode, ground the observer can see is green. In height mode, ground above the observer is red and ground below is blue, stronger with the difference.

    Parameter(s):
        0: Map control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_map] call uksf_ctab_fnc_elevationDraw
*/
params ["_map"];

if (GVAR(elevationObserver) isEqualTo []) exitWith {};

private _half = GVAR(elevationCellSize) / 2;
if (GVAR(elevationMode) == "visible") then {
    {
        _x params ["_centre", "_visible"];
        if (_visible) then {
            _map drawRectangle [_centre, _half, _half, 0, [0, 1, 0, 0.35], FILL_SOLID];
        };
    } forEach GVAR(elevationCells);
} else {
    {
        _x params ["_centre", "", "_difference"];
        private _strength = 0.6 min (abs _difference / ELEVATION_FULL_COLOUR_HEIGHT);
        private _colour = [[0, 0.3, 1, _strength], [1, 0, 0, _strength]] select (_difference > 0);
        _map drawRectangle [_centre, _half, _half, 0, _colour, FILL_SOLID];
    } forEach GVAR(elevationCells);
};

_map drawEllipse [GVAR(elevationObserver), GVAR(elevationRadius), GVAR(elevationRadius), 0, [1, 1, 1, 1], ""];
_map drawIcon [ICON_MAN, [1, 1, 1, 1], GVAR(elevationObserver), 24, 24, 0, "", 2];
