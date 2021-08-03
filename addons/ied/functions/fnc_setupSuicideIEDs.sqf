#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        sets up

    Parameters:
        0: _civilian <OBJECT>

    Return value:
        Nothing
*/
params ["_civilian"];

private _chance = random 10;

if (_chance < 4) then {
    private _group = createGroup EAST;
    [_civilian] join _group;
    [_civilian, false, false] call EFUNC(special,suicide);
};
