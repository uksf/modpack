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
private _action = [QGVAR(menu), "Virtualisation", QPATHTOEF(zeus,ui\Icon_Module_Caching_ca.paa), {}, {GVAR(enabled)}, [], {
    private _actions = [];

    private _action = [QGVAR(exclude), "Exclude From Virtualisation", "", {call FUNC(contextExclude)}, {call FUNC(contextCanExclude)}, [], {}, {call FUNC(contextExcludeModifier)}] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 100];

    _action = [QGVAR(devirtualise), "Devirtualise Nearby (10m)", "", {call FUNC(contextDevirtualizeNearby)}, {true}, [10], {
        private _actions = [];

        {
            private _radius = _x;

            private _action = [format [QGVAR(devirtualise%1m), _radius], format ["%1m", _radius], "", {call FUNC(contextDevirtualizeNearby)}, {true}, [_radius]] call zen_context_menu_fnc_createAction;
            _actions pushBack [_action, [], -_radius];
        } forEach [10, 100, 250, 500, 1000];

        _actions
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 90];

    _action = [QGVAR(toggleShow), "Show Virtualised", "", {
        GVAR(showVirtualised) = !GVAR(showVirtualised);

        [QGVAR(toggleDataStreamForClient), [player, GVAR(showVirtualised)]] call CBA_fnc_serverEvent;
    }, {true}, [], {}, {
        params ["_action"];

        _action set [1, ["Show Virtualised", "Hide Virtualised"] select GVAR(showVirtualised)];
    }] call zen_context_menu_fnc_createAction;
    _actions pushBack [_action, [], 80];

    _actions
}] call zen_context_menu_fnc_createAction;
[_action, [], 100] call zen_context_menu_fnc_addAction;
