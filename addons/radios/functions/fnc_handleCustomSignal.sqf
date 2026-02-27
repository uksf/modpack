#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles custom signal calculation for rebroadcasting stations and jamming :TM:

    Parameter(s):
        0: Radio frequency <SCALAR>
        1: Radio power <SCALAR>
        2: Receiving radio ID <STRING>
        3: Transmitting radio ID <STRING>

    Return Value:
        [Power, dBm]
*/
params ["_frequency", "_power", "_receiverId", "_transmitterId"];

private _bestResult = [0, -992];
private _originalResult = call acre_sys_signal_fnc_getSignalCore;

_bestResult = +_originalResult;
_bestResult params ["_bestPx", "_bestSignal"];

private _bestRebroStation = objNull;

if (GVAR(useRebros)) then {
    GVAR(rebroStations) = GVAR(rebroStations) select {alive _x};

    {
        private _result = [_x, _this, _originalResult] call FUNC(getRebroStationSignal);
        _result params ["_px", "_signal"];

        if (_px > _bestPx || _signal > _bestSignal) then {
            _bestResult = _result;
            _bestRebroStation = _x;
        };

    } forEach GVAR(rebroStations);
};

if (GVAR(debugReportingEnabled)) then {
    _bestResult params ["_bestPower", "_bestDbm"];

    private _radioClass = [_receiverId] call acre_sys_radio_fnc_getRadioBaseClassname;
    private _squelch = [_radioClass, {configFile >> "CfgAcreComponents" >> _radioClass >> "sensitivityMin"}, -118] call EFUNC(common,readCacheValues);
    private _extendedThreshold = _squelch * 1.1;

    if (_bestDbm >= _extendedThreshold) then {
        private _displayPower = if (_bestDbm >= _squelch) then {_bestPower} else {-1};

        private _transmitterOwner = [_transmitterId] call acre_sys_radio_fnc_getRadioObject;
        if (!isNull _transmitterOwner && {isPlayer _transmitterOwner}) then {
            if (isNull _bestRebroStation) then {
                GVAR(debugConnectionData) set [getPlayerUID _transmitterOwner, [_displayPower, ""]];
            } else {
                _bestResult params ["", "", "_rebroReceivePower", "_rebroTransmitPower"];
                GVAR(debugConnectionData) set [getPlayerUID _transmitterOwner, [
                    _displayPower,
                    netId _bestRebroStation,
                    _rebroReceivePower,
                    _rebroTransmitPower
                ]];
            };
        };
    };
};

REBRO_TRACE_2("",_originalResult,_bestResult);
_bestResult
