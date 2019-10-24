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

_fnc_getAiActions = {
    private _actions = [];

    private _action = [QGVAR(supportRadio), "Remove Support Radio", "", {call FUNC(contextSupportRadio)}, {call FUNC(contextCanSupportRadio)}, [], {}, {call FUNC(contextSupportRadioModifier)}] call zen_context_menu_fnc_createAction;
    _actions pushBack _action;

    _action = [QGVAR(caching), "Exclude From Caching", QPATHTOF(ui\Icon_Module_Caching_Exclude_ca.paa), {call FUNC(contextCaching)}, {call FUNC(contextCanCaching)}, [], {}, {call FUNC(contextCachingModifier)}] call zen_context_menu_fnc_createAction;
    _actions pushBack _action;

    _actions
};

_fnc_getObjectActions = {
    private _actions = [];

    private _action = [QGVAR(cleanup), "Exclude From Cleanup", QPATHTOF(ui\Icon_Module_Cleanup_Exclude_ca.paa), {call FUNC(contextCleanup)}, {call FUNC(contextCanCleanup)}, [], {}, {call FUNC(contextCleanupModifier)}] call zen_context_menu_fnc_createAction;
    _actions pushBack _action;

    _actions
};

private _action = [QGVAR(ai), "Ai", "", {}, {true}, [], {call _fnc_getAiActions}] call zen_context_menu_fnc_createAction;
[_action, [], 0] call zen_context_menu_fnc_addAction;

_action = [QGVAR(object), "Object", "", {}, {true}, [], {call _fnc_getObjectActions}] call zen_context_menu_fnc_createAction;
[_action, [], 0] call zen_context_menu_fnc_addAction;
