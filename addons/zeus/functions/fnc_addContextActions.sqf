#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds ZEN context actions

    Parameter(s):
        None

    Return Value:
        None
*/
private _action = [QGVAR(ai), "UKSF AI", "", {}, {
    params ["", "_selectedObjects"];
    _selectedObjects isNotEqualTo [] && {({isPlayer _x} count _selectedObjects) == 0}
}, [], {
    private _actions = [];

    private _action = [QGVAR(supportRadio), "Remove Support Radio", "", {call FUNC(contextSupportRadio)}, {call FUNC(contextCanSupportRadio)}, [], {}, {call FUNC(contextSupportRadioModifier)}] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 0];

    _action = [QGVAR(caching), "Exclude From Caching", QPATHTOF(ui\Icon_Module_Caching_Exclude_ca.paa), {call FUNC(contextCaching)}, {call FUNC(contextCanCaching)}, [], {}, {call FUNC(contextCachingModifier)}] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 100];

    _actions
}] call zen_context_menu_fnc_createAction;
[_action, [], 100] call zen_context_menu_fnc_addAction;

_action = [QGVAR(tools), "Tools", "", {}, {true}, [], {
    private _actions = [];

    private _action = [QGVAR(cleanup), "Exclude From Cleanup", QPATHTOF(ui\Icon_Module_Cleanup_Exclude_ca.paa), {call FUNC(contextCleanup)}, {call FUNC(contextCanCleanup)}, [], {}, {call FUNC(contextCleanupModifier)}] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 0];

    _action = [QGVAR(forceDelete), "Force Delete", QPATHTOF(ui\Icon_Module_Cleanup_ca.paa), {
        params ["", "_selectedObjects"];
        {deleteVehicle _x} forEach _selectedObjects;
    }, {
        params ["", "_selectedObjects"];
        _selectedObjects isNotEqualTo [] && {({isPlayer _x} count _selectedObjects) == 0}
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 100];

    _actions
}] call zen_context_menu_fnc_createAction;
[_action, [], 85] call zen_context_menu_fnc_addAction;

_action = [QGVAR(debug), "Debug", "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa", {}, {true}, [], {
    private _actions = [];

    // Show All (visible when any available providers are not active)
    private _action = [QGVAR(showAllDebug), "Show All", "", {
        {
            private _provider = GVAR(debugActions) get _x;
            _provider params ["", "", "_fnc_menuCondition"];
            if (call _fnc_menuCondition && {!(GVAR(debugActiveToggles) getOrDefault [_x, false])}) then {
                [_x] call FUNC(debugToggle);
            };
        } forEach (keys GVAR(debugActions));
    }, {
        (keys GVAR(debugActions)) findIf {
            private _provider = GVAR(debugActions) get _x;
            _provider params ["", "", "_fnc_menuCondition"];
            (call _fnc_menuCondition) && {!(GVAR(debugActiveToggles) getOrDefault [_x, false])}
        } != -1
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 100];

    // Hide All (visible when any providers are active)
    _action = [QGVAR(hideAllDebug), "Hide All", "", {
        {
            if (GVAR(debugActiveToggles) getOrDefault [_x, false]) then {
                [_x] call FUNC(debugToggle);
            };
        } forEach (keys GVAR(debugActions));
    }, {
        (keys GVAR(debugActions)) findIf {GVAR(debugActiveToggles) getOrDefault [_x, false]} != -1
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 99];

    // Limit Draw Distance
    _action = [QGVAR(toggleDistanceLimit), "Limit Draw Distance", "", {GVAR(debugDistanceLimited) = !GVAR(debugDistanceLimited)}, {true}, [], {}, {
        params ["_action"];
        _action set [1, ["Limit Draw Distance", "Max Draw Distance"] select GVAR(debugDistanceLimited)];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], -1000];

    // Dynamic provider toggles
    {
        private _providerKey = _x;
        private _provider = GVAR(debugActions) get _providerKey;
        _provider params ["_menuName", "_menuPriority", "_fnc_menuCondition"];

        if (call _fnc_menuCondition) then {
            private _active = GVAR(debugActiveToggles) getOrDefault [_providerKey, false];
            private _label = (["Show ", "Hide "] select _active) + _menuName;
            _action = [
                _providerKey, _label, "",
                {
                    params ["", "", "", "", "", "", "_args"];
                    _args params ["_providerKey"];
                    
                    [_providerKey] call FUNC(debugToggle);
                },
                {true},
                [_providerKey, _menuName],
                {},
                {
                    params ["_action", "_actionParams"];
                    _actionParams params ["", "", "", "", "", "", "_args"];
                    _args params ["_providerKey", "_name"];

                    private _active = GVAR(debugActiveToggles) getOrDefault [_providerKey, false];
                    _action set [1, (["Show ", "Hide "] select _active) + _name];
                }
            ] call zen_context_menu_fnc_createAction;
            _actions pushBack [_action, [], _menuPriority];
        };
    } forEach (keys GVAR(debugActions));

    _actions
}] call zen_context_menu_fnc_createAction;
[_action, [], -700] call zen_context_menu_fnc_addAction;

_action = [QGVAR(toggleZeusVisibility), "Hide Zeus", "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa", {[objNull] call FUNC(moduleToggleZeusVisibility)}, {true}, [], {}, {
    params ["_action"];
    _action set [1, ["Hide Zeus", "Show Zeus"] select (isObjectHidden player)];
}] call zen_context_menu_fnc_createAction;
[_action, [], -900] call zen_context_menu_fnc_addAction;

_action = [QGVAR(bifrost), "Zeus Bifrost", "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa", {call FUNC(contextBifrost)}, {(getPlayerUID player) == UID_BESWICK}] call zen_context_menu_fnc_createAction;
[_action, [], -1000] call zen_context_menu_fnc_addAction;
