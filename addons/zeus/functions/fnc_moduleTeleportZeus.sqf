/*
    Author:
        Tim Beswick

    Description:
        Teleports curator to module position

    Parameter(s):
        0: The module logic <OBJECT>
        1: Synchronized units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_logic", "", "_activated"];

if !(_activated && local _logic) exitWith {
    deleteVehicle _logic;
};

["ace_zeus_moveToRespawnPosition", [(vehicle player), _logic modelToWorld [0,0,0]], (vehicle player)] call CBA_fnc_targetEvent;

deleteVehicle _logic;
