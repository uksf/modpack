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

    Example:
        call uksf_common_fnc_addSelfActions
*/

private _action = [QGVAR(fpsAction), QUOTE(FPS), "\A3\ui_f\data\gui\rsc\rscdisplayoptionsvideo\icon_performance.paa", {call FUNC(fpsToggle)}, {ADMIN_OR_WHITELISTED}] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
