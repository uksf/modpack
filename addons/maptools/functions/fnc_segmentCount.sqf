#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Picks an integer point count for a curved arc. Targets one
        segment per GVAR(segmentTargetMetres) of arc length, clamped
        to the range 8..32.

    Parameter(s):
        0: Arc length in metres <NUMBER>

    Return Value:
        Number of polyline points to sample along the arc <NUMBER>

    Example:
        [120] call uksf_maptools_fnc_segmentCount
*/
params [["_arcLengthMetres", 0, [0]]];

private _target = GVAR(segmentTargetMetres) max 1;
private _count = ceil (_arcLengthMetres / _target);
((_count max 8) min 32)
