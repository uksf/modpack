#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Variant A: physical impulse on player body, perpendicular to player
        look direction, with setUnconscious=false to keep them on their feet.
        Magnitude scales with severity. Direction randomised left/right.

    Parameters:
        0: Severity <SCALAR> (0..1)

    Return value:
        None

    Example:
        [1] call uksf_immersion_fnc_debugCloseMiss_addForce
*/
params [["_severity", 1, [0]]];

private _magnitude = _severity * 80;

private _dir = getDir ACE_player;
private _side = selectRandom [-1, 1];
private _perp = [sin (_dir + 90 * _side), cos (_dir + 90 * _side), 0];
private _impulse = _perp vectorMultiply _magnitude;

private _selection = "head";
private _position = ACE_player selectionPosition _selection;

ACE_player addForce [_impulse, _position, false];

systemChat format ["[immersion debug A] addForce mag=%1 dir=%2 selection=%3", _magnitude, _perp, _selection];
