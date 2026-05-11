#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Vitals PFH body. Reads ACE + KAT medical vars and updates health-tab ctrls.

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

private _hr = round (ACE_player getVariable ["ace_medical_heartRate", 0]);
private _bp = ACE_player getVariable ["ace_medical_bloodPressure", [0, 0]];
private _pain = ACE_player getVariable ["ace_medical_pain", 0];

private _hrSeverity = switch (true) do {
    case (_hr == 0): { "critical" };
    case (_hr < 40 || _hr > 120): { "warn" };
    default { "normal" };
};
private _bpSystolic = _bp # 1;
private _bpSeverity = if (_bpSystolic < 90) then { "warn" } else { "normal" };
private _painSeverity = switch (true) do {
    case (_pain > 0.75): { "critical" };
    case (_pain > 0.4): { "warn" };
    default { "normal" };
};

private _hrCtrl = _display displayCtrl IDC_HEALTH_HR;
_hrCtrl ctrlSetStructuredText parseText (["HR", str _hr, "bpm", _hrSeverity] call FUNC(formatVital));
_hrCtrl ctrlShow GVAR(showHR);

private _bpCtrl = _display displayCtrl IDC_HEALTH_BP;
_bpCtrl ctrlSetStructuredText parseText (["BP", format ["%1/%2", round (_bp # 0), round _bpSystolic], "mmHg", _bpSeverity] call FUNC(formatVital));
_bpCtrl ctrlShow ((GVAR(viewMode) == "full") && GVAR(showBP));

private _painCtrl = _display displayCtrl IDC_HEALTH_PAIN;
_painCtrl ctrlSetStructuredText parseText (["Pain", str (round (_pain * 100)), "%", _painSeverity] call FUNC(formatVital));

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

private _respSeverity = switch (true) do {
    case (_respValue == 0): { "critical" };
    case (_respValue < 8 || _respValue > 25): { "warn" };
    default { "normal" };
};
private _spo2Severity = switch (true) do {
    case (_spo2Value < 70): { "critical" };
    case (_spo2Value < 90): { "warn" };
    default { "normal" };
};

private _respCtrl = _display displayCtrl IDC_HEALTH_RESP;
_respCtrl ctrlSetStructuredText parseText (["Resp", str _respValue, "/min", _respSeverity] call FUNC(formatVital));
_respCtrl ctrlShow ((GVAR(viewMode) == "full") && GVAR(showResp));

private _spo2Ctrl = _display displayCtrl IDC_HEALTH_SPO2;
_spo2Ctrl ctrlSetStructuredText parseText (["SpO2", str _spo2Value, "%", _spo2Severity] call FUNC(formatVital));
_spo2Ctrl ctrlShow ((GVAR(viewMode) == "full") && GVAR(showSpO2));

private _cardiacEnd = ACE_player getVariable ["ace_medical_statemachine_cardiacArrestEndTime", -1];
private _comaEnd = ACE_player getVariable ["ace_medical_statemachine_comaEndTime", -1];

private _stateCtrl = _display displayCtrl IDC_HEALTH_STATE_TIMER;

if (_cardiacEnd > -1) exitWith {
    private _remaining = round ((_cardiacEnd - CBA_missionTime) max 0);
    _stateCtrl ctrlSetStructuredText parseText format [
        "<t align='center' color='#ff3333' size='1.4'>CARDIAC ARREST: %1s</t>", _remaining
    ];
    _stateCtrl ctrlShow GVAR(showStateTimer);

    if (GVAR(soundOnStateChange) && {!GVAR(prevCardiacState)}) then {
        ["cardiac"] call FUNC(playStateSound);
    };
    GVAR(prevCardiacState) = true;
};

GVAR(prevCardiacState) = false;

if (_comaEnd > -1) exitWith {
    private _remaining = round ((_comaEnd - CBA_missionTime) max 0);
    _stateCtrl ctrlSetStructuredText parseText format [
        "<t align='center' color='#ff9900' size='1.4'>Coma: %1s</t>", _remaining
    ];
    _stateCtrl ctrlShow GVAR(showStateTimer);

    if (GVAR(soundOnStateChange) && {!GVAR(prevComaState)}) then {
        ["coma"] call FUNC(playStateSound);
    };
    GVAR(prevComaState) = true;
};

GVAR(prevComaState) = false;

_stateCtrl ctrlShow false;
