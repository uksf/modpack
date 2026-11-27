#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds the L118 casing bin actions to the UKSF light-gun ammo crates.
        Golf grab boxes sit beside the gun. Romeo crates are the bulk L118 supply.
        Both act as the bin.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_weapons_fnc_l118AddCrateActions
*/
if (!hasInterface) exitWith {};

private _cleanup = [QGVAR(l118CleanCasings), "Clean up casings", "", {
    params ["_crate", "_player"];
    [_crate, _player, "cleanup"] call FUNC(l118BinCasings);
}, {
    params ["_crate", "_player"];
    [_crate, _player, "canCleanup"] call FUNC(l118BinCasings)
}, {}, [], [0, 0, 0], 4] call ace_interact_menu_fnc_createAction;

private _bin = [QGVAR(l118BinCasing), "Bin casing", "", {
    params ["_crate", "_player"];
    [_crate, _player, "bin"] call FUNC(l118BinCasings);
}, {
    params ["_crate", "_player"];
    [_crate, _player, "canBin"] call FUNC(l118BinCasings)
}, {}, [], [0, 0, 0], 4] call ace_interact_menu_fnc_createAction;

{
    [_x, 0, ["ACE_MainActions"], _cleanup, true] call ace_interact_menu_fnc_addActionToClass;
    [_x, 0, ["ACE_MainActions"], _bin, true] call ace_interact_menu_fnc_addActionToClass;
} forEach [
    QEGVAR(resupply,g15),
    QEGVAR(resupply,g16),
    QEGVAR(resupply,g17),
    QEGVAR(resupply,g18),
    QEGVAR(resupply,r8),
    QEGVAR(resupply,r9)
];
