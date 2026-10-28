#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the Elevation map for the current observer, eye height, and radius, and stops any earlier calculation.
        The radius is split into a grid of square cells. Each cell is tested once, a share of the cells per frame, so the frame rate holds.
        A cell is visible when no terrain blocks the line from the observer's eye to a standing man at the cell centre.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_ctab_fnc_elevationCalculate
*/
[GVAR(elevationJob)] call CBA_fnc_removePerFrameHandler;
GVAR(elevationCells) = [];
GVAR(elevationPending) = [];

if (GVAR(elevationObserver) isEqualTo []) exitWith {
    call FUNC(elevationRefresh);
};

GVAR(elevationObserver) params ["_observerX", "_observerY"];
private _radius = GVAR(elevationRadius);
private _cell = 2 * _radius / ELEVATION_CELLS;
GVAR(elevationCellSize) = _cell;

for "_column" from 0 to ELEVATION_CELLS - 1 do {
    for "_row" from 0 to ELEVATION_CELLS - 1 do {
        private _centre = [_observerX - _radius + (_column + 0.5) * _cell, _observerY - _radius + (_row + 0.5) * _cell];
        if (_centre distance2D [_observerX, _observerY] <= _radius) then {
            GVAR(elevationPending) pushBack _centre;
        };
    };
};

private _ground = getTerrainHeightASL [_observerX, _observerY];
private _eye = [_observerX, _observerY, _ground + GVAR(elevationEye)];
GVAR(elevationGround) = _ground;
GVAR(elevationTotal) = count GVAR(elevationPending);

GVAR(elevationJob) = [{
    params ["_eye", "_handle"];

    for "_i" from 1 to (ELEVATION_CELLS_PER_FRAME min count GVAR(elevationPending)) do {
        private _centre = GVAR(elevationPending) deleteAt (count GVAR(elevationPending) - 1);
        private _height = getTerrainHeightASL _centre;
        private _target = _centre + [_height + ELEVATION_TARGET_HEIGHT];
        GVAR(elevationCells) pushBack [_centre, !terrainIntersectASL [_eye, _target], _height - GVAR(elevationGround)];
    };

    if (GVAR(elevationPending) isEqualTo []) then {
        [_handle] call CBA_fnc_removePerFrameHandler;
        GVAR(elevationJob) = -1;
    };
    call FUNC(elevationRefresh);
}, 0, _eye] call CBA_fnc_addPerFrameHandler;
