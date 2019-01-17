/*
    Author:
        Tim Beswick

    Description:
        If main op gear is enabled, UKSF arsenal crates will load with that gear. If not, a normal arsenal will be used.

    Parameter(s):
        0: Crate <OBJECT>

    Return Value:
        None
*/
#include "script_component.hpp"
#include "\u\uksf\addons\arsenal\script_mainOpGear.hpp"

params ["_crate"];

if (EGVAR(common,mainOp)) then {
    [_crate, uiNamespace getVariable [QGVAR(mainOpGear), MAIN_OP_GEAR]] call FUNC(addArsenal);
} else {
    [_crate] call FUNC(addArsenal);
};
