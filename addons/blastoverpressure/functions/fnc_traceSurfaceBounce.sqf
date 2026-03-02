#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Phase 2 surface bounce tracing. Casts rays from detonation toward
        surfaces near the target, checks if hit points have LOS to the target.
        Models blast entering buildings through openings or bouncing around corners.

    Parameter(s):
        0: Detonation position ASL <ARRAY>
        1: Target position ASL <ARRAY>
        2: Target object <OBJECT>
        3: Effective range <NUMBER>

    Return Value:
        [] if no path found, or [totalPathLength, bouncePointASL, bounceCount] for best path
*/
params ["_detonationPositionASL", "_targetPositionASL", "_target", "_effectiveRange"];

private _direction = _detonationPositionASL vectorFromTo _targetPositionASL;
private _directDistance = _detonationPositionASL vectorDistance _targetPositionASL;

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

// 1-bounce: cast ray, find surface hit, check LOS from hit to target
{
    private _rayDirection = _x;
    private _rayEnd = _detonationPositionASL vectorAdd (_rayDirection vectorMultiply (_effectiveRange * 1.5));

    private _intersections = lineIntersectsSurfaces [_detonationPositionASL, _rayEnd, _target, objNull, true, 1, "GEOM", "NONE"];

    if (_intersections isEqualTo []) then { continue };

    (_intersections#0) params ["_hitPositionASL", "_surfaceNormal"];

    // Check LOS from hit point to target
    // Offset slightly along surface normal to avoid self-intersection
    private _bouncePointASL = _hitPositionASL vectorAdd (_surfaceNormal vectorMultiply 0.1);

    private _bounceToTargetBlocked = lineIntersects [_bouncePointASL, _targetPositionASL, objNull, _target]
        || {terrainIntersectASL [_bouncePointASL, _targetPositionASL]};

    if !(_bounceToTargetBlocked) then {
        private _pathLength = (_detonationPositionASL vectorDistance _bouncePointASL)
            + (_bouncePointASL vectorDistance _targetPositionASL);

        if (_pathLength < _bestPathLength) then {
            _bestPathLength = _pathLength;
            _bestPath = [_pathLength, _bouncePointASL, 1];
        };
    } else {
        // Try 2-bounce: reflect off surface, cast again, check LOS
        private _reflectedDirection = _rayDirection vectorAdd ((_surfaceNormal vectorMultiply (-2 * (_rayDirection vectorDotProduct _surfaceNormal))));
        private _reflectedEnd = _bouncePointASL vectorAdd (_reflectedDirection vectorMultiply (_effectiveRange * 0.75));

        private _reflectedIntersections = lineIntersectsSurfaces [_bouncePointASL, _reflectedEnd, objNull, objNull, true, 1, "GEOM", "NONE"];

        if (_reflectedIntersections isEqualTo []) then { continue };

        (_reflectedIntersections#0) params ["_hitPosition2ASL", "_surfaceNormal2"];

        private _bouncePoint2ASL = _hitPosition2ASL vectorAdd (_surfaceNormal2 vectorMultiply 0.1);

        private _bounce2ToTargetBlocked = lineIntersects [_bouncePoint2ASL, _targetPositionASL, objNull, _target]
            || {terrainIntersectASL [_bouncePoint2ASL, _targetPositionASL]};

        if !(_bounce2ToTargetBlocked) then {
            private _pathLength = (_detonationPositionASL vectorDistance _bouncePointASL)
                + (_bouncePointASL vectorDistance _bouncePoint2ASL)
                + (_bouncePoint2ASL vectorDistance _targetPositionASL);

            if (_pathLength < _bestPathLength) then {
                _bestPathLength = _pathLength;
                _bestPath = [_pathLength, _bouncePoint2ASL, 2];
            };
        };
    };
} forEach _rayDirections;

_bestPath
