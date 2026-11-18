#include "script_component.hpp"

["acre_sys_mpu5_openGui", {
    ["WAVERELAY"] call comspec_atak_native_fnc_openApp;
}] call CBA_fnc_addEventHandler;

{ [_x, "COMSPEC_ATAK_Phone"] call ace_common_fnc_registerItemReplacement } forEach ["ItemcTab", "ItemAndroid", "ItemMicroDAGR"];
["ItemcTabHCam", "COMSPEC_ATAK_Camera"] call ace_common_fnc_registerItemReplacement;

["loadout", {
    params ["_unit"];
    private _gps = _unit getSlotItemName 612;
    if !(_gps isKindOf ["ItemcTab", configFile >> "CfgWeapons"]) exitWith {};
    _unit unlinkItem _gps;
    _unit linkItem "ItemGPS";
    [_unit, "COMSPEC_ATAK_Phone"] call ace_common_fnc_addToInventory;
}, true] call CBA_fnc_addPlayerEventHandler;
