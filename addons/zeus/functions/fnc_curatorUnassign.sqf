/*
    Author:
        Tim Beswick

    Description:
        Unassigns given curator

    Parameter(s):
        0: Curator <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_curator"];

unassignCurator _curator;
if (isMultiplayer) then {
    [QGVAR(curatorDelete), [_curator]] call CBA_fnc_serverEvent;
};
