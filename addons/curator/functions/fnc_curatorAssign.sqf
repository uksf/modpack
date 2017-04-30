/*
    Author:
        Tim Beswick

    Description:
        Assigns given curator to given player
        If no curator given, last created is used instead.

    Parameter(s):
        0: Player <OBJECT>
        1: Curator <OBJECT> (Optional)

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_player", ["_curator", objNull]];

if (isNull _curator) then {
    _curator = (GVAR(curatorObjects) select {isNull (getAssignedCuratorUnit _x)}) select 0;
};
_player assignCurator _curator;
