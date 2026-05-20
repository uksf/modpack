#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Map control mouse move handler. Updates the live drag positions
        for the current state and rebuilds the local preview markers.

    Parameter(s):
        0: Map control <CONTROL>
        1: Mouse screen X <NUMBER>
        2: Mouse screen Y <NUMBER>

    Return Value:
        None

    Example:
        [_ctrl, 0.5, 0.5] call uksf_maptools_fnc_handleMouseMove
*/
params ["_mapControl", "_screenPosX", "_screenPosY"];

if (GVAR(state) == "idle") exitWith {};

private _mouseWorld = _mapControl ctrlMapScreenToWorld [_screenPosX, _screenPosY];

switch (GVAR(state)) do {
    case "stage1": { GVAR(stage1End) = _mouseWorld };
    case "stage2": { GVAR(stage2Pos) = _mouseWorld };
};
call FUNC(updatePreview);
