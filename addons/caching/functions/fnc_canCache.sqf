/*
    Author:
        Tim Beswick

    Description:
        Checks if group can be cached

    Parameters:
        0: Group to be cached <GROUP>

    Return value:
        Boolean
*/
#include "script_component.hpp"

params [["_group",grpNull]];

!isNull _group &&
!(_group in GVAR(groups)) &&
!(_group getVariable [QGVAR(excluded), false]) &&
([(leader _group), GVAR(distance)] call EFUNC(common,getNearPlayers)) isEqualTo [] &&
isNull ((leader _group) findNearestEnemy (leader _group)) &&
((allPlayers - EGVAR(common,HCs)) select {[(leader _group), _x] call EFUNC(common,lineOfSight)}) isEqualTo []
