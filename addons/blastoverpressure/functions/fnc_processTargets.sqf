#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Per-frame handler that processes shielded targets for overpressure damage.
        Phase 1: overhead tracing (3 targets/frame).
        Phase 2: surface bounce tracing (2 targets/frame).
        Transitions automatically from Phase 1 to Phase 2 when overhead
        tracing is complete and surface bounce is enabled.

    Parameter(s):
        0: Process state array <ARRAY>
        1: Per-frame handler ID <NUMBER>

    Return Value:
        None

    Example:
        [_processState, _perFrameHandlerID] call uksf_blastoverpressure_fnc_processTargets
*/

#define PHASE1_TARGETS_PER_FRAME 3
#define PHASE2_TARGETS_PER_FRAME 2
#define OVERHEAD_BOUNCE_ATTENUATION 0.7
#define BOUNCE_1_ATTENUATION 0.4
#define BOUNCE_2_ATTENUATION 0.16

params ["_processState", "_perFrameHandlerID"];
_processState params [
    "_positionASL",
    "_ammo",
    "_indirectHit",
    "_indirectHitRange",
    "_effectiveRange",
    "_shieldedTargets",
    "_currentIndex",
    "_phase2Queue",
    "_source",
    "_phase"
];

private _processedThisFrame = 0;

if (_phase isEqualTo 1) then {
    // Phase 1: overhead tracing
    while {_currentIndex < count _shieldedTargets && {_processedThisFrame < PHASE1_TARGETS_PER_FRAME}} do {
        private _targetData = _shieldedTargets select _currentIndex;
        _targetData params ["_target", "_targetPositionASL", "_directDistance", "_parentVehicle"];

        // Skip if target died since we started processing
        if !(alive _target) then {
            _currentIndex = _currentIndex + 1;
            _processState set [6, _currentIndex];
            continue
        };

        private _traceResult = [_positionASL, _targetPositionASL, _target, _parentVehicle] call FUNC(traceOverhead);

        if (_traceResult isNotEqualTo []) then {
            // Path found — calculate and apply damage immediately
            _traceResult params ["_totalPathLength", "_samplePointASL"];

            private _damageParams = [
                _target, _positionASL, _targetPositionASL, _samplePointASL,
                _indirectHit, _effectiveRange, _directDistance, _totalPathLength,
                OVERHEAD_BOUNCE_ATTENUATION, _source, "overhead"
            ];
            _damageParams call FUNC(calculateDamage);

            TRACE_3("Phase 1 path found",_target,_totalPathLength,_directDistance);
        } else {
            // No overhead path — queue for Phase 2
            _phase2Queue pushBack _targetData;

            TRACE_1("Phase 1 failed, queued for Phase 2",_target);
        };

        _currentIndex = _currentIndex + 1;
        _processState set [6, _currentIndex];
        _processedThisFrame = _processedThisFrame + 1;
    };

    // Check if Phase 1 is complete
    if (_currentIndex >= count _shieldedTargets) then {
        if (_phase2Queue isNotEqualTo [] && {GVAR(surfaceBounceEnabled)}) then {
            // Transition to Phase 2: reset index, switch phase
            _processState set [6, 0];
            _processState set [9, 2];

            TRACE_1("Transitioning to Phase 2",count _phase2Queue);
        } else {
            [_perFrameHandlerID] call CBA_fnc_removePerFrameHandler;

            TRACE_1("Processing complete, Phase 2 queue",count _phase2Queue);
        };
    };
} else {
    // Phase 2: surface bounce tracing
    while {_currentIndex < count _phase2Queue && {_processedThisFrame < PHASE2_TARGETS_PER_FRAME}} do {
        private _targetData = _phase2Queue select _currentIndex;
        _targetData params ["_target", "_targetPositionASL", "_directDistance", "_parentVehicle"];

        if !(alive _target) then {
            _currentIndex = _currentIndex + 1;
            _processState set [6, _currentIndex];
            continue
        };

        private _traceResult = [_positionASL, _targetPositionASL, _target, _effectiveRange, _parentVehicle] call FUNC(traceSurfaceBounce);

        if (_traceResult isNotEqualTo []) then {
            _traceResult params ["_totalPathLength", "_bouncePointASL", "_bounceCount"];

            private _bounceAttenuation = if (_bounceCount >= 2) then {
                BOUNCE_2_ATTENUATION
            } else {
                BOUNCE_1_ATTENUATION
            };

            private _pathType = format ["%1-bounce", _bounceCount];

            private _damageParams = [
                _target, _positionASL, _targetPositionASL, _bouncePointASL,
                _indirectHit, _effectiveRange, _directDistance, _totalPathLength,
                _bounceAttenuation, _source, _pathType
            ];
            _damageParams call FUNC(calculateDamage);

            TRACE_3("Phase 2 path found",_target,_pathType,_totalPathLength);
        } else {
            TRACE_1("Phase 2 failed, fully shielded",_target);
        };

        _currentIndex = _currentIndex + 1;
        _processState set [6, _currentIndex];
        _processedThisFrame = _processedThisFrame + 1;
    };

    if (_currentIndex >= count _phase2Queue) then {
        [_perFrameHandlerID] call CBA_fnc_removePerFrameHandler;

        TRACE_1("Phase 2 processing complete",count _phase2Queue);
    };
};
