/*
    Author:
        Tim Beswick

    Description:
        Adds given NVG class to unit

    Parameter(s):
        0: Unit <OBJECT>
        1: NVG Class <STRING>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params [["_unit", objNull], ["_nvg", ""]];

if (local _unit) then {
    _unit linkItem _nvg;
};
