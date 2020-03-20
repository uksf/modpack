#include "script_component.hpp"
/*
    Author:
        LAxemann, Jokoho482, Tim Beswick

    Description:
        Suppression recovery

    Parameters:
        None

    Return value:
        None
*/

if (GVAR(suppression_threshold) > 0) then {
    private _subtract = call {
        if (GVAR(suppression_haltRecovery) && {(time - GVAR(suppression_lastShotAt)) <= 1.75}) exitWith {0};
        if (GVAR(suppression_suppressed)) exitWith {1.5 * GVAR(suppression_recoveryFactor)};
        2.5 * GVAR(suppression_recoveryFactor)
    };
    GVAR(suppression_threshold) = (GVAR(suppression_threshold) - _subtract) max 0;
};
