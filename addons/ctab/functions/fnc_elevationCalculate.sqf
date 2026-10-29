#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the Elevation map for the current observer, eye height, and radius, and stops any earlier calculation.
        The radius is split into a grid of square cells. Each cell is tested once, a share of the cells per frame, so the frame rate holds.
        A cell is visible when no terrain blocks the line from the observer's eye to a standing man at the cell centre.
        Each cell keeps its height colour, and the visible count and highest ground are kept as cells finish, so drawing and the panel do no per-cell work.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_ctab_fnc_elevationCalculate
*/
[GVAR(elevationJob)] call CBA_fnc_removePerFrameHandler;
GVAR(elevationJob) = -1;
GVAR(elevationCells) = [];
GVAR(elevationPending) = [];
GVAR(elevationVisible) = 0;
GVAR(elevationHighest) = -1e6;

if (GVAR(elevationObserver) isEqualTo []) exitWith {
    GVAR(elevationTotal) = 0;
    call FUNC(elevationRefresh);
};

GVAR(elevationObserver) params ["_observerX", "_observerY"];
private _radius = GVAR(elevationRadius);
private _cell = 2 * _radius / ELEVATION_CELLS;
GVAR(elevationCellHalf) = _cell / 2;

for "_column" from 0 to ELEVATION_CELLS - 1 do {
    for "_row" from 0 to ELEVATION_CELLS - 1 do {
        private _centre = [_observerX - _radius + (_column + 0.5) * _cell, _observerY - _radius + (_row + 0.5) * _cell];
        if (_centre distance2D [_observerX, _observerY] <= _radius) then {
            GVAR(elevationPending) pushBack _centre;
        };
    };
};

private _ground = getTerrainHeightASL [_observerX, _observerY];
GVAR(elevationGround) = _ground;
GVAR(elevationTotal) = count GVAR(elevationPending);

GVAR(elevationJob) = [{
    params ["_eye", "_handle"];

    for "_i" from 1 to (ELEVATION_CELLS_PER_FRAME min count GVAR(elevationPending)) do {
        private _centre = GVAR(elevationPending) deleteAt (count GVAR(elevationPending) - 1);
        private _height = getTerrainHeightASL _centre;
        private _visible = !terrainIntersectASL [_eye, _centre + [_height + ELEVATION_TARGET_HEIGHT]];
        private _difference = _height - GVAR(elevationGround);
        private _strength = 0.6 min (abs _difference / ELEVATION_FULL_COLOUR_HEIGHT);
        private _colour = [[0, 0.3, 1, _strength], [1, 0, 0, _strength]] select (_difference > 0);

        GVAR(elevationCells) pushBack [_centre, _visible, _colour];
        if (_visible) then {
            GVAR(elevationVisible) = GVAR(elevationVisible) + 1;
        };
        GVAR(elevationHighest) = GVAR(elevationHighest) max _difference;
    };

    if (GVAR(elevationPending) isEqualTo []) then {
        [_handle] call CBA_fnc_removePerFrameHandler;
        GVAR(elevationJob) = -1;
    };
    call FUNC(elevationRefresh);
}, 0, [_observerX, _observerY, _ground + GVAR(elevationEye)]] call CBA_fnc_addPerFrameHandler;
