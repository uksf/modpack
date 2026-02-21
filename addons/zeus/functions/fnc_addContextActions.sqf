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

_action = [QGVAR(visualise), "Visualise", "\a3\ui_f_curator\data\logos\arma3_curator_eye_64_ca.paa", {}, {true}, [], {
    private _actions = [];

    private _action = [QGVAR(toggleFPS), "Show Player FPS", "", {GVAR(fpsEnabled) = !GVAR(fpsEnabled)}, {isMultiplayer}, [], {}, {
        params ["_action"];
        _action set [1, ["Show Player FPS", "Hide Player FPS"] select GVAR(fpsEnabled)];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 0];

    _action = [QGVAR(toggleProjectiles), "Show Projectiles", "", {
        GVAR(projectilesEnabled) = !GVAR(projectilesEnabled);
        private _count = count GVAR(trackedProjectiles);
        TRACE_2("toggled projectile tracking",GVAR(projectilesEnabled),_count);
    }, {true}, [], {}, {
        params ["_action"];
        _action set [1, ["Show Projectiles", "Hide Projectiles"] select GVAR(projectilesEnabled)];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], -10];

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
