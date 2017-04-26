/*
    Author:
        Adam Bridgford

    Description:
        Fires the mortar based on POS

    Parameter(s):
        0: Unit <OBJECT>

    Return Value:
        Nothing
*/

#include "script_component.hpp"

params ["_unit"];

private _enemy = _unit findNearestEnemy _unit;
if (!mortCooldown) then {
    mortar1 commandArtilleryFire [getPosATL _enemy, "8Rnd_82mm_Mo_shells", (floor random [1,4,6])];
    mortCooldown = true;
    [{mortCooldown = false}, [], 120] call CBA_fnc_waitAndExecute;
};
