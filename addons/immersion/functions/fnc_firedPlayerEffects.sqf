#include "script_component.hpp"
/*
    Author:
        LAxemann, Jokoho482, Tim Beswick

    Description:
        Effects for player firing

    Parameters:
        0: Shooter <OBJECT>
        1: Ammo name <STRING>

    Return value:
        None
*/
params ["_shooter", "_ammo"];

// Exit if:
// Player is not shooter
// Player is in air vehicle
if (
    _shooter != GVAR(suppression_currentUnit) ||
    {(vehicle GVAR(suppression_currentUnit)) isKindOf "Air"}
) exitWith {};

// Use ammo hit value to scale effects (higher hit = heavier effects)
private _hit = [[QGVAR(hit_), _ammo] joinString "", {EGVAR(common,configAmmo) >> _ammo >> "hit"}] call EFUNC(common,readCacheValues);
if (_hit == 0) exitWith {};
private _powerCoefficient = linearConversion [1, 120, _hit, 0.05, 1.2, true];
private _randomness = (random (_powerCoefficient / 10)) - (_powerCoefficient / 10);

// Screen blur and darkening
if ((diag_tickTime - GVAR(firing_lastShot)) <= 0.45) then {
    GVAR(firing_multiplier) = (GVAR(firing_multiplier) + 0.015) min 1;
} else {
    GVAR(firing_multiplier) = 0;
};

// [_hit, _powerCoefficient] call FUNC(testEffects);

private _ccAdjust = (0.9 - (_powerCoefficient * 0.25 * GVAR(firing_multiplier))) + _randomness;
GVAR(firing_CC) ppEffectAdjust [1, 1, 0, [1, 1, 1, -0.04], [1, 1, 1, _ccAdjust], [0, 0, 0, 0]];
GVAR(firing_CC) ppEffectCommit 0;

private _blurAdjust1 = _powerCoefficient * (0.05 + (0.5 * GVAR(firing_multiplier))) + _randomness;
private _blurAdjust2 = _powerCoefficient * (0.2 + (0.05 * GVAR(firing_multiplier))) + _randomness;
GVAR(firing_RBlur) ppEffectAdjust [_blurAdjust1, _blurAdjust2, 0.1, 0.1];
GVAR(firing_RBlur) ppEffectCommit 0;

GVAR(firing_CC) ppEffectAdjust [1, 1, 0, [1, 1, 1, 0], [1, 1, 1, 1], [0, 0, 0, 0]];
GVAR(firing_CC) ppEffectCommit 0.05 + (0.4 * GVAR(firing_multiplier));

GVAR(firing_RBlur) ppEffectAdjust [0, 0, 0, 0];
GVAR(firing_RBlur) ppEffectCommit 0.12 + (0.05 * GVAR(firing_multiplier));
GVAR(firing_lastShot) = diag_tickTime;

// Recoil
private _power = _powerCoefficient * (8 + (random 0.2) - 0.1) + _randomness; // 1.3
private _duration = (0.5 + (random 0.1) - 0.05); // 0.4
private _frequency = _powerCoefficient * (40 + (random 2) - 1) + _randomness; // 15
addCamShake [_power, _duration, _frequency];

// systemChat format ["hit: %1, powcoef: %2, ccadjust: %3, bluradjust1: %4, bluradjust2: %5, shakepow: %6, shakedur: %7, shakefreq: %8", _hit, _powerCoefficient, _ccAdjust, _blurAdjust1, _blurAdjust2, _power, _duration, _frequency];
