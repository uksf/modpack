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
private _action = [QGVAR(ai), "AI", "", {}, {
    params ["", "_selectedObjects"];
    _selectedObjects isNotEqualTo [] && {({isPlayer _x} count _selectedObjects) == 0}
}, [], {
    private _actions = [];

    private _action = [QGVAR(supportRadio), "Remove Support Radio", "", {call FUNC(contextSupportRadio)}, {call FUNC(contextCanSupportRadio)}, [], {}, {call FUNC(contextSupportRadioModifier)}] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 0];

    _action = [QGVAR(caching), "Exclude From Caching", QPATHTOF(ui\Icon_Module_Caching_Exclude_ca.paa), {call FUNC(contextCaching)}, {call FUNC(contextCanCaching)}, [], {}, {call FUNC(contextCachingModifier)}] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 100];

    _action = [QGVAR(virtualisation), "Exclude From Virtualisation", QPATHTOF(ui\Icon_Module_Caching_Exclude_ca.paa), {call FUNC(contextVirtualisationExclude)}, {call FUNC(contextCanVirtualisationExclude)}] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 100];

    _actions
}] call zen_context_menu_fnc_createAction;
[_action, [], 100] call zen_context_menu_fnc_addAction;

_action = [QGVAR(object), "Object", "", {}, {true}, [], {
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

_action = [QGVAR(toggleFPS), "Toggle FPS", "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa", {GVAR(fpsEnabled) = !GVAR(fpsEnabled)}, {isMultiplayer}] call zen_context_menu_fnc_createAction;
[_action, [], -480] call zen_context_menu_fnc_addAction;

_action = [QGVAR(toggleZeusVisibility), "Toggle Zeus Visibility", "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa", {[objNull] call FUNC(moduleToggleZeusVisibility)}, {true}] call zen_context_menu_fnc_createAction;
[_action, [], -500] call zen_context_menu_fnc_addAction;
