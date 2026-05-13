#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Vitals PFH body. Reads ACE + KAT medical vars and updates health-tab ctrls. State timer
        line shows "Cardiac Arrest — M:SS" (red) or "Coma — M:SS" (amber) using endpoint vars.

    Parameter(s):
        Standard PFH args: [_args, _idPFH]

    Return Value:
        None

    Example:
        Registered via openDialogOnLoad
*/
params ["_args", "_idPFH"];

private _display = findDisplay IDD_UNCON;
if (isNull _display) exitWith {
    [_idPFH] call CBA_fnc_removePerFrameHandler;
    GVAR(activeVitalsPFH) = -1;
};

if (GVAR(interfaceHidden)) exitWith {};

#define COLOUR_LABEL  "#9a9a9a"
#define COLOUR_VALUE  "#e6e6e6"
#define COLOUR_WARN   "#ffb366"
#define COLOUR_CRIT   "#ff6666"

private _hr = round (ACE_player getVariable ["ace_medical_heartRate", 0]);
private _bp = ACE_player getVariable ["ace_medical_bloodPressure", [0, 0]];

private _hrColour = switch (true) do {
    case (_hr == 0): { COLOUR_CRIT };
    case (_hr < 40 || _hr > 120): { COLOUR_WARN };
    default { COLOUR_VALUE };
};
private _bpSystolic = round (_bp # 1);
private _bpDiastolic = round (_bp # 0);
private _bpColour = if (_bpSystolic < 90) then { COLOUR_WARN } else { COLOUR_VALUE };

(_display displayCtrl IDC_HEALTH_HR) ctrlSetStructuredText parseText format [
    "<t color='%1'>Heart Rate</t><t align='right' color='%2'>%3 bpm</t>",
    COLOUR_LABEL, _hrColour, _hr
];
(_display displayCtrl IDC_HEALTH_BP) ctrlSetStructuredText parseText format [
    "<t color='%1'>Blood Pressure</t><t align='right' color='%2'>%3 / %4 mmHg</t>",
    COLOUR_LABEL, _bpColour, _bpDiastolic, _bpSystolic
];

private _respValue = 0;
private _spo2Value = 0;

if (GVAR(katLoaded)) then {
    _respValue = round (ACE_player getVariable ["kat_breathing_breathrate", 0]);
    _spo2Value = ((ACE_player getVariable ["kat_circulation_bloodgas", [0, 90]]) # 1) + 5;
} else {
    if (_hr > 0) then {
        _respValue = round (_hr * 0.127);
    };
    _spo2Value = round (ACE_player getVariable ["ace_medical_spo2", 100]);
};

private _respColour = switch (true) do {
    case (_respValue == 0): { COLOUR_CRIT };
    case (_respValue < 8 || _respValue > 25): { COLOUR_WARN };
    default { COLOUR_VALUE };
};
private _spo2Colour = switch (true) do {
    case (_spo2Value < 70): { COLOUR_CRIT };
    case (_spo2Value < 90): { COLOUR_WARN };
    default { COLOUR_VALUE };
};

(_display displayCtrl IDC_HEALTH_RESP) ctrlSetStructuredText parseText format [
    "<t color='%1'>Respiration</t><t align='right' color='%2'>%3 /min</t>",
    COLOUR_LABEL, _respColour, _respValue
];
(_display displayCtrl IDC_HEALTH_SPO2) ctrlSetStructuredText parseText format [
    "<t color='%1'>SpO2</t><t align='right' color='%2'>%3%4</t>",
    COLOUR_LABEL, _spo2Colour, _spo2Value, "%"
];

private _stateCtrl = _display displayCtrl IDC_HEALTH_STATE_TIMER;
private _healthTabOpen = ctrlEnabled (_display displayCtrl IDC_HEALTH_TABFOCUS);

private _cardiacEnd = ACE_player getVariable ["ace_medical_statemachine_cardiacArrestEndTime", -1];
private _comaEnd = ACE_player getVariable ["ace_medical_statemachine_comaEndTime", -1];

private _fnc_formatTime = {
    params ["_seconds"];
    private _mins = floor (_seconds / 60);
    private _secs = _seconds - (_mins * 60);
    private _secsStr = if (_secs < 10) then { "0" + str _secs } else { str _secs };
    format ["%1:%2", _mins, _secsStr]
};

if (_cardiacEnd > -1) exitWith {
    private _remaining = round ((_cardiacEnd - CBA_missionTime) max 0);
    private _timeStr = [_remaining] call _fnc_formatTime;
    _stateCtrl ctrlSetStructuredText parseText format [
        "<t align='center' color='#ff5555'>Cardiac Arrest  </t><t align='center' color='#ffffff'>%1</t>",
        _timeStr
    ];
    if (GVAR(showStateTimer) && _healthTabOpen) then {
        _stateCtrl ctrlEnable true;
        _stateCtrl ctrlShow true;
    };
};

if (_comaEnd > -1) exitWith {
    private _remaining = round ((_comaEnd - CBA_missionTime) max 0);
    private _timeStr = [_remaining] call _fnc_formatTime;
    _stateCtrl ctrlSetStructuredText parseText format [
        "<t align='center' color='#ffb366'>Coma  </t><t align='center' color='#ffffff'>%1</t>",
        _timeStr
    ];
    if (GVAR(showStateTimer) && _healthTabOpen) then {
        _stateCtrl ctrlEnable true;
        _stateCtrl ctrlShow true;
    };
};

_stateCtrl ctrlEnable false;
_stateCtrl ctrlShow false;
