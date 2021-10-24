#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Checks if oxygen is connected. If not negative effects, if it is then play the sound.

    Parameter(s):
        0: Player <object>

    Return Value:
        Nothing
*/

params ["_player"];

if (GVAR(oxygenConnected)) exitWith {

};

call FUNC(handleEffects);
