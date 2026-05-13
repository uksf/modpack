#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Vitals PFH body. Reads ACE + KAT medical vars and updates health-tab ctrls. State timer
        line shows "CARDIAC ARREST: Xs" (red) or "Coma: Xs" (amber) using endpoint vars.

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

(_display displayCtrl IDC_HEALTH_HR) ctrlSetText format ["HR:      %1      bpm", _hr];
(_display displayCtrl IDC_HEALTH_BP) ctrlSetText format ["BP:      %1/%2      mmHg", round (_bp # 0), round (_bp # 1)];

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

(_display displayCtrl IDC_HEALTH_RESP) ctrlSetText format ["Resp:      %1      /min", _respValue];
(_display displayCtrl IDC_HEALTH_SPO2) ctrlSetText format ["SpO2:      %1      %2", _spo2Value, "%"];

private _stateCtrl = _display displayCtrl IDC_HEALTH_STATE_TIMER;
private _healthTabOpen = ctrlEnabled (_display displayCtrl IDC_HEALTH_TABFOCUS);

private _cardiacEnd = ACE_player getVariable ["ace_medical_statemachine_cardiacArrestEndTime", -1];
private _comaEnd = ACE_player getVariable ["ace_medical_statemachine_comaEndTime", -1];

if (_cardiacEnd > -1) exitWith {
    private _remaining = round ((_cardiacEnd - CBA_missionTime) max 0);
    _stateCtrl ctrlSetText format ["CARDIAC ARREST! Time remaining until death: %1", _remaining];
    _stateCtrl ctrlSetTextColor [0.6, 0, 0, 1];
    if (GVAR(showStateTimer) && _healthTabOpen) then {
        _stateCtrl ctrlEnable true;
        _stateCtrl ctrlShow true;
    };
};

if (_comaEnd > -1) exitWith {
    private _remaining = round ((_comaEnd - CBA_missionTime) max 0);
    _stateCtrl ctrlSetText format ["Coma: %1s", _remaining];
    _stateCtrl ctrlSetTextColor [0.95, 0.6, 0.1, 1];
    if (GVAR(showStateTimer) && _healthTabOpen) then {
        _stateCtrl ctrlEnable true;
        _stateCtrl ctrlShow true;
    };
};

_stateCtrl ctrlEnable false;
_stateCtrl ctrlShow false;
