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

GVAR(rebroStations) = GVAR(rebroStations) select {alive _x};
INFO_2("Transmission: %1, Rebro stations: %2",_this,GVAR(rebroStations));

private _bestResult = [0, -992];
private _originalResult = call acre_sys_signal_fnc_getSignalCore;
TRACE_1("",_originalResult);

_bestResult = +_originalResult;
_bestResult params ["_bestPx", "_bestSignal"];

{
    private _result = [_x, _this, _originalResult] call FUNC(getRebroStationSignal);
    _result params ["_px", "_signal"];
    TRACE_1("",_result);

    if (_px > _bestPx || _signal > _bestSignal) then {
        _bestResult = _result;
    };

} forEach GVAR(rebroStations);

TRACE_1("",_bestResult);
_bestResult
