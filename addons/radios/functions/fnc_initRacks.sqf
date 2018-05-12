/*
    Author:
        Tim Beswick
        
    Description:
        Initialises radio racks for vehicles using given channels

    Parameters:
        0: Vehicle <OBJECT>
        1: Channels <ARRAY>

    Return value:
        None
*/
#include "script_component.hpp"

if (!isServer) exitWith {};

[{
    GVAR(presetsDone)
},{
    params ["_vehicle", "_channels"];
    [_vehicle] call acre_api_fnc_initVehicleRacks;
    [{
        params ["_vehicle", "_channels"];
        [_vehicle] call acre_sys_rack_fnc_configureRackIntercom;
        private _radios = ([_vehicle] call acre_api_fnc_getVehicleRacks) apply {[_x] call acre_api_fnc_getMountedRackRadio};
        {
            [_x, _channels select _forEachIndex] call acre_api_fnc_setRadioChannel;
        } forEach (_radios select {_x != ""});
    }, _this, 0.5] call CBA_fnc_waitAndExecute;
}, _this] call CBA_fnc_waitUntilAndExecute;
