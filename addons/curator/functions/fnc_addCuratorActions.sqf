#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds curator actions to ACE self-interaction for unit

    Parameter(s):
        0: Unit

    Return Value:
        None
*/

params ["_unit"];

if (local _unit && {!(_unit getVariable [QGVAR(curatorActionsAdded), false])}) then {
    private _action = [QGVAR(curatorActions), QUOTE(Curator), CURATOR_ICON, {}, {true}, {call FUNC(getCuratorActions)}] call ace_interact_menu_fnc_createAction;
    [_unit, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToObject;
    _unit setVariable [QGVAR(curatorActionsAdded), true, true];
};
