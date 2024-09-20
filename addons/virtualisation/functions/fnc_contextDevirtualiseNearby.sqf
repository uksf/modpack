#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Devirtualise any groups in radius from cursor

    Parameter(s):
        0: Action Parameters

    Return Value:
        None
*/
params ["_contextPosition", "", "", "", "", "", "_args"];
_args params ["_radius"];

[QGVAR(devirtualiseNearby), [_contextPosition, _radius]] call CBA_fnc_serverEvent;
