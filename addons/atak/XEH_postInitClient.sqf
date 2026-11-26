#include "script_component.hpp"

if (isNil "COMSPEC_ArsenalOverlayEH") then { COMSPEC_ArsenalOverlayEH = -1 };

["acre_sys_mpu5_openGui", {
    ["WAVERELAY"] call comspec_atak_native_fnc_openApp;
}] call CBA_fnc_addEventHandler;

{ [_x, "COMSPEC_ATAK_Phone"] call ace_common_fnc_registerItemReplacement } forEach ["ItemcTab", "ItemAndroid", "ItemMicroDAGR"];
["ItemcTabHCam", "COMSPEC_ATAK_Camera"] call ace_common_fnc_registerItemReplacement;

GVAR(selfBranches) = [["ACE_SelfActions"], ["ACE_SelfActions", "ACE_Equipment"], ["ACE_SelfActions", "ACE_Explosives"]];
GVAR(selfPath) = ["ACE_SelfActions", QGVAR(self)];

["CAManBase", 1, ["ACE_SelfActions"], [QGVAR(self), "ATAK", "\z\comspec_atak_native\addons\main\data\logo_atak.paa", {}, { true }] call ace_interact_menu_fnc_createAction, true] call ace_interact_menu_fnc_addActionToClass;

GVAR(groupSelfActions) = {
    private _tree = ace_interact_menu_ActSelfNamespace getOrDefault [(typeOf ACE_player) call ace_common_fnc_getConfigName, []];
    private _atak = [_tree, GVAR(selfPath)] call ace_interact_menu_fnc_findActionNode;
    if (isNil "_atak") exitWith {};
    private _grouped = (_atak select 1) apply { _x select 0 select 0 };
    {
        private _branch = [_tree, _x] call ace_interact_menu_fnc_findActionNode;
        if (isNil "_branch") then { continue };
        private _children = _branch select 1;
        {
            _x params ["_action", "_actionChildren"];
            private _id = _action select 0;
            if ((_id find "COMSPEC_") isEqualTo 0 && {!(_id in _grouped)}) then {
                (_atak select 1) pushBack [_action, _actionChildren];
                private _stub = +_action;
                _stub set [4, { false }];
                _children set [_forEachIndex, [_stub, _actionChildren]];
                _grouped pushBack _id;
            };
        } forEach _children;
    } forEach GVAR(selfBranches);
    {
        _x params ["_action", "_parentPath"];
        if ((_action select 0 find "COMSPEC_") isEqualTo 0 && {_parentPath in GVAR(selfBranches)}) then {
            _x set [1, +GVAR(selfPath)];
        };
    } forEach (ACE_player getVariable ["ace_interact_menu_selfActions", []]);
};

["ace_interactMenuOpened", {
    params ["_menuType"];
    if (_menuType isEqualTo 1) then { call GVAR(groupSelfActions) };
}] call CBA_fnc_addEventHandler;

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
