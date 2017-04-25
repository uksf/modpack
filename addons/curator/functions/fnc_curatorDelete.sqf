/*
    Author:
        Tim Beswick

    Description:
        Deletes given curator object

    Parameter(s):
        0: Curator <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_curator"];

GVAR(curatorObjects) deleteAt (GVAR(curatorObjects) find _curator);
publicVariable QGVAR(curatorObjects);
deleteVehicle _curator;
