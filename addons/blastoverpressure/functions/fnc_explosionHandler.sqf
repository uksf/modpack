#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Handles explosion events from ACE. Filters by ammo threshold and
        collects candidate targets for overpressure damage processing.
        For vehicles, individually processes each crew member's line of sight,
        excluding the parent vehicle hull from LOS checks.

    Parameter(s):
        0: Projectile that exploded <OBJECT>
        1: Position ASL of explosion <ARRAY>

    Return Value:
        None

    Example:
        [_projectile, _positionASL] call uksf_blastoverpressure_fnc_explosionHandler
*/
params ["_projectile", "_positionASL"];

if !(GVAR(enabled)) exitWith {};

private _ammo = typeOf _projectile;

private _ammoConfig = [_ammo] call FUNC(getAmmoConfig);
_ammoConfig params ["_indirectHit", "_indirectHitRange", "_powerScore", "_ammoDamageMultiplier", "_isEnabled"];

if !(_isEnabled) exitWith {};
if (_powerScore < GVAR(threshold)) exitWith {};

private _effectiveRange = _indirectHitRange * GVAR(rangeMultiplier);
private _adjustedIndirectHit = _indirectHit * _ammoDamageMultiplier;

private _shotParents = getShotParents _projectile;
private _source = _shotParents select !isNull (_shotParents#1);

TRACE_7("Explosion",_ammo,_indirectHit,_adjustedIndirectHit,_indirectHitRange,_powerScore,_effectiveRange,_positionASL);

// Collect all entities in effective range
private _candidates = (ASLToAGL _positionASL) nearEntities [
    ["CAManBase", "Car", "Motorcycle", "Tank", "StaticWeapon", "Air", "Ship"],
    _effectiveRange
];

// Filter to units whose direct LOS to the detonation is blocked
// For vehicles, check each crew member individually and exclude the vehicle hull from LOS
// Target data: [unit, positionASL, directDistance, parentVehicle]
private _shieldedTargets = [];
#ifdef DEBUG_MODE_FULL
    private _unshieldedTargets = [];
#endif

{
    if !(alive _x) then { continue };

    if (_x isKindOf "CAManBase") then {
        // Infantry on foot — check eye position for LOS
        private _targetPositionASL = eyePos _x;

        private _hasDirectLOS = !(lineIntersects [_positionASL, _targetPositionASL, _projectile, _x])
            && {!(terrainIntersectASL [_positionASL, _targetPositionASL])};

        if (_hasDirectLOS) then {
            TRACE_1("Skipping infantry - direct LOS",_x);
            #ifdef DEBUG_MODE_FULL
                _unshieldedTargets pushBack _x;
            #endif
            continue
        };

        private _directDistance = _positionASL vectorDistance _targetPositionASL;
        _shieldedTargets pushBack [_x, _targetPositionASL, _directDistance, objNull];

        TRACE_2("Shielded infantry",_x,_directDistance);
    } else {
        // Vehicle — check each crew member individually
        // Exclude the vehicle hull from LOS so we test against external cover only
        {
            if !(alive _x) then { continue };

            private _crewPositionASL = eyePos _x;
            private _parentVehicle = objectParent _x;

            // Exclude both the projectile and parent vehicle from LOS check
            // Tests whether external obstacles (buildings, terrain) shield the crew
            private _hasDirectLOS = !(lineIntersects [_positionASL, _crewPositionASL, _projectile, _parentVehicle])
                && {!(terrainIntersectASL [_positionASL, _crewPositionASL])};

            if (_hasDirectLOS) then {
                TRACE_2("Skipping crew - direct LOS",_x,_parentVehicle);
                #ifdef DEBUG_MODE_FULL
                    _unshieldedTargets pushBack _x;
                #endif
                continue
            };

            private _directDistance = _positionASL vectorDistance _crewPositionASL;
            _shieldedTargets pushBack [_x, _crewPositionASL, _directDistance, _parentVehicle];

            TRACE_3("Shielded crew",_x,_directDistance,_parentVehicle);
        } forEach crew _x;
    };
} forEach _candidates;

if (_shieldedTargets isEqualTo []) exitWith {
    TRACE_1("No shielded targets found",count _candidates);
};

TRACE_1("Processing shielded targets",count _shieldedTargets);

#ifdef DEBUG_MODE_FULL
    [_positionASL, _indirectHitRange, _effectiveRange, _ammo, count _shieldedTargets, _shieldedTargets, _unshieldedTargets] call FUNC(debugDrawBlastRadius);
#endif

if (GVAR(mode) isEqualTo "pressure_wave") then {
    private _candidatePositions = _shieldedTargets apply { _x#1 };
    [_positionASL, _ammo, _adjustedIndirectHit, _indirectHitRange, _effectiveRange, _source, _candidatePositions, _shieldedTargets] call FUNC(waveSimulation);
} else {
    private _processState = [_positionASL, _ammo, _adjustedIndirectHit, _indirectHitRange, _effectiveRange, _shieldedTargets, 0, [], _source, 1];
    [FUNC(processTargets), 0, _processState] call CBA_fnc_addPerFrameHandler;
};
