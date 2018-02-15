/*
    Author:
        Tim Beswick
        
    Description:
        Adds use all action to vehicle class

    Parameters:
        0: Vehicle <OBJECT>

    Return value:
        None
*/
#include "script_component.hpp"

params ["_vehicle"];

private _action = [QGVAR(useAll), "Use All", "", {
    params ["_vehicle", "_unit"];
    private _radios = ([_vehicle] call acre_sys_rack_fnc_getVehicleRacks) apply {[_x] call acre_sys_rack_fnc_getMountedRadio};        
    {
        [_vehicle, _unit, _x] call acre_sys_rack_fnc_startUsingMountedRadio;
    } forEach (_radios select {_x != "" && {!(_x in ACRE_ACCESSIBLE_RACK_RADIOS) || !(_x in ACRE_HEARABLE_RACK_RADIOS)}});
}, {true}] call ace_interact_menu_fnc_createAction;
[_vehicle, 1, ["ACE_SelfActions", "acre_sys_rack_racks"], _action] call ace_interact_menu_fnc_addActionToObject;
