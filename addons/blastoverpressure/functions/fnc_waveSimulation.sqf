#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Initialises the ray-marched pressure wave simulation.
        Fires rays in cones toward each known unit position, with angular
        spread for bounce opportunities. Filters below-ground rays for
        ground-level explosions.

    Parameter(s):
        0: Detonation position ASL <ARRAY>
        1: Ammo class name <STRING>
        2: indirectHit <NUMBER>
        3: indirectHitRange <NUMBER>
        4: Effective range <NUMBER>
        5: Source unit <OBJECT>
        6: Candidate positions ASL <ARRAY>

    Return Value:
        None
*/
params ["_positionASL", "_ammo", "_indirectHit", "_indirectHitRange", "_effectiveRange", "_source", "_candidatePositions"];

#define RAYS_PER_UNIT 12
#define MAX_TOTAL_RAYS 256
#define SPREAD_ANGLE 15

// Check if detonation is at ground level
private _terrainHeight = getTerrainHeightASL [_positionASL#0, _positionASL#1];
private _isGroundLevel = (_positionASL#2) - _terrainHeight < 2;

// Generate rays targeted at each unit
private _rays = [];
private _raysPerUnit = RAYS_PER_UNIT min (floor (MAX_TOTAL_RAYS / (count _candidatePositions max 1)));
_raysPerUnit = _raysPerUnit max 4;

private _goldenRatio = (1 + sqrt 5) / 2;

{
    private _targetPositionASL = _x;
    private _direction = _positionASL vectorFromTo _targetPositionASL;

    // Build local basis for this direction
    private _worldUp = [0, 0, 1];
    private _right = _direction vectorCrossProduct _worldUp;
    private _rightMagnitude = vectorMagnitude _right;
    if (_rightMagnitude < 0.01) then {
        _right = [1, 0, 0];
    } else {
        _right = _right vectorMultiply (1 / _rightMagnitude);
    };
    private _up = _right vectorCrossProduct _direction;
    private _upMagnitude = vectorMagnitude _up;
    if (_upMagnitude > 0) then {
        _up = _up vectorMultiply (1 / _upMagnitude);
    };

    // Generate rays in a cone around the direction to this unit
    for "_i" from 0 to (_raysPerUnit - 1) do {
        private _rayDirection = if (_i isEqualTo 0) then {
            // First ray: dead centre at unit
            _direction
        } else {
            // Spread rays using golden angle distribution within cone
            private _spreadFraction = _i / _raysPerUnit;
            private _coneAngle = SPREAD_ANGLE * sqrt _spreadFraction;
            private _rotationAngle = 360 * _i / _goldenRatio;

            private _pitchRadians = _coneAngle * (pi / 180);
            private _offsetDirection = _direction vectorAdd
                (_up vectorMultiply (sin _pitchRadians * cos _rotationAngle)) vectorAdd
                (_right vectorMultiply (sin _pitchRadians * sin _rotationAngle));
            private _magnitude = vectorMagnitude _offsetDirection;
            if (_magnitude > 0) then {
                _offsetDirection vectorMultiply (1 / _magnitude)
            } else {
                _direction
            }
        };

        // Ground filtering: clamp rays pointing below ground for ground-level explosions
        if (_isGroundLevel && {(_rayDirection#2) < 0}) then {
            _rayDirection = [_rayDirection#0, _rayDirection#1, 0];
            private _magnitude = vectorMagnitude _rayDirection;
            if (_magnitude > 0) then {
                _rayDirection = _rayDirection vectorMultiply (1 / _magnitude);
            } else {
                continue
            };
        };

        // Each ray: [currentPositionASL, direction, energy, bounceCount, distanceTravelled, pathHistory]
        _rays pushBack [_positionASL, _rayDirection, 1.0, 0, 0, [+[_positionASL, 0]]];
    };

    // Cap total rays
    if (count _rays >= MAX_TOTAL_RAYS) then { break };
} forEach _candidatePositions;

// Track which units have already been hit (avoid duplicate damage)
private _hitUnits = createHashMap;

private _waveState = [
    _positionASL, _rays, _indirectHit, _effectiveRange,
    _source, _hitUnits, CBA_missionTime
];

[FUNC(waveProcessRays), 0, _waveState] call CBA_fnc_addPerFrameHandler;

TRACE_2("Wave simulation started",count _rays,_effectiveRange);
