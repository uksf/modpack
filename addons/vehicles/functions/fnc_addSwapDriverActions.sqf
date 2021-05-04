#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds ace interactions to swap with unconscious driver

    Parameter(s):
        None

    Return Value:
        None
*/

private _action = [QGVAR(swapDriver), "Swap With Driver", "A3\ui_f\data\IGUI\RscIngameUI\RscUnitInfo\role_driver_ca.paa", {call FUNC(swapDriver)}, {call FUNC(canSwapDriver)}] call ace_interact_menu_fnc_createAction;
["Car", 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
