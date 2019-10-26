#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds arsenal to given object with given classes, and adds scroll interaction.

    Parameter(s):
        0: Crate <OBJECT>
        1: Classes <ARRAY,BOOL>

    Return Value:
        None
*/
params ["_crate", ["_classes", true, [[], true]]];

[_crate, true] call ace_arsenal_fnc_removeBox;
[_crate, _classes, false] call ace_arsenal_fnc_initBox;
[QGVAR(addArsenalAction), [_crate]] call CBA_fnc_localEvent;
