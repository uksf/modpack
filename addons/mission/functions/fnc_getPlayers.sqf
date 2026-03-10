#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets players for processing
        Provides debug ability through static array of unit

    Parameters:
        None

    Return value:
        Array of players
        [Players]

    Example:
        call uksf_mission_fnc_getPlayers
*/

#ifdef DEBUG_MODE_ANALYSIS
GVAR(dynamicPatrolDebugPlayers)
#else
call CBA_fnc_players
#endif
