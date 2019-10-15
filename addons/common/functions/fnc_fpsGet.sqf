#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sends FPS value back to given player.

    Parameters:
        0: Return Player <OBJECT>

    Return value:
        None
*/

params ["_player"];

if (isServer) then {
    [QGVAR(fpsSet), [owner player, diag_fps], _player] call CBA_fnc_targetEvent;
} else {
    [QGVAR(fpsSet), [player, diag_fps], _player] call CBA_fnc_targetEvent;
};
