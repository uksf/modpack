#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Calculates overpressure damage based on attenuation factors and
        dispatches to damage application.

    Parameter(s):
        0: Target object <OBJECT>
        1: Detonation position ASL <ARRAY>
        2: Target position ASL <ARRAY>
        3: Intermediate/bounce point ASL <ARRAY>
        4: Ammo indirectHit value <NUMBER>
        5: Effective range <NUMBER>
        6: Direct distance to target <NUMBER>
        7: Total path length <NUMBER>
        8: Bounce attenuation factor <NUMBER>
        9: Source unit (who caused the explosion) <OBJECT>
        10: Path type string for debug <STRING>

    Return Value:
        Damage applied <NUMBER>
*/
params [
    "_target", "_detonationPositionASL", "_targetPositionASL", "_intermediatePointASL",
    "_indirectHit", "_effectiveRange", "_directDistance", "_totalPathLength",
    "_bounceAttenuation", "_source", "_pathType"
];

// Distance falloff: sqrt curve matching ACE overpressure model
private _distanceFalloff = if (_totalPathLength >= _effectiveRange) then {
    0
} else {
    sqrt (1 - (_totalPathLength / _effectiveRange))
};

if (_distanceFalloff <= 0) exitWith { 0 };

// Path indirectness penalty: longer detours = less damage
private _indirectnessPenalty = if (_totalPathLength > 0) then {
    (_directDistance / _totalPathLength) min 1
} else {
    1
};

// Calculate raw damage
private _rawDamage = _indirectHit * _distanceFalloff * _indirectnessPenalty * _bounceAttenuation * GVAR(damageMultiplier);

if (_rawDamage <= 0) exitWith { 0 };

#ifdef DEBUG_MODE_FULL
    diag_log text format [
        "[%1] Damage calc for %2: raw=%3 distFalloff=%4 indirect=%5 bounce=%6 type=%7",
        ADDON, _target, _rawDamage, _distanceFalloff, _indirectnessPenalty, _bounceAttenuation, _pathType
    ];
#endif

// Apply damage
[_target, _rawDamage, _source] call FUNC(applyDamage);

#ifdef DEBUG_MODE_FULL
    [_target, _detonationPositionASL, _targetPositionASL, _intermediatePointASL, _rawDamage, _pathType] call FUNC(debugDraw);
#endif

_rawDamage
