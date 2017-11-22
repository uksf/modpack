/*
    Author:
        Tim Beswick

    Description:
        Deletes corpse quicker than cleanup

    Parameter(s):
        0: Unit <OBJECT>
        1: Corpse <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["", "_corpse"];

[QEGVAR(common,waitAndDelete), [_corpse, 30]] call CBA_fnc_serverEvent;
