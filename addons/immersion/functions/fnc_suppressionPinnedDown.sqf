#include "script_component.hpp"
/*
    Author:
        LAxemann, Jokoho482, Tim Beswick

    Description:
        Handles suppression pinned down effects

    Parameters:
        None

    Return value:
        None
*/

if (GVAR(suppression_threshold) >= SUPPRESSION_BORDER) then {
    if (alive GVAR(suppression_currentUnit)) then {
        if !GVAR(suppression_suppressed) then {
            GVAR(suppression_suppressed) = true;
        };
        private _workValue = (GVAR(suppression_intensity) * ((GVAR(suppression_threshold) - SUPPRESSION_BORDER) / (SUPPRESSION_MAX_VALUE - SUPPRESSION_BORDER)));
        addCamShake [_workValue, 2 + _workValue * 23, 1.5];

        GVAR(suppression_blur) ppEffectAdjust [(_workValue * 1.28)];
        GVAR(suppression_blur) ppEffectCommit 0.5;

        GVAR(suppression_cc) ppEffectAdjust [1, 1, 0, [0,0,0,0], [1,1,1,(1 - (_workValue * 0.40))],[1,1,1,0]];
        GVAR(suppression_cc) ppEffectCommit 0.5;

        GVAR(suppression_rBlur) ppEffectAdjust [(_workValue * 0.011), (_workValue * 0.011), 0.2, 0.2];
        GVAR(suppression_rBlur) ppEffectCommit 0.05;
    };
} else {
    if GVAR(suppression_suppressed) then {
        GVAR(suppression_suppressed) = false;
        GVAR(suppression_cc) ppEffectAdjust [1, 1, 0, [0,0,0,0], [1,1,1,1],[1,1,1,0]];
        GVAR(suppression_cc) ppEffectCommit 0;

        GVAR(suppression_blur) ppEffectAdjust [0];
        GVAR(suppression_blur) ppEffectCommit 0.3;

        GVAR(suppression_rBlur) ppEffectAdjust [0, 0, 0, 0];
        GVAR(suppression_rBlur) ppEffectCommit 1;
    };
};
