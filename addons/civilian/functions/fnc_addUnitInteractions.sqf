#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds interactions to unit

    Parameters:
        0: Unit <OBJECT>

    Return value:
        Nothing
*/
params ["_unit"];

private _action = [QGVAR(unit_ignoreCommands), "Please wait there", "", {
    _target setVariable [QGVAR(unit_ignoreCommands), true, true];
    [QGVAR(stopCommand), [_target], _target] call CBA_fnc_targetEvent;
}, {
    !(_target getVariable [QGVAR(unit_ignoreCommands), false])
}] call ace_interact_menu_fnc_createAction;
[_unit, 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToObject;

_action = [QGVAR(unit_followCommands), "Ok pay attention", "", {
    _target setVariable [QGVAR(unit_ignoreCommands), false, true];
}, {
    _target getVariable [QGVAR(unit_ignoreCommands), false]
}] call ace_interact_menu_fnc_createAction;
[_unit, 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToObject;
