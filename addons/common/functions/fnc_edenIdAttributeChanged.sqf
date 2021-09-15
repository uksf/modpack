#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets logic ID

    Parameter(s):
        0: Edit control <CONTROL>

    Return Value:
        Nothing
*/
params ["_ctrlEditbox"];

private _logic = (get3DENSelected "logic")#0;
private _id = [_logic] call FUNC(edenSetIdAttribute);

_ctrlEditbox ctrlEnable false;
_ctrlEditbox ctrlSetText _id;
