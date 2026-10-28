#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Shows lines of text in an app's structured text control.

    Parameter(s):
        0: Structured text control <CONTROL>
        1: Lines <ARRAY of STRING>

    Return Value:
        Nothing

    Example:
        [_info, ["Distance: 1.2 km", "Foot: 14 min"]] call uksf_ctab_fnc_setInfo
*/
params ["_info", "_lines"];

if (isNull _info) exitWith {};

_info ctrlSetStructuredText parseText (_lines joinString "<br/>");
