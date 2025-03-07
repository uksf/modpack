#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds curator actions to ACE self-interaction

    Parameter(s):
        None

    Return Value:
        None
*/

private _action = [QGVAR(curatorActions), QUOTE(Curator), CURATOR_ICON, {}, {true}, {call FUNC(getCuratorActions)}] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
