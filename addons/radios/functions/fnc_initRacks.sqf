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
if (_channels isEqualTo []) then {
    private _channelsConfig = configOf _vehicle >> QGVAR(rackChannels);
    if (isArray _configChannels) then {
        _channels = getArray _configChannels;
    };
};

if (_channels isEqualTo []) exitWith {};

_vehicle setVariable [QGVAR(channelsSet), true, true];
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
    }, _this, 30, {
        params ["_vehicle"];

        _vehicle setVariable [QGVAR(channelsSet), false, true];
    }] call CBA_fnc_waitUntilAndExecute;
}, [_vehicle, _channels], 1] call CBA_fnc_waitAndExecute;
