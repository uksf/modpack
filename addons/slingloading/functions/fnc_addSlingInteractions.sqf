/*
    Author:
        Tim Beswick

    Description:
        Adds main and self interactions to helicopter for sling loading

    Parameter(s):
        0: Heli <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

if (!hasInterface) exitWith {};

params ["_heli"];

// Main
// Deploy ropes
deleteVehicle helper;
ropeDestroy testrope;
_center = getCenterOfMass heli;
_center set [2, -1];
testrope = ropeCreate [heli, [0,-2,0], 10];
_ends = ropeEndPosition testrope;
helper = createVehicle ["Land_Can_V2_F", _ends select 1, [], 0, "CAN_COLLIDE"];
hideObject helper;
[helper,[0,0,0],[0,0,-1]] ropeAttachTo testrope;
_action = ["Test", "Grab", "", {
    helper attachTo [player, [0,0,0], "RightHand"];
}, {true}, {}, [], [0,0,0]] call ace_interact_menu_fnc_createAction;
[testrope, 0, [], _action] call ace_interact_menu_fnc_addActionToObject;

deleteVehicle helper;
ropeDestroy testrope;
_center = getCenterOfMass heli;
_center set [2, -1];
testrope = ropeCreate [heli, _center, 7];
_ends = ropeEndPosition testrope;
_action = ["Test", "Grab", "", {
    [test,[0,0,0],[0,0,-1]] ropeAttachTo testrope;
}, {true}] call ace_interact_menu_fnc_createAction;
[testrope, 0, [], _action] call ace_interact_menu_fnc_addActionToObject;

// Self
