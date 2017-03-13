/*
    Author:
        Glowbal from ACE https://github.com/acemod/ACE3, edited by Tim Beswick

    Description:
        Init module

    Parameter(s):
        0: The logic object <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"

if ((_this select 0) isKindOf "Module_F") then {
    GVAR(moduleInitCollection) pushBack (_this select 0);
};
