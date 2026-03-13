#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Show ace structured message

    Parameter(s):
        0: Message <STRING>
        1: Admin only <BOOL>

    Return Value:
        None

    Example:
        [_message, _admin] call uksf_common_fnc_hint
*/
params ["_message", ["_admin", false]];

if (_admin && !(ADMIN_OR_HOST)) exitWith {};
[_message] call ace_common_fnc_displayTextStructured;

