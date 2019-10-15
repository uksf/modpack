#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds ace self interaction

    Parameter(s):
        None

    Return Value:
        None
*/

if (local player && {!(player getVariable [QGVAR(actionsAdded), false])}) then {
    private _action = [QGVAR(fpsAction), QUOTE(FPS), "\A3\ui_f\data\gui\rsc\rscdisplayoptionsvideo\icon_performance.paa", {call FUNC(fpsToggle)}, {MULTIPLAYER_ADMIN_OR_WHITELISTED}] call ace_interact_menu_fnc_createAction;
    [player, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToObject;
    player setVariable [QGVAR(actionsAdded), true, true];
};
