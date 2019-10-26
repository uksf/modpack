#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Serializes unit radio data
        PTT indices will not be saved if the unit is not local

    Parameter(s):
        0: Unit <OBJECT>

    Return Value:
        Array of radio data <ARRAY>
        Formatted as: [type, channel, volume, ear, pttIndex]
*/
params ["_unit"];

private _radios = ([_unit] call acre_sys_core_fnc_getGear) select {_x call acre_sys_radio_fnc_isUniqueRadio};
private _local = local _unit;
private _pttAssignments = [];
if (_local) then {
    _pttAssignments = +ACRE_ASSIGNED_PTT_RADIOS;
    if (_pttAssignments isEqualTo []) then {
        _pttAssignments = call acre_sys_data_fnc_getPlayerRadioList;
    };
};

private _radioData = [];
{
    private _type = [_x] call acre_api_fnc_getBaseRadio;
    private _channel = [_x] call acre_api_fnc_getRadioChannel;
    private _volume = ([_x] call acre_api_fnc_getRadioVolume)^(1/3);
    private _spatial = [_x] call acre_api_fnc_getRadioSpatial;
    private _ptt = [0, _pttAssignments find _x] select (count _pttAssignments == count _radios);
    if (!(_volume isEqualType 0)) then {_volume = 1};
    _radioData pushBack [_type, _channel, _volume, _spatial, _ptt];
} forEach _radios;

_radioData
