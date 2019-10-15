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
*/

params ["_message", ["_admin", false]];

if (_admin && !(ADMIN_OR_HOST)) exitWith {};
[_message] call ace_common_fnc_displayTextStructured;

