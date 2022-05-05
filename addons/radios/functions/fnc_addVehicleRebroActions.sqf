#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds actions to enable/disable re-broadcasting for a vehicle

    Parameter(s):
        0: Vehicle type <OBJECT>

    Return Value:
        None
*/
params ["_vehicleType"];

private _action = [QGVAR(enableRebro), "Enable Radio Re-broadcasting", "", {
    [QGVAR(initialiseRebroStation), [_target]] call CBA_fnc_serverEvent;
    "Radio re-broadcasting enabled" call CBA_fnc_notify;
}, {
    !(_target in GVAR(rebroStations))
}] call ace_interact_menu_fnc_createAction;
[_vehicleType, 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

_action = [QGVAR(disableRebro), "Disable Radio Re-broadcasting", "", {
    [QGVAR(deinitialiseRebroStation), [_target]] call CBA_fnc_serverEvent;
    "Radio re-broadcasting disabled" call CBA_fnc_notify;
}, {
    _target in GVAR(rebroStations)
}] call ace_interact_menu_fnc_createAction;
[_vehicleType, 1, ["ACE_SelfActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;
