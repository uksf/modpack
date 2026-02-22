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

if (GVAR(visualiseReportingEnabled)) then {
    // Log which rebro station relayed this signal (if any)
    if (!isNull _bestRebroStation) then {
        GVAR(visualiseSignalLog) set [netId _bestRebroStation, [_bestResult#0, _bestResult#1]];
    };

    // Log connection to transmitter for full network graph
    private _transmitterOwner = [_transmitterId] call acre_sys_radio_fnc_getRadioObject;
    if (!isNull _transmitterOwner && {isPlayer _transmitterOwner}) then {
        private _isDirect = isNull _bestRebroStation;
        private _rebroNetId = if (_isDirect) then {""} else {netId _bestRebroStation};
        GVAR(visualiseConnectionLog) set [getPlayerUID _transmitterOwner, [
            _bestResult#0,
            _isDirect,
            _rebroNetId
        ]];
    };
};

REBRO_TRACE_2("",_originalResult,_bestResult);
_bestResult
