#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Per-frame handler for Phase 2 surface bounce processing.
        Processes 1-2 targets per frame (heavier work than Phase 1).

    Parameter(s):
        0: Phase 2 state array <ARRAY>
        1: Per-frame handler ID <NUMBER>

    Return Value:
        None
*/

#define PHASE2_TARGETS_PER_FRAME 2
#define BOUNCE_1_ATTENUATION 0.4
#define BOUNCE_2_ATTENUATION 0.16

params ["_phase2State", "_perFrameHandlerID"];
_phase2State params [
    "_positionASL",
    "_ammo",
    "_indirectHit",
    "_indirectHitRange",
    "_effectiveRange",
    "_phase2Queue",
    "_currentIndex",
    "_source"
];

private _processedThisFrame = 0;

while {_currentIndex < count _phase2Queue && {_processedThisFrame < PHASE2_TARGETS_PER_FRAME}} do {
    private _targetData = _phase2Queue select _currentIndex;
    _targetData params ["_target", "_targetPositionASL", "_directDistance"];

    if !(alive _target) then {
        _currentIndex = _currentIndex + 1;
        _phase2State set [6, _currentIndex];
        continue
    };

    private _traceResult = [_positionASL, _targetPositionASL, _target, _effectiveRange] call FUNC(traceSurfaceBounce);

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
    _phase2State set [6, _currentIndex];
    _processedThisFrame = _processedThisFrame + 1;
};

if (_currentIndex >= count _phase2Queue) then {
    [_perFrameHandlerID] call CBA_fnc_removePerFrameHandler;

    TRACE_0("Phase 2 processing complete");
};
