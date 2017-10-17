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
    if (local _crate) then {
        private _data = call compile MAIN_OP_GEAR;
        _data params [["_input", [], [[]]]];
        clearWeaponCargoGlobal _crate;
        clearMagazineCargoGlobal _crate;
        clearBackpackCargoGlobal _crate;
        clearItemCargoGlobal _crate;
        _crate call BIS_fnc_removeVirtualItemCargo;
        _crate call BIS_fnc_removeVirtualWeaponCargo;
        _crate call BIS_fnc_removeVirtualMagazineCargo;
        _crate call BIS_fnc_removeVirtualBackpackCargo;
        ["AmmoboxInit", _crate] spawn BIS_fnc_arsenal;
        [_crate, (_input select 0) select 0, true] call BIS_fnc_addVirtualWeaponCargo;
        [_crate, (_input select 1) select 0, true] call BIS_fnc_addVirtualMagazineCargo;
        [_crate, (_input select 2) select 0, true] call BIS_fnc_addVirtualItemCargo;
        [_crate, (_input select 3) select 0, true] call BIS_fnc_addVirtualBackpackCargo;
        missionnamespace setVariable [QGVAR(mainGear), true, true];
    };
} else {
    ["AmmoboxInit", [_crate, true]] spawn BIS_fnc_arsenal;
};


