/*
    Author:
        Adam Bridgford

    Description:
        Mortar test

    Parameter(s):
        0: Unit <OBJECT>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_unit"];

diag_log _this;
diag_log _unit;

if (!(_unit getVariable [QGVAR(isRTO), false])) exitWith {
    diag_log format ["This unit is NOT an RTO: %1", _unit];
};

diag_log format ["This unit is an RTO: %1", _unit];
