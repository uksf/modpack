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
        Formatted as: [type, channel, volume, ear, pttIndex, mpu5]
        mpu5 is [monitors, monitorAudio, txSlots] for an MPU-5 and absent for other radios

    Example:
        [_unit] call uksf_radios_fnc_serializeRadios
*/
params ["_unit"];

private _radios = ([_unit] call acre_sys_core_fnc_getGear) select {_x call acre_sys_radio_fnc_isUniqueRadio};
private _local = local _unit && !isDedicated;
TRACE_2("Unit local?",_unit,_local);
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
    private _volume = [_x] call acre_api_fnc_getRadioVolume;
    private _spatial = [_x] call acre_api_fnc_getRadioSpatial;
    private _ptt = _pttAssignments find _x;
    if (_ptt == -1) then {_ptt = count _pttAssignments + _forEachIndex};
    if (!(_volume isEqualType 0)) then {_volume = 1};
    private _data = [_type, _channel, _volume, _spatial, _ptt];
    if (_type == "ACRE_MPU5" && {!isNil "acre_sys_mpu5_fnc_getTxSlots"}) then {
        private _bridgeReturn = [_x, "getState", "mpu5BridgeReturn"] call acre_sys_data_fnc_dataEvent;
        if (_channel > 16 && {!isNil "_bridgeReturn"}) then {
            _data set [1, _bridgeReturn + 1];
        };
        private _monitorAudio = [_x, "getState", "mpu5MonitorAudio"] call acre_sys_data_fnc_dataEvent;
        if (isNil "_monitorAudio") then {_monitorAudio = []};
        _data pushBack [[_x] call acre_sys_mpu5_fnc_getMonitors, _monitorAudio, [_x] call acre_sys_mpu5_fnc_getTxSlots];
    };
    _radioData pushBack _data;
} forEach _radios;

_radioData
