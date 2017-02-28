/*
    Author:
        Tim Beswick

    Description:
        Adds full arsenal to object

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"
#include "\achilles\modules_f_ares\module_header.hpp"

_unitUnderCursor = [_logic] call Ares_fnc_GetUnitUnderCursor;
if (!(isNull _unitUnderCursor)) then {
    ["AmmoboxInit", [_unitUnderCursor, true]] spawn EFUNC(arsenal,arsenal);
    ["Arsenal Added"] call Ares_fnc_ShowZeusMessage;
} else {
    ["Must be placed on an object."] call Ares_fnc_ShowZeusMessage;
};

#include "\achilles\modules_f_ares\module_footer.hpp"
