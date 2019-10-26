#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds persistence actions

    Parameter(s):
        None

    Return Value:
        None
*/
params ["_unit"];

private _fnc_children = {
    private _actions = [];

    private _action = [QGVAR(persistenceShutdown), QUOTE(Save and Shutdown), "", {[] call FUNC(shutdown)}, {MULTIPLAYER_ADMIN_OR_WHITELISTED}] call ace_interact_menu_fnc_createAction;
    _actions pushBack [_action, [], _player];

    _actions
};

if (local _unit && {!(_unit getVariable [QGVAR(persistenceActionsAdded), false])}) then {
    private _action = [QGVAR(persistenceActions), QUOTE(Persistence), "", {}, {true}, _fnc_children] call ace_interact_menu_fnc_createAction;
    [_unit, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToObject;
    _unit setVariable [QGVAR(persistenceActionsAdded), true];
};
