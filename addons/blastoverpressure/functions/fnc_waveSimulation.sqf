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
        7: Shielded targets [unit, positionASL, distance] <ARRAY>

    Return Value:
        None

    Example:
        [_positionASL, _ammo, _indirectHit, _indirectHitRange, _effectiveRange, _source, _candidatePositions, _shieldedTargets] call uksf_blastoverpressure_fnc_waveSimulation
*/
params ["_positionASL", "_ammo", "_indirectHit", "_indirectHitRange", "_effectiveRange", "_source", "_candidatePositions", "_shieldedTargets"];

#define RAYS_PER_UNIT 12
#define MAX_TOTAL_RAYS 256
#define SPREAD_ANGLE 10
#define HEIGHT_OFFSETS [0, 0.5, 1.0]

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
    // Rays are distributed across 3 height tiers (0m, +0.5m, +1.0m above detonation)
    private _heightOffsets = HEIGHT_OFFSETS;
    for "_i" from 0 to (_raysPerUnit - 1) do {
        // Cycle height tier per ray — offset origin but keep original direction
        // so elevated rays fire parallel, not angled into the ground
        private _heightOffset = _heightOffsets select (_i mod 3);
        private _rayOrigin = [_positionASL#0, _positionASL#1, (_positionASL#2) + _heightOffset];

        // Spread rays using golden angle distribution within cone
        private _spreadFraction = (_i + 1) / (_raysPerUnit + 1);
        private _coneAngle = SPREAD_ANGLE * sqrt _spreadFraction;
        private _rotationAngle = 360 * _i / _goldenRatio;

        private _offsetDirection = _direction vectorAdd
            (_up vectorMultiply (sin _coneAngle * cos _rotationAngle)) vectorAdd
            (_right vectorMultiply (sin _coneAngle * sin _rotationAngle));
        private _magnitude = vectorMagnitude _offsetDirection;
        private _rayDirection = if (_magnitude > 0) then {
            _offsetDirection vectorMultiply (1 / _magnitude)
        } else {
            _direction
        };

        // Height-offset rays: don't let spread push them below the base direction
        if (_heightOffset > 0 && {(_rayDirection#2) < (_direction#2)}) then {
            _rayDirection = [_rayDirection#0, _rayDirection#1, _direction#2];
            _magnitude = vectorMagnitude _rayDirection;
            if (_magnitude > 0) then {
                _rayDirection = _rayDirection vectorMultiply (1 / _magnitude);
            } else {
                continue
            };
        };

        // Ground filtering: clamp rays pointing below ground for ground-level explosions
        if (_isGroundLevel && {(_rayDirection#2) < 0}) then {
            _rayDirection = [_rayDirection#0, _rayDirection#1, 0];
            _magnitude = vectorMagnitude _rayDirection;
            if (_magnitude > 0) then {
                _rayDirection = _rayDirection vectorMultiply (1 / _magnitude);
            } else {
                continue
            };
        };

        // Each ray: [currentPositionASL, direction, energy, bounceCount, distanceTravelled, pathHistory]
        _rays pushBack [_rayOrigin, _rayDirection, 1.0, 0, 0, [+[_rayOrigin, 0]]];
    };

    // Cap total rays
    if (count _rays >= MAX_TOTAL_RAYS) then { break };
} forEach _candidatePositions;

// Track which units have already been hit (avoid duplicate damage)
private _hitUnits = createHashMap;

private _waveState = [
    _positionASL, _rays, _indirectHit, _effectiveRange,
    _source, _hitUnits, CBA_missionTime, _shieldedTargets
];

[FUNC(waveProcessRays), 0, _waveState] call CBA_fnc_addPerFrameHandler;

TRACE_2("Wave simulation started",count _rays,_effectiveRange);
