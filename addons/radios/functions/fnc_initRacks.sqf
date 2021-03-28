#include "script_component.hpp"
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
params ["_vehicle"];

if (_vehicle getVariable [QGVAR(channelsSet), false]) exitWith {};

private _channels = _vehicle getVariable [QGVAR(rackChannels), []];
private _customChannels = [
    ["UKSF_Apache_AH1", CHANNELS_AIR_FOUR],
    ["UK3CB_BAF_Wildcat_AH1_CAS_6A", CHANNELS_AIR_THREE],
    ["UK3CB_BAF_Wildcat_AH1_CAS_8A", CHANNELS_AIR_THREE],
    ["rksla3_aw159_hma2", CHANNELS_AIR_THREE],
    ["CUP_C130J_Base", CHANNELS_AIR_THREE],
    ["uksf_air_f35_base", CHANNELS_AIR_THREE],
    ["CUP_CH47F_base", CHANNELS_AIR_THREE],
    ["UK3CB_BAF_Merlin_Base", CHANNELS_AIR_THREE],
    ["rksla3_pumahc_base", CHANNELS_AIR_THREE],
    ["UK3CB_BAF_Wildcat_Base", CHANNELS_AIR_THREE],
    ["UK3CB_BAF_MAN_HX60_Base", [40, 48]]
];

if (count _channels == 0) then {
    private _index = _customChannels findIf {_vehicle isKindOf _x#0};
    if (_index != -1) then {
        _channels = (_customChannels#_index)#1;
    };
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
