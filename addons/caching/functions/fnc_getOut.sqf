/*
    Author:
        Tim Beswick

    Description:
        Handles get out

    Parameters:
        0: Vehicle <OBJECT>
        1: Position <STRING>
        2: Unit <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_vehicle", "", "_unit"];

if (group _unit in GVAR(groups)) then {
    group _unit leaveVehicle _vehicle;
};        
