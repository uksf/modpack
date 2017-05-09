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

params ["_logic", "_units", "_activated"];

if !(_activated && local _logic) exitWith {};

(vehicle player) setPosATL (getPosATL _logic);

deleteVehicle _logic;
