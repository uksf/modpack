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

// Check per-ammo blacklist
if (getNumber (configFile >> "CfgAmmo" >> _ammo >> QGVAR(enabled)) isEqualTo 0) exitWith {};

// Calculate explosion power score: indirectHit * sqrt(indirectHitRange)
private _indirectHit = getNumber (configFile >> "CfgAmmo" >> _ammo >> "indirectHit");
private _indirectHitRange = getNumber (configFile >> "CfgAmmo" >> _ammo >> "indirectHitRange");

if (_indirectHit <= 0 || {_indirectHitRange <= 0}) exitWith {};

private _powerScore = _indirectHit * sqrt _indirectHitRange;

if (_powerScore < GVAR(threshold)) exitWith {};

private _effectiveRange = _indirectHitRange * GVAR(rangeMultiplier);

#ifdef DEBUG_MODE_FULL
    private _positionATL = ASLToATL _positionASL;
    diag_log text format [
        "[%1] Explosion: ammo=%2 indirectHit=%3 indirectHitRange=%4 powerScore=%5 effectiveRange=%6 pos=%7",
        ADDON, _ammo, _indirectHit, _indirectHitRange, _powerScore, _effectiveRange, _positionATL
    ];
#endif

// Collect all entities in effective range
private _candidates = (ASLToAGL _positionASL) nearEntities [
    ["CAManBase", "Car", "Motorcycle", "Tank", "StaticWeapon", "Air", "Ship"],
    _effectiveRange
];

// Filter to units that are alive and whose direct LOS to the detonation is blocked
private _shieldedTargets = [];
private _shotParents = getShotParents _projectile;
private _source = _shotParents select !isNull (_shotParents#1);

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
        #ifdef DEBUG_MODE_FULL
            diag_log text format ["[%1] Skipping %2 (direct LOS exists)", ADDON, _x];
        #endif
        continue
    };

    private _directDistance = _positionASL vectorDistance _targetPositionASL;

    _shieldedTargets pushBack [_x, _targetPositionASL, _directDistance];

    #ifdef DEBUG_MODE_FULL
        diag_log text format ["[%1] Shielded target: %2 distance=%3", ADDON, _x, _directDistance];
    #endif
} forEach _candidates;

if (_shieldedTargets isEqualTo []) exitWith {
    #ifdef DEBUG_MODE_FULL
        diag_log text format ["[%1] No shielded targets found", ADDON];
    #endif
};

#ifdef DEBUG_MODE_FULL
    diag_log text format ["[%1] Processing %2 shielded targets", ADDON, count _shieldedTargets];
#endif

#ifdef DEBUG_MODE_FULL
    [_positionASL, _indirectHitRange, _effectiveRange, _ammo, count _shieldedTargets, _shieldedTargets] call FUNC(debugDrawBlastRadius);
#endif

// Queue targets for per-frame processing
// _processState: [positionASL, ammo, indirectHit, indirectHitRange, effectiveRange, shieldedTargets, currentIndex, phase2Queue, source]
private _processState = [_positionASL, _ammo, _indirectHit, _indirectHitRange, _effectiveRange, _shieldedTargets, 0, [], _source];
[FUNC(processTargets), 0, _processState] call CBA_fnc_addPerFrameHandler;
