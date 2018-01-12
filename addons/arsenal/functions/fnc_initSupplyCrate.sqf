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

if (GVAR(mainOpGear)) then {
    [_crate, call compile MAIN_OP_GEAR, false] call ace_arsenal_fnc_initBox;
    // missionnamespace setVariable [QGVAR(mainGear), true, true];
} else {
    [_crate, true, false] call ace_arsenal_fnc_initBox;
};
_crate addAction ["Arsenal", { [_this select 3, player] call ace_arsenal_fnc_openBox; }, _crate, 10, true, true, "", "true", 10];
