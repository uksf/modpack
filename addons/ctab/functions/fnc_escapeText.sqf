#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Escapes text for structured text, so a name that holds &, <, or > shows as typed.

    Parameter(s):
        0: Text <STRING>

    Return Value:
        Escaped text <STRING>

    Example:
        [name player] call uksf_ctab_fnc_escapeText
*/
params ["_text"];

_text = [_text, "&", "&amp;"] call CBA_fnc_replace;
_text = [_text, "<", "&lt;"] call CBA_fnc_replace;
[_text, ">", "&gt;"] call CBA_fnc_replace
