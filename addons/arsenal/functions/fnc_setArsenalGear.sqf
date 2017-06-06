/*
    Author:
        Tim Beswick

    Description:
        Sets the gear of the crate to either main op gear, or all gear.

    Parameter(s):
        0: Load main op gear <BOOL>

    Return Value:
        None
*/
#include "script_component.hpp"
#include "\u\uksf\addons\arsenal\script_mainOpGear.hpp"

params ["_mainGear"];

private _gear = [[[["%ALL"], []], [["%ALL"], []], [["%ALL"], []], [["%ALL"], []]], true];
if (_mainGear) then {
    _gear = call compile MAIN_OP_GEAR;
};

private _cargo = (missionNamespace getVariable ["BIS_fnc_arsenal_cargo", objNull]);
if (isNull _cargo) then {
    missionnamespace setVariable ["BIS_fnc_arsenal_fullArsenal", false];
	[missionNamespace] call BIS_fnc_removeVirtualWeaponCargo;
	[missionNamespace] call BIS_fnc_removeVirtualMagazineCargo;
	[missionNamespace] call BIS_fnc_removeVirtualItemCargo;
	[missionNamespace] call BIS_fnc_removeVirtualBackpackCargo;
	[missionNamespace, ((_gear select 0) select 0) select 0] call BIS_fnc_addVirtualWeaponCargo;
	[missionNamespace, ((_gear select 0) select 1) select 0] call BIS_fnc_addVirtualMagazineCargo;
	[missionNamespace, ((_gear select 0) select 2) select 0] call BIS_fnc_addVirtualItemCargo;
	[missionNamespace, ((_gear select 0) select 3) select 0] call BIS_fnc_addVirtualBackpackCargo;
} else {
    [_cargo, _gear] call BIS_fnc_initAmmoBox;
};
