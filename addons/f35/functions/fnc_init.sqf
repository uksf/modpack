/*
    Author:
        Tim Beswick, eRazeri, USAF Team

    Description:
        Inits F-35

    Parameters:
        0: Plane <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_plane"];

GVAR(afterBurnerOn) = false;
GVAR(afterBurnerMultiplier) = 0.4;

if (local _plane) then {
    if ((driver _plane) isEqualTo player) then {
        [_plane] call FUNC(getIn);
    };
};
