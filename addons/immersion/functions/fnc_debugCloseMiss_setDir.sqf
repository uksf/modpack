#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Variant B: snap rotation. Adds a small random yaw offset to the player
        (flashbang-style flinch). Severity scales the magnitude band.

    Parameters:
        0: Severity <SCALAR> (0..1)

    Return value:
        None

    Example:
        [1] call uksf_immersion_fnc_debugCloseMiss_setDir
*/
params [["_severity", 1, [0]]];

private _minYaw = _severity * 2;
private _maxYaw = _severity * 5;
private _flinch = (_minYaw + random (_maxYaw - _minYaw)) * selectRandom [-1, 1];

ACE_player setDir ((getDir ACE_player) + _flinch);

systemChat format ["[immersion debug B] setDir flinch=%1 deg", _flinch];
