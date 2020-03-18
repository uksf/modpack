#include "script_component.hpp"
/*
    Author:
        LAxemann, Jokoho482, Tim Beswick

    Description:
        Fired event for firing recoil

    Parameters:
        Fired Event Parameters

    Return value:
        None
*/

private _power = 1.3 + (random 0.2) - 0.1;
private _duration = 0.4 + (random 0.1) - 0.05;
private _frequency = 15 + (random 2) - 1;
addCamshake [_power, _duration, _frequency];
