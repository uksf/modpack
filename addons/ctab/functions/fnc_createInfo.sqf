#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates a structured text control inside an app's content group, for app output that spans several lines.

    Parameter(s):
        0: App content group <CONTROL>
        1: Position as [x, y, w, h] fractions of the group <ARRAY>

    Return Value:
        Structured text control <CONTROL>

    Example:
        [_group, [0, 0.1, 1, 0.5]] call uksf_ctab_fnc_createInfo
*/
params ["_group", "_rect"];

[_group, "RscStructuredText", _rect] call FUNC(createCtrl)
