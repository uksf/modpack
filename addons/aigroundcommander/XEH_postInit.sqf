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

GVAR(aggressionLevel20) = 40;
GVAR(aggressionLevel40) = 80;
GVAR(aggressionLevel60) = 120;
GVAR(aggressionLevel80) = 160;

call FUNC(removePlayersWhoHaveFired);