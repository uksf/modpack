#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks if all rack radios for a vehicle are initialized and have an ID

    Parameters:
        0: Vehicle <OBJECT>

    Return value:
        Initialized <BOOLEAN>
*/
params ["_vehicle"];

if !(_vehicle getVariable ["acre_sys_rack_initialized", false]) exitWith {false};

private _baseRadios = ([_vehicle] call acre_api_fnc_getVehicleRacks) apply {[_x] call acre_api_fnc_getMountedRackRadio} select {[_x] call acre_api_fnc_isBaseRadio};

_baseRadios isEqualTo []
