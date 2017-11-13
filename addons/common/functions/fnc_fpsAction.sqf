/*
    Author:
        Tim Beswick

    Description:
        Adds ace self interaction for admin to display server + HC fps

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

if (local player && !(player getVariable [QGVAR(fpsActionAdded), false])) then {
    private _action = [QGVAR(fpsAction), QUOTE(FPS), "\A3\ui_f\data\gui\rsc\rscdisplayoptionsvideo\icon_performance.paa", {call FUNC(fpsToggle)}, {MULTIPLAYER_ADMIN_OR_WHITELISTED}] call ace_interact_menu_fnc_createAction;
    [player, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToObject;
    player setVariable [QGVAR(fpsActionAdded), true, true];
};
