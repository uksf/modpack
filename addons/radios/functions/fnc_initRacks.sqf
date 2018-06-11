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

[{
    GVAR(presetsDone)
}, {
    params ["_vehicle", "_channels"];

    if (isServer) then {
        [_vehicle] call acre_api_fnc_initVehicleRacks;
        [_vehicle] call acre_sys_rack_fnc_configureRackIntercom;
    };

    [{
        params ["_vehicle"];
        _vehicle getVariable ["acre_sys_rack_initialized", false]
    }, {
        params ["_vehicle", "_channels"];
        
        if (_vehicle getVariable [QGVAR(channelsSet), false]) exitWith {};
        private _radios = ([_vehicle] call acre_api_fnc_getVehicleRacks) apply {[_x] call acre_api_fnc_getMountedRackRadio};
        {
            [_x, _channels select _forEachIndex] call acre_api_fnc_setRadioChannel;
        } forEach (_radios select {_x != ""});
        _vehicle setVariable [QGVAR(channelsSet), true];
    }, _this, 30] call CBA_fnc_waitUntilAndExecute;
}, _this] call CBA_fnc_waitUntilAndExecute;
