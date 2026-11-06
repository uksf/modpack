#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Describes the MPU-5 settings of one radio in a preset, for the presets manager

    Parameter(s):
        0: MPU-5 preset data, [monitors, monitorAudio, txSlots] <ARRAY>

    Return Value:
        Structured text lines that start with a line break <STRING>

    Example:
        [[[3, 5], [[3, 0.5, -1]], [2, 0, 0, 0]]] call uksf_radios_fnc_presetMpu5Details
*/
params ["_mpu5"];
_mpu5 params [["_monitors", []], ["_monitorAudio", []], ["_txSlots", []]];

private _earNames = createHashMapFromArray [[-2, "radio ear"], [-1, "left ear"], [0, "both ears"], [1, "right ear"]];
private _text = format ["<br/>Monitoring: %1", ["none", (_monitors apply {format ["TG %1", _x]}) joinString ", "] select (_monitors isNotEqualTo [])];

private _slots = [];
{
    if (_x > 0) then {_slots pushBack format ["slot %1 TG %2", _forEachIndex + 1, _x]};
} forEach _txSlots;
_text = _text + format ["<br/>TX slots: %1", ["none", _slots joinString ", "] select (_slots isNotEqualTo [])];

private _audio = _monitorAudio apply {
    _x params ["_talkgroup", "_volume", "_ear"];
    format ["TG %1 %2%% %3", _talkgroup, round (_volume * 100), _earNames getOrDefault [_ear, "radio ear"]]
};
if (_audio isNotEqualTo []) then {
    _text = _text + format ["<br/>Monitor audio: %1", _audio joinString ", "];
};

_text
