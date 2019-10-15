#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Teleports curator to module position

    Parameter(s):
        0: The module logic <OBJECT>

    Return Value:
        None
*/

params ["_logic"];

if (!local _logic) exitWith {};

["ace_zeus_moveToRespawnPosition", [(vehicle player), _logic modelToWorld [0,0,0]], (vehicle player)] call CBA_fnc_targetEvent;

deleteVehicle _logic;
