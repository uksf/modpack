#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Per-frame handler that advances ray particles in the pressure wave simulation.
        Processes rays in batches, handles surface reflections and unit hits.
        Accumulates path history per ray for debug visualisation.

    Parameter(s):
        0: Wave state array <ARRAY>
        1: Per-frame handler ID <NUMBER>

    Return Value:
        None
*/

#define RAYS_PER_FRAME 32
#define WAVE_SPEED 340
#define BOUNCE_ENERGY_FACTOR 0.5
#define MAX_BOUNCES 3
#define HIT_PROXIMITY 1.5
#define MIN_ENERGY 0.05

params ["_waveState", "_perFrameHandlerID"];
_waveState params [
    "_originASL", "_rays", "_indirectHit", "_effectiveRange",
    "_source", "_hitUnits", "_lastFrameTime"
];

private _currentTime = CBA_missionTime;
private _deltaTime = _currentTime - _lastFrameTime;
_waveState set [6, _currentTime];

// Clamp delta time to avoid huge jumps
_deltaTime = _deltaTime min 0.1;

if (_deltaTime <= 0) exitWith {};

private _stepDistance = WAVE_SPEED * _deltaTime;
private _raysToRemove = [];

private _processCount = (count _rays) min RAYS_PER_FRAME;

for "_i" from 0 to (_processCount - 1) do {
    private _ray = _rays select _i;
    _ray params ["_rayPositionASL", "_rayDirection", "_energy", "_bounceCount", "_distanceTravelled", "_pathHistory"];

    // Skip dead rays
    if (_energy < MIN_ENERGY) then {
        _raysToRemove pushBack _i;
        continue
    };

    // Calculate new position
    private _newPositionASL = _rayPositionASL vectorAdd (_rayDirection vectorMultiply _stepDistance);
    private _newDistance = _distanceTravelled + _stepDistance;

    // Check if ray exceeded effective range
    if (_newDistance > _effectiveRange) then {
        _raysToRemove pushBack _i;
        continue
    };

    // Check for surface intersection
    private _intersections = lineIntersectsSurfaces [_rayPositionASL, _newPositionASL, objNull, objNull, true, 1, "GEOM", "NONE"];

    if (_intersections isNotEqualTo []) then {
        (_intersections#0) params ["_hitPositionASL", "_surfaceNormal"];

        // Record path up to bounce point
        _pathHistory pushBack [_hitPositionASL, _bounceCount];

        if (_bounceCount >= MAX_BOUNCES) then {
            _raysToRemove pushBack _i;
            continue
        };

        // Reflect off surface
        private _reflectedDirection = _rayDirection vectorAdd (
            _surfaceNormal vectorMultiply (-2 * (_rayDirection vectorDotProduct _surfaceNormal))
        );

        // Update ray: new position (offset from surface), reflected direction, reduced energy
        private _bouncePosition = _hitPositionASL vectorAdd (_surfaceNormal vectorMultiply 0.15);
        _ray set [0, _bouncePosition];
        _ray set [1, _reflectedDirection];
        _ray set [2, _energy * BOUNCE_ENERGY_FACTOR];
        _ray set [3, _bounceCount + 1];
        _ray set [4, _distanceTravelled + (_rayPositionASL vectorDistance _hitPositionASL)];

        // Record post-bounce position as start of next segment
        _pathHistory pushBack [_bouncePosition, _bounceCount + 1];
    } else {
        // No intersection — advance ray
        _ray set [0, _newPositionASL];
        _ray set [4, _newDistance];

        // Record path point
        _pathHistory pushBack [_newPositionASL, _bounceCount];

        // Check for nearby units
        private _nearUnits = (ASLToAGL _newPositionASL) nearEntities [
            ["CAManBase", "Car", "Motorcycle", "Tank", "StaticWeapon", "Air", "Ship"],
            HIT_PROXIMITY
        ];

        {
            if !(alive _x) then { continue };

            private _unitKey = hashValue _x;
            if (_unitKey in _hitUnits) then { continue };

            // Calculate damage based on ray energy and distance from detonation
            private _distanceFromOrigin = _originASL vectorDistance _newPositionASL;
            private _distanceFalloff = if (_distanceFromOrigin >= _effectiveRange) then {
                0
            } else {
                sqrt (1 - (_distanceFromOrigin / _effectiveRange))
            };

            private _rawDamage = _indirectHit * _energy * _distanceFalloff * GVAR(damageMultiplier);

            if (_rawDamage > 0) then {
                _hitUnits set [_unitKey, true];
                [_x, _rawDamage, _source] call FUNC(applyDamage);

                TRACE_4("Wave hit",_x,_energy,_rawDamage,_bounceCount);
                #ifdef DEBUG_MODE_FULL
                    [_x, _originASL, eyePos _x, _newPositionASL, _rawDamage, format ["wave-%1bounce", _bounceCount]] call FUNC(debugDraw);
                #endif
            };
        } forEach _nearUnits;
    };
};

#ifdef DEBUG_MODE_FULL
    // Draw accumulated path trails for all active rays
    {
        _x params ["", "", "", "", "", "_history"];
        if (count _history < 2) then { continue };

        for "_j" from 1 to (count _history - 1) do {
            private _previous = _history select (_j - 1);
            private _current = _history select _j;
            _previous params ["_previousPositionASL", "_previousBounceCount"];
            _current params ["_currentPositionASL", ""];

            // Colour by bounce count: yellow -> orange -> red -> magenta
            private _colour = switch (_previousBounceCount) do {
                case 0: { [1, 1, 0, 0.8] };
                case 1: { [1, 0.5, 0, 0.8] };
                case 2: { [1, 0, 0, 0.8] };
                default { [1, 0, 1, 0.8] };
            };

            drawLine3D [ASLToATL _previousPositionASL, ASLToATL _currentPositionASL, _colour];
        };
    } forEach _rays;
#endif

// Remove dead rays (reverse order to preserve indices)
_raysToRemove sort false;
{
    _rays deleteAt _x;
} forEach _raysToRemove;

// Rotate processed rays to back of queue for round-robin processing
private _remainingCount = count _rays;
if (_remainingCount > RAYS_PER_FRAME) then {
    private _rotateCount = _processCount min _remainingCount;
    private _processed = _rays select [0, _rotateCount];
    _rays deleteRange [0, _rotateCount];
    _rays append _processed;
};

// Stop when all rays are dead
if (_rays isEqualTo []) then {
    [_perFrameHandlerID] call CBA_fnc_removePerFrameHandler;

    TRACE_1("Wave simulation complete",count _rays);
};
