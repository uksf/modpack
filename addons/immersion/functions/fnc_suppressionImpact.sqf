#include "script_component.hpp"
/*
    Author:
        LAxemann, Jokoho482, Tim Beswick

    Description:
        Returns unique ID.

    Parameters:
        0: Ammo hit value <SCALAR>
        1: Factor value <SCALAR>

    Return value:
        None
*/
params ["_hit", "_factor"];

if !(alive GVAR(suppression_currentUnit)) exitWith {};

private _powerCoefficient = linearConversion [1, 120, _hit, 0.5, 1.25, true];
private _randomness = (random (_powerCoefficient / 10)) - (_powerCoefficient / 10);
_factor = _factor * GVAR(suppression_flybyIntensity);

private _blurAdjust = _powerCoefficient * (0.5 * _factor) + _randomness;
GVAR(suppression_impactBlur) ppEffectAdjust [_blurAdjust, _blurAdjust, _blurAdjust, _blurAdjust];
GVAR(suppression_impactBlur) ppEffectCommit 0;

private _ccAdjust = _powerCoefficient * _factor + _randomness;
GVAR(suppression_impactCC) ppEffectAdjust [1, 1, 0, [0, 0, 0, _ccAdjust], [1, 1, 1, 1], [1, 1, 1, 0]];
GVAR(suppression_impactCC) ppEffectCommit 0;

GVAR(suppression_impactBlur) ppEffectAdjust [0, 0, 0, 0];
GVAR(suppression_impactBlur) ppEffectCommit (0.3 + (0.5 * _factor));

GVAR(suppression_impactCC) ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [1, 1, 1, 1], [1, 1, 1, 0]];
GVAR(suppression_impactCC) ppEffectCommit (0.25 + (0.4 * _factor));

// Makes the player twitch if it's been a while since he was getting shot at
if ((time - GVAR(suppression_lastShotAt)) >= 60) then {
    private _power = _powerCoefficient * (6 + (random 0.5) - 0.25) + _randomness; // 3
    private _duration = (0.5 + (random 0.1) - 0.05); // 0.4
    private _frequency = _powerCoefficient * (80 + (random 10) - 5) + _randomness; // 80
    addCamshake [_power, _duration, _frequency];
};
