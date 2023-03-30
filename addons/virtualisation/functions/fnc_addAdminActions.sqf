#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds admin actions

    Parameter(s):
        None

    Return Value:
        None
*/

private _fnc_children = {
    private _actions = [];

    private _action = [QGVAR(killswitchToggle), "Killswitch On", "", {
        GVAR(killswitched) = !GVAR(killswitched);
        publicVariable QGVAR(killswitched);

        [QEGVAR(common,log), format ["Virtualisation killswitch %1", ["off", "on"] select GVAR(killswitched)]] call CBA_fnc_serverEvent;
    }, {MULTIPLAYER_ADMIN_OR_WHITELISTED}, {}, nil, nil, nil, [false, false, false, false, false], {
        params ["", "", "", "_actionData"];

        _actionData set [1, ["Killswitch On", "Killswitch Off"] select GVAR(killswitched)];
    }] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _action = [QGVAR(recreateAll), "Recreate all virtualised", "", {
        [QGVAR(recreateAll), []] call CBA_fnc_serverEvent;
    }, {MULTIPLAYER_ADMIN_OR_WHITELISTED && GVAR(killswitched)}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _actions
};

private _action = [QGVAR(actions), "Virtualisation", "", {}, {true}, _fnc_children] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
