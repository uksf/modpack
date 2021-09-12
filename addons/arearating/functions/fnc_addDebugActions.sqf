#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds debug actions

    Parameter(s):
        None

    Return Value:
        None
*/

private _fnc_children = {
    private _actions = [];

    private _action = [QGVAR(toggleDebugInfo), "Toggle Map Debug", "", {[] call FUNC(toggleDebugInfo)}, {true}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _actions
};

private _action = [QGVAR(actions), "Ratings", "", {}, {ADMIN_OR_WHITELISTED}, _fnc_children] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
