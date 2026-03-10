#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Phase 1 overhead path tracing. Finds the obstruction between detonation
        and target using lineIntersectsSurfaces, then generates tightly-spaced
        sample points just above the obstruction. Designed for low cover only
        (sandbags, trenches, low walls) — not for arcing over buildings.

    Parameter(s):
        0: Detonation position ASL <ARRAY>
        1: Target position ASL <ARRAY>
        2: Target object <OBJECT>
        3: Parent vehicle to exclude from LOS checks <OBJECT> (default objNull)

    Return Value:
        [] if no path found, or [totalPathLength, samplePoint] for the best path

    Example:
        [_detonationPositionASL, _targetPositionASL, _target, _parentVehicle] call uksf_blastoverpressure_fnc_traceOverhead
*/
params ["_detonationPositionASL", "_targetPositionASL", "_target", ["_parentVehicle", objNull]];

// Find the obstruction point on the direct path
private _intersections = lineIntersectsSurfaces [_detonationPositionASL, _targetPositionASL, _target, _parentVehicle, true, 1, "GEOM", "NONE"];

private _obstructionPositionASL = [];
if (_intersections isNotEqualTo []) then {
    _obstructionPositionASL = (_intersections#0)#0;
} else {
    // No surface hit — terrain is blocking. Use terrain height at midpoint + 1m
    private _midpoint = (_detonationPositionASL vectorAdd _targetPositionASL) vectorMultiply 0.5;
    private _terrainHeight = getTerrainHeightASL [_midpoint#0, _midpoint#1];
    _obstructionPositionASL = [_midpoint#0, _midpoint#1, _terrainHeight + 1];
};

// Calculate lateral direction (perpendicular to detonation-target line in horizontal plane)
private _direction = _detonationPositionASL vectorFromTo _targetPositionASL;
private _lateralDirection = [-(_direction#1), _direction#0, 0];
private _lateralMagnitude = vectorMagnitude _lateralDirection;
if (_lateralMagnitude > 0) then {
    _lateralDirection = _lateralDirection vectorMultiply (1 / _lateralMagnitude);
} else {
    _lateralDirection = [1, 0, 0];
};

// Generate 6 sample points: 2 heights (0.5m, 1.0m above obstruction) x 3 lateral positions (centre, +-0.5m)
private _samplePoints = [];
{
    private _heightOffset = _x;
    private _basePoint = _obstructionPositionASL vectorAdd [0, 0, _heightOffset];

    // Centre
    _samplePoints pushBack _basePoint;
    // Lateral offsets
    _samplePoints pushBack (_basePoint vectorAdd (_lateralDirection vectorMultiply 0.5));
    _samplePoints pushBack (_basePoint vectorAdd (_lateralDirection vectorMultiply -0.5));
} forEach [0.5, 1.0];

private _bestPath = [];
private _bestPathLength = 1e10;

{
    private _samplePointASL = _x;

    // Segment 1: detonation to sample point
    private _segment1Blocked = lineIntersects [_detonationPositionASL, _samplePointASL, _parentVehicle, _target]
        || {terrainIntersectASL [_detonationPositionASL, _samplePointASL]};

    if (_segment1Blocked) then { continue };

    // Segment 2: sample point to target
    private _segment2Blocked = lineIntersects [_samplePointASL, _targetPositionASL, _parentVehicle, _target]
        || {terrainIntersectASL [_samplePointASL, _targetPositionASL]};

    if (_segment2Blocked) then { continue };

    // Both segments clear — path found
    private _pathLength = (_detonationPositionASL vectorDistance _samplePointASL)
        + (_samplePointASL vectorDistance _targetPositionASL);

    if (_pathLength < _bestPathLength) then {
        _bestPathLength = _pathLength;
        _bestPath = [_pathLength, _samplePointASL];
    };
} forEach _samplePoints;

_bestPath
