/*
    Author:
        Tim Beswick

    Description:
        Init module settings

    Parameter(s):
        0: Module logic <LOGIC>
        1: Units <ARRAY>
        2: Activated <BOOLEAN>

    Return Value:
        None
*/
#include "script_component.hpp"

params ["_logic","_units", "_activated"];

if !(_activated) exitWith {};

[_logic, QGVAR(ID), "id"] call ace_common_fnc_readSettingFromModule;
