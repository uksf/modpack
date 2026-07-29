#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds ZEN context actions for virtualisation: exclude group from virt,
        and devirtualise nearby groups in a chosen radius.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_virtualisation_fnc_addContextActions
*/
private _action = [QGVAR(menu), "Virtualisation", QPATHTOEF(zeus,ui\Icon_Module_Caching_ca.paa), {}, {GVAR(enabled)}, [], {
    private _actions = [];

    private _action = [QGVAR(exclude), "Exclude From Virtualisation", "", {call FUNC(contextExclude)}, {call FUNC(contextCanExclude)}, [], {}, {call FUNC(contextExcludeModifier)}] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 100];

    _action = [QGVAR(devirtualise), "Devirtualise Nearby (10m)", "", {call FUNC(contextDevirtualiseNearby)}, {true}, [10], {
        private _actions = [];

        {
            private _radius = _x;

            private _action = [format [QGVAR(devirtualise%1m), _radius], format ["%1m", _radius], "", {call FUNC(contextDevirtualiseNearby)}, {true}, [_radius]] call zen_context_menu_fnc_createAction;
            _actions pushBack [_action, [], -_radius];
        } forEach [10, 100, 250, 500, 1000];

        _actions
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 90];

    _actions
}] call zen_context_menu_fnc_createAction;
[_action, [], 100] call zen_context_menu_fnc_addAction;
