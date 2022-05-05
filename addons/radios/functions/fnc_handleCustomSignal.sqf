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

if (GVAR(useRebros)) then {
    GVAR(rebroStations) = GVAR(rebroStations) select {alive _x};

    {
        private _result = [_x, _this, _originalResult] call FUNC(getRebroStationSignal);
        _result params ["_px", "_signal"];

        if (_px > _bestPx || _signal > _bestSignal) then {
            _bestResult = _result;
        };

    } forEach GVAR(rebroStations);
};

REBRO_TRACE_2("",_originalResult,_bestResult);
_bestResult
