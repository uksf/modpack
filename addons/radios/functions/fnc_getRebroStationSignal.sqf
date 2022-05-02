#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles custom signal calculation for a single rebroadcasting station

    Parameter(s):
        0: Rebro mast <OBJECT>
        1: Signal data <ARRAY>
            0: Radio frequency <SCALAR>
            1: Radio power <SCALAR>
            2: Receiving radio ID <STRING>
            3: Transmitting radio ID <STRING>
        2: Original signal result

    Return Value:
        [Power, dBm]
*/
params ["_mast", "_data", "_originalResult"];
_data params ["_frequency", "_power", "_receiverId", "_transmitterId"];
_originalResult params ["_originalPx", "_originalSignal"];

private _radioId = [_mast] call FUNC(getRebroStationRadio);
if (_radioId == "") exitWith {
    WARNING_1("Failed to initialise rebro station",_this);
    [0, -992]
};

if (_radioId == _receiverId || _radioId == _transmitterId) exitWith {
    // Rebro is the receiver/transmitter, don't recalc signal
    [0, -992]
};

// tx -> rebro, if not better than original, exit
private _receiveResult = [_frequency, REBRO_POWER, _radioId, _transmitterId] call acre_sys_signal_fnc_getSignalCore;
_receiveResult params ["_receivePx", "_receiveSignal"];
if (_receivePx < _originalPx || _receiveSignal < _originalSignal || _receivePx == 0 || _receivePx < -125) exitWith {
    TRACE_1("Signal is not better than original",_receiveResult);
    [0, -992]
};

// tx -> rebro, needs to be detectable by rebro
private _rebroClass = [_radioId] call EFUNC(sys_radio,getRadioBaseClassname);
private _min = [_rebroClass, {configFile >> "CfgAcreComponents" >> _rebroClass >> "sensitivityMin"}, -118] call EFUNC(common,readCacheValues);
TRACE_1("",_min);
if (_receiveSignal < _min) exitWith {
    TRACE_1("Signal is not detectable by rebro",_receiveResult);
    [0, -992]
};


// rebro -> rx, return transmitted result with degredation
private _transmitResult = [_frequency, REBRO_POWER, _receiverId, _radioId] call acre_sys_signal_fnc_getSignalCore;
_transmitResult params ["_transmitPx", "_transmitSignal"];

private _finalResult = [(_transmitPx - ((1 - _receivePx) * 0.1)) max 0, _transmitSignal - (abs _receiveSignal * 0.1)];
TRACE_4("",_originalResult,_receiveResult,_transmitResult,_finalResult);

_finalResult
