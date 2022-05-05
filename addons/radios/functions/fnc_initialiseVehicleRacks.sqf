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

if (!isServer) exitWith {};

if (_vehicle getVariable [QGVAR(channelsSet), false]) exitWith {};

private _channels = _vehicle getVariable [QGVAR(rackChannels), []];
if (_channels isEqualTo []) then {
    _channels = [typeOf _vehicle, {configOf _vehicle >> QGVAR(rackChannels)}, []] call EFUNC(common,readCacheValues);
};

if (_channels isEqualTo []) exitWith {};

[{
    params ["_args", "_idPFH"];
    _args params ["_vehicle", "_channels"];

    if (!alive _vehicle) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if ([_vehicle] call FUNC(isRackInitialisationComplete)) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        _vehicle setVariable [QGVAR(channelsSet), true, true];

        private _radios = ([_vehicle] call acre_api_fnc_getVehicleRacks) apply {[_x] call acre_api_fnc_getMountedRackRadio};
        {
            private _channel = [_x] call acre_api_fnc_getRadioChannel;

            // If radio channel has not been changed, set a channel if one is available
            if (_channel <= 1 && _forEachIndex < count _channels) then {
                [_x, _channels#_forEachIndex] call acre_api_fnc_setRadioChannel;
            };
        } forEach (_radios select {_x != ""});
    };
}, 2, [_vehicle, _channels]] call CBA_fnc_addPerFrameHandler;
