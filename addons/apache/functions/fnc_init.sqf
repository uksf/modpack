/*
    Author:
        Tim Beswick

    Description:
        Inits Apache

    Parameters:
        0: Heli <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_heli"];

if (player in _heli) then {
    [_heli] call FUNC(getIn);
};

_heli setVariable [QGVAR(jammerMode), 0, true];
