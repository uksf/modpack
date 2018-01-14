/*
    Author:
        Tim Beswick

    Description:
        Adds all objects to all curators

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

[QEGVAR(common,addObjectsToCurators), []] call CBA_fnc_serverEvent;
["All objects were added to Zeus"] call ace_common_fnc_displayTextStructured;

deleteVehicle _logic;
