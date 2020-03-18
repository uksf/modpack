#include "script_component.hpp"
/*
    Author:
        LAxemann, Jokoho482, Tim Beswick

    Description:
        Returns unique ID.

    Parameters:
        0: Factor value <SCALAR>

    Return value:
        None
*/
params ["_factor"];

if !(alive GVAR(suppression_currentUnit)) exitWith {};

_factor = _factor * GVAR(suppression_flybyIntensity);

GVAR(suppression_impactBlur) ppEffectAdjust [(0.023 * _factor), (0.023 * _factor), (0.28 * _factor), (0.28 * _factor)];
GVAR(suppression_impactBlur) ppEffectCommit 0;
GVAR(suppression_impactCC) ppEffectAdjust [1, 1, 0, [0,0,0,(0.6 * _factor)], [1,1,1,1],[1,1,1,0]];
GVAR(suppression_impactCC) ppEffectCommit 0;

GVAR(suppression_impactBlur) ppEffectAdjust [0, 0, 0, 0];
GVAR(suppression_impactBlur) ppEffectCommit (0.3 + (0.5 * _factor));
GVAR(suppression_impactCC) ppEffectAdjust [1, 1, 0, [0,0,0,0], [1,1,1,1],[1,1,1,0]];
GVAR(suppression_impactCC) ppEffectCommit (0.25 + (0.4 * _factor));

// Makes the player twitch if it's been a while since he was getting shot at
if ((time - GVAR(suppression_lastShotAt)) >= 60) then {
    private _power = 3 + (random 0.5) - 0.25;
    private _duration = 0.4 + (random 0.1) - 0.05;
    private _frequency = 80 + (random 10) - 5;
    addCamshake [_power, _duration, _frequency];
};
