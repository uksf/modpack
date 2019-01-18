/*
    Author:
        Tim Beswick
        
    Description:
        Initialises radio racks for vehicles using given channels

    Parameters:
        0: Vehicle <OBJECT>

    Return value:
        None
*/
#include "script_component.hpp"
        
params ["_vehicle"];

if (_vehicle getVariable [QGVAR(channelsSet), false]) exitWith {};

private _channels = _vehicle getVariable [QGVAR(rackChannels), []];
private _customChannels = [
    ["UKSF_Apache_AH1", CHANNELS_SQN_656],
    ["UK3CB_BAF_Wildcat_AH1_CAS_6A", CHANNELS_SQN_656],
    ["UK3CB_BAF_Wildcat_AH1_CAS_8A", CHANNELS_SQN_656],
    ["CUP_C130J_Base", CHANNELS_SQN_617],
    ["USAF_F35A", CHANNELS_SQN_617],
    ["CUP_CH47F_base", CHANNELS_SQN_7],
    ["UK3CB_BAF_Merlin_Base", CHANNELS_SQN_7],
    ["rksla3_pumahc_base", CHANNELS_SQN_7],
    ["UK3CB_BAF_Wildcat_Base", CHANNELS_SQN_7],
    ["UK3CB_BAF_MAN_HX60_Base", [40, 48]]
];

if (count _channels == 0) then {
    {
        if (_vehicle isKindOf _x#0) exitWith {
            _channels = _x#1;
        };
    } forEach _customChannels;
};

if (count _channels == 0) exitWith {};
[{
    [{
        params ["_vehicle"];
        private _return = false;
        if (_vehicle getVariable ["acre_sys_rack_initialized", false]) then {
            private _radios = ([_vehicle] call acre_api_fnc_getVehicleRacks) apply {[_x] call acre_api_fnc_getMountedRackRadio};
            private _initialisedRadios = ({!([_x] call acre_api_fnc_isBaseRadio)} count _radios);
            if (_initialisedRadios > 0 && {_initialisedRadios == count _radios}) then {
                _return = true;
            };
        };
        _return
    }, {
        params ["_vehicle", "_channels"];
            
        private _radios = ([_vehicle] call acre_api_fnc_getVehicleRacks) apply {[_x] call acre_api_fnc_getMountedRackRadio};
        {
            [_x, _channels#_forEachIndex] call acre_api_fnc_setRadioChannel;
        } forEach (_radios select {_x != ""});
        _vehicle setVariable [QGVAR(channelsSet), true, true];
    }, _this, 30] call CBA_fnc_waitUntilAndExecute;
}, [_vehicle, _channels], 1] call CBA_fnc_waitAndExecute;
