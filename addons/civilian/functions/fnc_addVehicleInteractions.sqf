#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Adds interactions to vehicle

    Parameters:
        0: Vehicle <OBJECT>

    Return value:
        Nothing
*/
params ["_vehicle"];

private _action = [QGVAR(vehicle_ignoreCommands), "Please wait there", "", {
    _target setVariable [QGVAR(vehicle_ignoreCommands), true, true];
    [QGVAR(stopCommand), [_target], _target] call CBA_fnc_targetEvent;
}, {
    !(_target getVariable [QGVAR(vehicle_ignoreCommands), false])
}, {}, [], [0,0,0], 7, [false, true, false, false, false]] call ace_interact_menu_fnc_createAction;
[_vehicle, 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToObject;

_action = [QGVAR(vehicle_followCommands), "Ok pay attention", "", {
    _target setVariable [QGVAR(vehicle_ignoreCommands), false, true];
}, {
    _target getVariable [QGVAR(vehicle_ignoreCommands), false]
}, {}, [], [0,0,0], 7, [false, true, false, false, false]] call ace_interact_menu_fnc_createAction;
[_vehicle, 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToObject;

private _action = [QGVAR(vehicle_getOut), "Please get out of the vehicle", "", {
    (driver _target) setVariable [QGVAR(unit_stopCommander), _player, true];
    [QGVAR(getOutCommand), [_target], _target] call CBA_fnc_targetEvent;
}, {
    !(isNull (driver _target))
}, {}, [], [0,0,0], 7, [false, true, false, false, false]] call ace_interact_menu_fnc_createAction;
[_vehicle, 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToObject;

_action = [QGVAR(vehicle_getIn), "You may get back in your vehicle", "", {
    private _vehicle = _target getVariable [QGVAR(vehicle_vehicle), objNull];
    [QGVAR(getInCommand), [_vehicle], _vehicle] call CBA_fnc_targetEvent;
}, {
    _target == (vehicle  _target) && {!(isNull (_target getVariable [QGVAR(vehicle_vehicle), objNull]))}
}, {}, [], [0,0,0], 7, [false, true, false, false, false]] call ace_interact_menu_fnc_createAction;
[driver _vehicle, 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToObject;
