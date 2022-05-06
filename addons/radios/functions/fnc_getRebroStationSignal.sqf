#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles custom signal calculation for a 1-step re-broadcasting radio

    Parameter(s):
        0: Rebro vehicle <OBJECT>
        1: Signal data <ARRAY>
            0: Radio frequency <SCALAR>
            1: Radio power <SCALAR>
            2: Receiving radio ID <STRING>
            3: Transmitting radio ID <STRING>
        2: Original signal result

    Return Value:
        [Power, dBm]
*/
params ["_vehicle", "_data", "_originalResult"];
_data params ["_frequency", "_power", "_receiverId", "_transmitterId"];
_originalResult params ["_originalPx", "_originalSignal"];

private _rebroData = [_vehicle] call FUNC(getRebroStationRadio);
_rebroData params ["", "_rebroId"];

if (_rebroId == "") exitWith {
    WARNING_1("Failed to initialise rebro station %1",_this);
    [0, -992]
};

if (_rebroId == _receiverId || _rebroId == _transmitterId) exitWith {
    // Rebro is the receiver/transmitter, don't recalc signal
    [0, -992]
};

private _rebroPower = [REBRO_RACK_POWER, REBRO_MAST_POWER] select (_vehicle isKindOf QGVAR(rebroStationMast));

// tx -> rebro, if not better than original, exit
private _receiveResult = [_frequency, _power, _rebroId, _transmitterId] call acre_sys_signal_fnc_getSignalCore;
_receiveResult params ["_receivePx", "_receiveSignal"];
if (_receivePx < _originalPx || _receiveSignal < _originalSignal || _receivePx == 0 || _receivePx < -125) exitWith {
    REBRO_TRACE_2("Signal is not better than original",_originalSignal,_receiveResult);
    [0, -992]
};

// tx -> rebro, needs to be detectable by rebro
private _rebroClass = [_rebroId] call EFUNC(sys_radio,getRadioBaseClassname);
private _min = [_rebroClass, {configFile >> "CfgAcreComponents" >> _rebroClass >> "sensitivityMin"}, -118] call EFUNC(common,readCacheValues);
if (_receiveSignal < _min) exitWith {
    REBRO_TRACE_2("Signal is not detectable by rebro",_receiveResult,_min);
    [0, -992]
};


// rebro -> rx, return transmitted result with degredation
private _transmitResult = [_frequency, _rebroPower, _receiverId, _rebroId] call acre_sys_signal_fnc_getSignalCore;
_transmitResult params ["_transmitPx", "_transmitSignal"];

private _finalResult = [(_transmitPx - ((1 - _receivePx) * 0.1)) max 0, _transmitSignal - (abs _receiveSignal * 0.1)];
REBRO_TRACE_4("",_originalResult,_receiveResult,_transmitResult,_finalResult);

_finalResult
