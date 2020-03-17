#include "script_component.hpp"
/*
    Author:
        joko, Tim Beswick

    Description:
        Player Fired Event Handler

    Parameters:
        Fired Event Parameters

    Return value:
        None
*/
params ["", "_weapon"];

if (!(isNull (ACE_controlledUAV#0)) || {GVAR(zeusOpen)}) exitWith {};

if ((toLower _weapon) isEqualTo "put" || (toLower _weapon) isEqualTo "throw") exitWith {};

private _power = 1.3 + (random 0.2) - 0.1;
private _duration = 0.4 + (random 0.1) - 0.05;
private _frequency = 15 + (random 2) - 1;
addCamshake [_power, _duration, _frequency];
