#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Phase 1 overhead path tracing. Tries to find a 2-segment blast path
        from the detonation to the target via intermediate elevated/lateral
        sample points. Handles units behind sandbags, low walls, in trenches.

    Parameter(s):
        0: Detonation position ASL <ARRAY>
        1: Target position ASL <ARRAY>
        2: Target object <OBJECT>

    Return Value:
        [] if no path found, or [totalPathLength, samplePoint] for the best path
*/
params ["_detonationPositionASL", "_targetPositionASL", "_target"];

private _midpointASL = _detonationPositionASL vectorAdd _targetPositionASL;
_midpointASL = _midpointASL vectorMultiply 0.5;

// Calculate lateral direction (perpendicular to detonation-target line in horizontal plane)
private _direction = _detonationPositionASL vectorFromTo _targetPositionASL;
private _lateralDirection = [- (_direction#1), _direction#0, 0];
private _lateralMagnitude = vectorMagnitude _lateralDirection;
if (_lateralMagnitude > 0) then {
    _lateralDirection = _lateralDirection vectorMultiply (1 / _lateralMagnitude);
} else {
    _lateralDirection = [1, 0, 0];
};

// Generate 7 sample points
private _samplePoints = [
    // Above midpoint: +2m, +4m, +6m
    _midpointASL vectorAdd [0, 0, 2],
    _midpointASL vectorAdd [0, 0, 4],
    _midpointASL vectorAdd [0, 0, 6],
    // Above target: +3m, +5m
    _targetPositionASL vectorAdd [0, 0, 3],
    _targetPositionASL vectorAdd [0, 0, 5],
    // Lateral offsets at midpoint: 3m left and right, +2m height
    (_midpointASL vectorAdd [0, 0, 2]) vectorAdd (_lateralDirection vectorMultiply 3),
    (_midpointASL vectorAdd [0, 0, 2]) vectorAdd (_lateralDirection vectorMultiply -3)
];

private _bestPath = [];
private _bestPathLength = 1e10;

{
    private _samplePointASL = _x;

    // Segment 1: detonation to sample point
    private _segment1Blocked = lineIntersects [_detonationPositionASL, _samplePointASL, objNull, _target]
        || {terrainIntersectASL [_detonationPositionASL, _samplePointASL]};

    if (_segment1Blocked) then { continue };

    // Segment 2: sample point to target
    private _segment2Blocked = lineIntersects [_samplePointASL, _targetPositionASL, objNull, _target]
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
