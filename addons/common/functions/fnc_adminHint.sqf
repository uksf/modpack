/*
    Author:
        Tim Beswick

    Description:
        Shows message to admin

    Parameter(s):
        0: Message <STRING>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_message"];

if (ADMIN_OR_HOST) then {
    [_message] call ace_common_fnc_displayTextStructured;
};
