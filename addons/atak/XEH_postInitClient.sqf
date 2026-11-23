#include "script_component.hpp"

["acre_sys_mpu5_openGui", {
    ["WAVERELAY"] call comspec_atak_native_fnc_openApp;
}] call CBA_fnc_addEventHandler;

{ [_x, "COMSPEC_ATAK_Phone"] call ace_common_fnc_registerItemReplacement } forEach ["ItemcTab", "ItemAndroid", "ItemMicroDAGR"];
["ItemcTabHCam", "COMSPEC_ATAK_Camera"] call ace_common_fnc_registerItemReplacement;

["zen_curatorDisplayLoaded", {
    private _actions = missionNamespace getVariable ["zen_context_menu_actions", []];
    private _comspec = _actions select { ((_x select 0 select 0) find "comspec_") isEqualTo 0 };
    if (_comspec isEqualTo []) exitWith {};
    if (_actions findIf { (_x select 0 select 0) isEqualTo QGVAR(zeus) } < 0) then {
        [[QGVAR(zeus), "ATAK", "\z\comspec_atak_native\addons\main\data\app_ew.paa", {}, { true }] call zen_context_menu_fnc_createAction, [], 6] call zen_context_menu_fnc_addAction;
    };
    private _children = _actions select (_actions findIf { (_x select 0 select 0) isEqualTo QGVAR(zeus) }) select 1;
    {
        _actions deleteAt (_actions find _x);
        _children pushBack _x;
    } forEach _comspec;
    [_children, 2, false] call CBA_fnc_sortNestedArray;
}] call CBA_fnc_addEventHandler;

["loadout", {
    params ["_unit"];
    private _gps = _unit getSlotItemName 612;
    if !(_gps isKindOf ["ItemcTab", configFile >> "CfgWeapons"]) exitWith {};
    _unit unlinkItem _gps;
    _unit linkItem "ItemGPS";
    [_unit, "COMSPEC_ATAK_Phone"] call ace_common_fnc_addToInventory;
}, true] call CBA_fnc_addPlayerEventHandler;
