#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Phase 2 surface bounce tracing. Casts rays from detonation toward
        surfaces near the target, checks if hit points have LOS to the target.
        Models blast entering buildings through openings or bouncing around corners.
        Supports up to 2 bounces per ray via iterative reflection.

    Parameter(s):
        0: Detonation position ASL <ARRAY>
        1: Target position ASL <ARRAY>
        2: Target object <OBJECT>
        3: Effective range <NUMBER>
        4: Parent vehicle to exclude from LOS checks <OBJECT> (default objNull)

    Return Value:
        [] if no path found, or [totalPathLength, bouncePointASL, bounceCount] for best path

    Example:
        [_detonationPositionASL, _targetPositionASL, _target, _effectiveRange, _parentVehicle] call uksf_blastoverpressure_fnc_traceSurfaceBounce
*/

#define MAX_BOUNCES 2

params ["_detonationPositionASL", "_targetPositionASL", "_target", "_effectiveRange", ["_parentVehicle", objNull]];

private _direction = _detonationPositionASL vectorFromTo _targetPositionASL;

// Build orthonormal basis for generating offset rays
private _up = [0, 0, 1];
private _right = _direction vectorCrossProduct _up;
private _rightMagnitude = vectorMagnitude _right;
if (_rightMagnitude < 0.01) then {
    _right = [1, 0, 0];
} else {
    _right = _right vectorMultiply (1 / _rightMagnitude);
};
_up = _right vectorCrossProduct _direction;
private _upMagnitude = vectorMagnitude _up;
if (_upMagnitude > 0) then {
    _up = _up vectorMultiply (1 / _upMagnitude);
};

// Generate 12 ray directions: offset from D->T by various angles
private _rayDirections = [];

// 8 rays in a cone: +/-10 and +/-20 degrees in pitch and yaw
{
    _x params ["_pitchDegrees", "_yawDegrees"];
    private _pitchRadians = _pitchDegrees * (pi / 180);
    private _yawRadians = _yawDegrees * (pi / 180);
    private _offsetDirection = _direction vectorAdd (_up vectorMultiply (sin _pitchRadians)) vectorAdd (_right vectorMultiply (sin _yawRadians));
    private _magnitude = vectorMagnitude _offsetDirection;
    if (_magnitude > 0) then {
        _rayDirections pushBack (_offsetDirection vectorMultiply (1 / _magnitude));
    };
} forEach [
    [10, 0], [-10, 0], [0, 10], [0, -10],
    [20, 0], [-20, 0], [0, 20], [0, -20]
];

// 4 rays aimed at offset positions from target
{
    private _offsetTarget = _targetPositionASL vectorAdd _x;
    private _offsetDirection = _detonationPositionASL vectorFromTo _offsetTarget;
    _rayDirections pushBack _offsetDirection;
} forEach [
    [0, 0, 4],   // above
    [0, 0, -1],  // below
    (_right vectorMultiply 4),   // right
    (_right vectorMultiply -4)   // left
];

private _bestPath = [];
private _bestPathLength = 1e10;

// For each ray, iteratively bounce up to MAX_BOUNCES times
{
    private _rayDirection = _x;
    private _currentOrigin = _detonationPositionASL;
    private _currentDirection = _rayDirection;
    private _accumulatedPathLength = 0;
    private _rangeScale = 1.5;

    for "_bounce" from 1 to MAX_BOUNCES do {
        private _rayEnd = _currentOrigin vectorAdd (_currentDirection vectorMultiply (_effectiveRange * _rangeScale));

        private _intersections = lineIntersectsSurfaces [_currentOrigin, _rayEnd, _target, _parentVehicle, true, 1, "GEOM", "NONE"];

        if (_intersections isEqualTo []) then { break };

        (_intersections#0) params ["_hitPositionASL", "_surfaceNormal"];

        // Offset from surface to avoid self-intersection
        private _bouncePointASL = _hitPositionASL vectorAdd (_surfaceNormal vectorMultiply 0.1);
        _accumulatedPathLength = _accumulatedPathLength + (_currentOrigin vectorDistance _bouncePointASL);

        // Check LOS from bounce point to target
        private _bounceToTargetBlocked = lineIntersects [_bouncePointASL, _targetPositionASL, _parentVehicle, _target]
            || {terrainIntersectASL [_bouncePointASL, _targetPositionASL]};

        if !(_bounceToTargetBlocked) then {
            private _totalPathLength = _accumulatedPathLength + (_bouncePointASL vectorDistance _targetPositionASL);

            if (_totalPathLength < _bestPathLength) then {
                _bestPathLength = _totalPathLength;
                _bestPath = [_totalPathLength, _bouncePointASL, _bounce];
            };
            break
        };

        // Reflect direction for next bounce
        _currentDirection = _currentDirection vectorAdd (_surfaceNormal vectorMultiply (-2 * (_currentDirection vectorDotProduct _surfaceNormal)));
        _currentOrigin = _bouncePointASL;
        _rangeScale = 0.75;
    };
} forEach _rayDirections;

_bestPath
