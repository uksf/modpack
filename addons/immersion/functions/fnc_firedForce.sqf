#include "script_component.hpp"
/*
    Author:
        LAxemann, Jokoho482, Tim Beswick

    Description:
        Fired event for firing force

    Parameters:
        Fired Event Parameters

    Return value:
        None
*/

if ((diag_tickTime - GVAR(firing_lastShot)) <= 0.45) then {
    GVAR(firing_multiplier) = (GVAR(firing_multiplier) + 0.005) min 1;
} else {
    GVAR(firing_multiplier) = 0;
};

GVAR(firing_CC) ppEffectAdjust [1, 1, 0, [1, 1, 1, -0.04], [1, 1, 1, 0.9 - (0.25 * GVAR(firing_multiplier))], [0, 0, 0, 0]];
GVAR(firing_CC) ppEffectCommit 0;

GVAR(firing_RBlur) ppEffectAdjust [0.009 + (0.025 * GVAR(firing_multiplier)), 0.09 + (0.01 * GVAR(firing_multiplier)), 0.1 , 0.1 ];
GVAR(firing_RBlur) ppEffectCommit 0;

GVAR(firing_CC) ppEffectAdjust [1, 1, 0, [1, 1, 1, 0], [1, 1, 1, 1], [0, 0, 0, 0]];
GVAR(firing_CC) ppEffectCommit 0.05 + (0.3 * GVAR(firing_multiplier));

GVAR(firing_RBlur) ppEffectAdjust [0, 0, 0, 0];
GVAR(firing_RBlur) ppEffectCommit 0.12 + (0.08 * GVAR(firing_multiplier));
GVAR(firing_lastShot) = diag_tickTime;
