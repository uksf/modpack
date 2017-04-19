/*
    Author:
        Tim Beswick

    Description:
        Adds curator actions to ACE self-interaction for player

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

if (local player && {!(player getVariable [QGVAR(curatorActionsAdded), false])}) then {
    private _action = [QGVAR(curatorActions), QUOTE(Curator), CURATOR_ICON, {}, {true}, {call FUNC(getCuratorActions)}] call ace_interact_menu_fnc_createAction;
    [player, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToObject;
    player setVariable [QGVAR(curatorActionsAdded), true, true];
};
