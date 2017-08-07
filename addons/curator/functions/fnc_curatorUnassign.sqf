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

private _index = QGVAR(curatorObjects) find _curator;
if (_index > -1) then {
    unassignCurator (QGVAR(curatorObjects) select _index);
    publicVariable QGVAR(curatorObjects);
};
