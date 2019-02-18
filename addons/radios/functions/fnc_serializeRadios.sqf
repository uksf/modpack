#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Serializes unit radio data

    Parameter(s):
        0: Unit <OBJECT>

    Return Value:
        Array of radio data <ARRAY>
        Formatted as: [type, channel, volume, ear]
*/

params ["_unit"];

private _radios = ([_unit] call acre_sys_core_fnc_getGear) select {_x call acre_sys_radio_fnc_isUniqueRadio};

private _radioData = [];
{
    private _type = [_x] call acre_api_fnc_getBaseRadio;
    private _channel = [_x] call acre_api_fnc_getRadioChannel;
    private _volume = [_x] call acre_api_fnc_getRadioVolume;
    private _spatial = [_x] call acre_api_fnc_getRadioSpatial;
    if (!(_volume isEqualType 0)) then {_volume = 1};
    _radioData pushBack [_type, _channel, _volume, _spatial];
} forEach _radios;

_radioData
