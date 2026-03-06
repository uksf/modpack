#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Per-frame handler that processes shielded targets for overpressure damage.
        Processes TARGETS_PER_FRAME targets per frame in Phase 1, then Phase 2.

    Parameter(s):
        0: Process state array <ARRAY>
        1: Per-frame handler ID <NUMBER>

    Return Value:
        None
*/

#define TARGETS_PER_FRAME 3
#define OVERHEAD_BOUNCE_ATTENUATION 0.7

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
    "_source"
];

private _processedThisFrame = 0;

// Phase 1: overhead tracing
while {_currentIndex < count _shieldedTargets && {_processedThisFrame < TARGETS_PER_FRAME}} do {
    private _targetData = _shieldedTargets select _currentIndex;
    _targetData params ["_target", "_targetPositionASL", "_directDistance"];

    // Skip if target died since we started processing
    if !(alive _target) then {
        _currentIndex = _currentIndex + 1;
        _processState set [6, _currentIndex];
        continue
    };

    private _traceResult = [_positionASL, _targetPositionASL, _target] call FUNC(traceOverhead);

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
    // If Phase 2 queue is empty or surface bounce disabled, we're done
    if (_phase2Queue isEqualTo [] || {!GVAR(surfaceBounceEnabled)}) then {
        [_perFrameHandlerID] call CBA_fnc_removePerFrameHandler;

        TRACE_1("Processing complete, Phase 2 queue",count _phase2Queue);
    } else {
        // Switch to Phase 2 processing
        [_perFrameHandlerID] call CBA_fnc_removePerFrameHandler;

        private _phase2State = [_positionASL, _ammo, _indirectHit, _indirectHitRange, _effectiveRange, _phase2Queue, 0, _source];
        [FUNC(processSurfaceBounces), 0, _phase2State] call CBA_fnc_addPerFrameHandler;
    };
};
