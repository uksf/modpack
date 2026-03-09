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

if (GVAR(useRebros) && {_bestPx < 0.95}) then {
    // Filter dead rebro stations periodically rather than every signal calculation.
    // diag_frameNo check ensures we only rebuild the array once per frame regardless
    // of how many TX-RX pairs are being processed.
    if (GVAR(rebroStationsFilterFrame) != diag_frameNo) then {
        GVAR(rebroStations) = GVAR(rebroStations) select {alive _x};
        GVAR(rebroStationsFilterFrame) = diag_frameNo;
    };

    {
        private _result = [_x, _this, _originalResult] call FUNC(getRebroStationSignal);
        _result params ["_px", "_signal"];

        if (_px > _bestPx || _signal > _bestSignal) then {
            _bestResult = _result;
            _bestRebroStation = _x;
        };

    } forEach GVAR(rebroStations);
};

if (GVAR(debugReportingEnabled) && {CBA_missionTime >= GVAR(debugReportingNextUpdate)}) then {
    GVAR(debugReportingNextUpdate) = CBA_missionTime + 1;
    _bestResult params ["_bestPower", "_bestDbm"];

    private _radioClass = [_receiverId] call acre_sys_radio_fnc_getRadioBaseClassname;
    private _squelch = [_radioClass, {configFile >> "CfgAcreComponents" >> _radioClass >> "sensitivityMin"}, -118] call EFUNC(common,readCacheValues);
    private _extendedThreshold = _squelch * 1.1;

    if (_bestDbm >= _extendedThreshold) then {
        private _displayPower = if (_bestDbm >= _squelch) then {_bestPower} else {-1};

        private _transmitterOwner = [_transmitterId] call acre_sys_radio_fnc_getRadioObject;
        if (!isNil "_transmitterOwner" && {!isNull _transmitterOwner} && {isPlayer _transmitterOwner}) then {
            if (isNull _bestRebroStation) then {
                GVAR(debugConnectionData) set [getPlayerUID _transmitterOwner, [_displayPower, ""]];
            } else {
                _bestResult params ["", "", ["_rebroReceivePower", 0], ["_rebroTransmitPower", 0]];
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
