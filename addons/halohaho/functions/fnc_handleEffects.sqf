#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Determines if any effects are needed based on diving state

    Parameter(s):
        None

    Return Value:
        None
*/

/*
if (GVAR(noAirTimeout) <= 0) exitWith {
    player setDamage 1;
};
*/

call FUNC(effectToxicO2);



/*
if (GVAR(currentDepth) > GVAR(maxDepth)) then {
    GVAR(toxicO2Timeout) = GVAR(toxicO2Timeout) - 1;
    if (GVAR(toxicO2Timeout) == 0) then {
        call FUNC(effectToxicO2);
        GVAR(toxicO2Timeout) = 2;
    };
};
*/
