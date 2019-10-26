#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Packs parachute into backpack

    Parameter(s):
        0: Parachute <OBJECT>
        1: Unit <OBJECT>

    Return Value:
        None
*/
params ["_chute", "_unit"];

deleteVehicle _chute;
createVehicle ["CUP_T10_Parachute_backpack", getPosATLVisual _unit, nil, 0, "CAN_COLLIDE"];
