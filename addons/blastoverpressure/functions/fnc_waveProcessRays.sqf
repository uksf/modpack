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

    Example:
        [_waveState, _perFrameHandlerID] call uksf_blastoverpressure_fnc_waveProcessRays
*/

// Ray budget scales with FPS: more rays when frames are cheap, fewer when struggling
#define RAYS_AT_60FPS 32
#define WAVE_SPEED 340
#define BOUNCE_ENERGY_FACTOR 0.5
#define MAX_BOUNCES 3
#define HIT_PROXIMITY 1.5
#define MIN_ENERGY 0.05

params ["_waveState", "_perFrameHandlerID"];
_waveState params [
    "_originASL", "_rays", "_indirectHit", "_effectiveRange",
    "_source", "_hitUnits", "_lastFrameTime", "_shieldedTargets"
];

private _currentTime = CBA_missionTime;
private _deltaTime = _currentTime - _lastFrameTime;
_waveState set [6, _currentTime];

// Clamp delta time to avoid huge jumps
_deltaTime = _deltaTime min 0.1;

if (_deltaTime <= 0) exitWith {};

private _stepDistance = WAVE_SPEED * _deltaTime;

if (_rays isEqualTo []) exitWith {
    [_perFrameHandlerID] call CBA_fnc_removePerFrameHandler;
};

// Scale ray budget with current FPS: 32 at 60fps, 16 at 30fps, 8 at 15fps
private _rayBudget = (RAYS_AT_60FPS * diag_fps / 60) max 4;
private _processCount = (count _rays) min (ceil _rayBudget);
private _proximityThreshold = HIT_PROXIMITY + _stepDistance;

for "_i" from 0 to (_processCount - 1) do {
    private _ray = _rays select _i;
    _ray params ["_rayPositionASL", "_rayDirection", "_energy", "_bounceCount", "_distanceTravelled", "_pathHistory"];

    // Skip dead rays
    if (count _rayPositionASL < 3 || {_energy < MIN_ENERGY}) then {
        _ray set [2, 0];
        continue
    };

    // Calculate new position
    private _newPositionASL = _rayPositionASL vectorAdd (_rayDirection vectorMultiply _stepDistance);
    private _newDistance = _distanceTravelled + _stepDistance;

    // Check if ray exceeded effective range
    if (_newDistance > _effectiveRange) then {
        _ray set [2, 0];
        continue
    };

    // Check for surface intersection
    private _intersections = lineIntersectsSurfaces [_rayPositionASL, _newPositionASL, objNull, objNull, true, 1, "GEOM", "NONE"];

    if (_intersections isNotEqualTo []) then {
        (_intersections#0) params ["_hitPositionASL", "_surfaceNormal"];

        // Record path up to bounce point
        _pathHistory pushBack [_hitPositionASL, _bounceCount];

        if (_bounceCount >= MAX_BOUNCES) then {
            _ray set [2, 0];
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

        // Check pre-collected targets — compute segment vector once for all targets
        private _segmentVector = _newPositionASL vectorDiff _rayPositionASL;
        private _segmentLengthSq = _segmentVector vectorDotProduct _segmentVector;

        {
            _x params ["_unit", "_targetPositionASL", ""];

            if !(alive _unit) then { continue };

            private _unitKey = hashValue _unit;
            if (_unitKey in _hitUnits) then { continue };

            // Quick reject: rough distance check avoids expensive segment projection
            if (_newPositionASL vectorDistance _targetPositionASL > _proximityThreshold) then { continue };

            // Precise: project target onto ray segment to find closest point
            private _toTarget = _targetPositionASL vectorDiff _rayPositionASL;
            private _t = if (_segmentLengthSq > 0) then {
                ((_toTarget vectorDotProduct _segmentVector) / _segmentLengthSq) max 0 min 1
            } else {
                0
            };
            private _closestPointASL = _rayPositionASL vectorAdd (_segmentVector vectorMultiply _t);
            private _proximityDistance = _closestPointASL vectorDistance _targetPositionASL;

            if (_proximityDistance > HIT_PROXIMITY) then { continue };

            // Calculate damage based on ray energy and distance from detonation
            private _distanceFromOrigin = _originASL vectorDistance _closestPointASL;
            private _distanceFalloff = if (_distanceFromOrigin >= _effectiveRange) then {
                0
            } else {
                sqrt (1 - (_distanceFromOrigin / _effectiveRange))
            };

            private _rawDamage = _indirectHit * _energy * _distanceFalloff * GVAR(damageMultiplier);

            if (_rawDamage > 0) then {
                _hitUnits set [_unitKey, true];
                [_unit, _rawDamage, _source] call FUNC(applyDamage);

                TRACE_4("Wave hit",_unit,_energy,_rawDamage,_bounceCount);
                #ifdef DEBUG_MODE_FULL
                    [_unit, _targetPositionASL, _closestPointASL, _rawDamage, format ["wave-%1bounce", _bounceCount], +_pathHistory] call FUNC(debugDraw);
                #endif
            };
        } forEach _shieldedTargets;
    };
};

#ifdef DEBUG_MODE_FULL
    // Draw last 5m of each ray's path trail
    {
        _x params ["", "", "", "", "", "_history"];
        if (count _history < 2) then { continue };

        // Walk backwards through history to find segments within 5m of the ray head
        private _headPositionASL = (_history select (count _history - 1)) select 0;
        private _startIndex = count _history - 2;
        for "_j" from (count _history - 2) to 0 step -1 do {
            private _segmentPositionASL = (_history select _j) select 0;
            if (_headPositionASL vectorDistance _segmentPositionASL > 5) exitWith {
                _startIndex = _j;
            };
            _startIndex = _j;
        };

        for "_j" from (_startIndex max 1) to (count _history - 1) do {
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

// Remove dead rays and rotate processed to back in one pass
private _processedAlive = [];
private _unprocessed = [];

{
    if ((_x#2) < MIN_ENERGY) then { continue };
    if (_forEachIndex < _processCount) then {
        _processedAlive pushBack _x;
    } else {
        _unprocessed pushBack _x;
    };
} forEach _rays;

_unprocessed append _processedAlive;
_waveState set [1, _unprocessed];

// Stop when all rays are dead
if (_unprocessed isEqualTo []) then {
    [_perFrameHandlerID] call CBA_fnc_removePerFrameHandler;

    TRACE_1("Wave simulation complete",0);
};
