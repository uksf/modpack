#include "script_component.hpp"
/*
    Author:
        joko, Tim Beswick

    Description:
        Player Fired Event Handler

    Parameters:
        Fired Event Parameters

    Return value:
        None
*/
params ["_shooter", "_weapon", "", "", "_ammo", "", "_projectile"];

if !(isNull (ACE_controlledUAV#0)) exitWith {};

if ((toLower _weapon) isEqualTo "put" || (toLower _weapon) isEqualTo "throw") exitWith {};

if ((diag_tickTime - GVAR(force_lastShot)) <= 0.45) then {
    GVAR(force_multiplier) = (GVAR(force_multiplier) + 0.025) min 1;
} else {
    GVAR(force_multiplier) = 0;
};

GVAR(force_CC) ppEffectAdjust [1, 1, 0, [1, 1, 1, -0.04], [1, 1, 1, 0.9 - (0.5 * GVAR(force_multiplier))], [0, 0, 0, 0]];
GVAR(force_CC) ppEffectCommit 0;

GVAR(force_RBlur) ppEffectAdjust [0.009 + (0.025 * GVAR(force_multiplier)), 0.09 + (0.025 * GVAR(force_multiplier)), 0.1 , 0.1 ];
GVAR(force_RBlur) ppEffectCommit 0;

GVAR(force_CC) ppEffectAdjust [1, 1, 0, [1, 1, 1, 0], [1, 1, 1, 1], [0, 0, 0, 0]];
GVAR(force_CC) ppEffectCommit 0.05 + (0.65 * GVAR(force_multiplier));

GVAR(force_RBlur) ppEffectAdjust [0, 0, 0, 0];
GVAR(force_RBlur) ppEffectCommit 0.12 + (0.16 * GVAR(force_multiplier));
GVAR(force_lastShot) = diag_tickTime;
