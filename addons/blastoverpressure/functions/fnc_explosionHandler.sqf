#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Handles explosion events from ACE. Filters by ammo threshold and
        collects candidate targets for overpressure damage processing.

    Parameter(s):
        0: Projectile that exploded <OBJECT>
        1: Position ASL of explosion <ARRAY>

    Return Value:
        None
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

// Fortification destruction — fire server event if above fortification threshold
if (GVAR(fortificationDestructionEnabled) && {_powerScore >= GVAR(fortificationThreshold)}) then {
    [QGVAR(processFortifications), [_positionASL, _adjustedIndirectHit, _indirectHitRange, _effectiveRange, _source]] call CBA_fnc_serverEvent;
};

TRACE_7("Explosion",_ammo,_indirectHit,_adjustedIndirectHit,_indirectHitRange,_powerScore,_effectiveRange,_positionASL);

// Collect all entities in effective range
private _candidates = (ASLToAGL _positionASL) nearEntities [
    ["CAManBase", "Car", "Motorcycle", "Tank", "StaticWeapon", "Air", "Ship"],
    _effectiveRange
];

// Filter to units that are alive and whose direct LOS to the detonation is blocked
private _shieldedTargets = [];
#ifdef DEBUG_MODE_FULL
    private _unshieldedTargets = [];
#endif

{
    if !(alive _x) then { continue };

    // Get target check position: eye position for infantry, model centre for vehicles
    private _targetPositionASL = if (_x isKindOf "CAManBase") then {
        eyePos _x
    } else {
        AGLToASL (_x modelToWorldVisual [0, 0, 0])
    };

    // Check direct LOS — if clear, Arma handles this unit natively, skip
    private _hasDirectLOS = !(lineIntersects [_positionASL, _targetPositionASL, _projectile, _x])
        && {!(terrainIntersectASL [_positionASL, _targetPositionASL])};

    if (_hasDirectLOS) then {
        TRACE_1("Skipping - direct LOS",_x);
        #ifdef DEBUG_MODE_FULL
            _unshieldedTargets pushBack _x;
        #endif
        continue
    };

    private _directDistance = _positionASL vectorDistance _targetPositionASL;

    _shieldedTargets pushBack [_x, _targetPositionASL, _directDistance];

    TRACE_2("Shielded target",_x,_directDistance);
} forEach _candidates;

if (_shieldedTargets isEqualTo []) exitWith {
    TRACE_1("No shielded targets found",count _candidates);
};

TRACE_1("Processing shielded targets",count _shieldedTargets);

#ifdef DEBUG_MODE_FULL
    [_positionASL, _indirectHitRange, _effectiveRange, _ammo, count _shieldedTargets, _shieldedTargets, _unshieldedTargets] call FUNC(debugDrawBlastRadius);
#endif

if (GVAR(mode) isEqualTo "pressure_wave") then {
    // Pressure wave PoC mode — ray-marched simulation
    [_positionASL, _ammo, _adjustedIndirectHit, _indirectHitRange, _effectiveRange, _source] call FUNC(waveSimulation);
} else {
    // Path trace mode (default) — per-frame target processing
    private _processState = [_positionASL, _ammo, _adjustedIndirectHit, _indirectHitRange, _effectiveRange, _shieldedTargets, 0, [], _source];
    [FUNC(processTargets), 0, _processState] call CBA_fnc_addPerFrameHandler;
};
