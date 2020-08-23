#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        PostInit for:
            - Set aggression level thresholds

    Parameters:
        None

    Return value:
        Nothing
*/

GVAR(aggressionLevel40) = 40;
GVAR(aggressionLevel160) = 80;
GVAR(aggressionLevel120) = 120;
GVAR(aggressionLevel160) = 160;

call FUNC(removePlayersWhoHaveFired);