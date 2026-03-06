#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Server-side handler for fortification destruction. Collects objects
        in blast radius, filters to fortifications, classifies by tier,
        calculates distance-based damage, and applies destruction.

    Parameter(s):
        0: Detonation position ASL <ARRAY>
        1: indirectHit value (adjusted) <NUMBER>
        2: indirectHitRange <NUMBER>
        3: Effective range <NUMBER>
        4: Source object (who caused the explosion) <OBJECT>

    Return Value:
        None
*/
if !(isServer) exitWith {};
if !(GVAR(fortificationDestructionEnabled)) exitWith {};

params ["_positionASL", "_indirectHit", "_indirectHitRange", "_effectiveRange", "_source"];

// Collect static objects in effective range
private _positionAGL = ASLToAGL _positionASL;
private _nearbyObjects = _positionAGL nearObjects ["Static", _effectiveRange];

TRACE_2("Fortification scan",count _nearbyObjects,_effectiveRange);

#ifdef DEBUG_MODE_FULL
    private _destroyedCount = 0;
    private _damagedCount = 0;
    private _protectedCount = 0;
#endif

{
    // Skip already destroyed objects
    if !(alive _x) then { continue };
    if (damage _x >= 1) then { continue };

    // Skip damage-protected objects
    if !(isDamageAllowed _x) then {
        #ifdef DEBUG_MODE_FULL
            _protectedCount = _protectedCount + 1;
        #endif
        continue
    };

    // Classify the object — skip terrain objects with no classname
    private _className = typeOf _x;
    if (_className isEqualTo "") then { continue };
    private _classification = [_className] call FUNC(classifyFortification);
    _classification params ["_isFortification", "_tier"];

    if !(_isFortification) then { continue };

    // Calculate distance-based damage
    private _objectPositionASL = getPosASL _x;
    private _distance = _positionASL vectorDistance _objectPositionASL;

    if (_distance >= _effectiveRange) then { continue };

    // Damage falloff: linear from indirectHit at distance 0 to 0 at effectiveRange
    private _rawDamage = _indirectHit * (1 - (_distance / _effectiveRange));

    // Normalise to 0-1 damage scale
    // indirectHit for large munitions is 60-200+, a value of ~53 should destroy most fortifications
    private _normalisedDamage = (_rawDamage / 53) min 1;

    if (_normalisedDamage <= 0.01) then { continue };

    // Apply destruction
    private _destroyed = [_x, _normalisedDamage, _source, _tier] call FUNC(destroyFortification);

    #ifdef DEBUG_MODE_FULL
        if (_destroyed) then {
            _destroyedCount = _destroyedCount + 1;
        } else {
            _damagedCount = _damagedCount + 1;
        };
    #endif
} forEach _nearbyObjects;

#ifdef DEBUG_MODE_FULL
    TRACE_3("Fortification results",_destroyedCount,_damagedCount,_protectedCount);
    [_positionASL, _effectiveRange, _destroyedCount, _damagedCount, _protectedCount] call FUNC(debugDrawFortifications);
#endif
