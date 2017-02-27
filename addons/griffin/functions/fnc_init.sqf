/*
    Author:
        Tim Beswick

    Description:
        Inits Griffin

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
