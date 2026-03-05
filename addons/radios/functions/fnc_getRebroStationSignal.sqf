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
        [Power, dBm, rebroReceivePower, rebroTransmitPower]
*/
params ["_vehicle", "_data", "_originalResult"];
_data params ["_frequency", "_power", "_receiverId", "_transmitterId"];
_originalResult params ["_originalPx", "_originalSignal"];

if (!alive _vehicle) exitWith {[0, -992]};

private _rebroData = [_vehicle] call FUNC(getRebroStationRadio);
_rebroData params ["", "_rebroId"];

if (_rebroId == "") exitWith {
    REBRO_TRACE_1("Rebro station has no radio",_vehicle);
    [0, -992]
};

if (_rebroId == _receiverId || _rebroId == _transmitterId) exitWith {
    // Rebro is the receiver/transmitter, don't recalc signal
    [0, -992]
};

private _rebroPower = [REBRO_RACK_POWER, REBRO_MAST_POWER] select (_vehicle isKindOf QGVAR(rebroStationMast));

// Rebro receives from transmitter — if not better than original, exit
private _rebroReceiveResult = [_frequency, _power, _rebroId, _transmitterId] call acre_sys_signal_fnc_getSignalCore;
_rebroReceiveResult params ["_rebroReceivePower", "_rebroReceiveSignal"];
if (_rebroReceivePower < _originalPx || _rebroReceiveSignal < _originalSignal || _rebroReceivePower == 0 || _rebroReceivePower < -125) exitWith {
    REBRO_TRACE_2("Signal is not better than original",_originalSignal,_rebroReceiveResult);
    [0, -992]
};

// Rebro receives from transmitter — needs to be detectable by rebro
private _rebroClass = [_rebroId] call acre_sys_radio_fnc_getRadioBaseClassname;
private _min = [_rebroClass, {configFile >> "CfgAcreComponents" >> _rebroClass >> "sensitivityMin"}, -118] call EFUNC(common,readCacheValues);
if (_rebroReceiveSignal < _min) exitWith {
    REBRO_TRACE_2("Signal is not detectable by rebro",_rebroReceiveResult,_min);
    [0, -992]
};

// Rebro transmits to receiver — return with degradation from receive leg
private _rebroTransmitResult = [_frequency, _rebroPower, _receiverId, _rebroId] call acre_sys_signal_fnc_getSignalCore;
_rebroTransmitResult params ["_rebroTransmitPower", "_rebroTransmitSignal"];

private _finalResult = [
    (_rebroTransmitPower - ((1 - _rebroReceivePower) * 0.1)) max 0,
    _rebroTransmitSignal - (abs _rebroReceiveSignal * 0.1),
    _rebroReceivePower,
    _rebroTransmitPower
];
REBRO_TRACE_4("",_originalResult,_rebroReceiveResult,_rebroTransmitResult,_finalResult);

_finalResult
