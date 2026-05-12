#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Populates the settings tab listbox with current CBA setting values.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_medical_fnc_settingsTabBuild
*/

private _display = findDisplay IDD_UNCON;
if (isNull _display) exitWith {};

private _list = _display displayCtrl IDC_SETTINGS_LIST;
lnbClear _list;

private _settings = [
    ["Master Enable", QGVAR(modEnabled), GVAR(modEnabled)],
    ["Show Spectator Tab", QGVAR(showSpectator), GVAR(showSpectator)],
    ["Show Health Tab", QGVAR(showHealth), GVAR(showHealth)],
    ["Spectator Distance", QGVAR(spectatorDistance), GVAR(spectatorDistance)],
    ["Spectator NVG Mode", QGVAR(spectatorNVGMode), GVAR(spectatorNVGMode)],
    ["Show HR", QGVAR(showHR), GVAR(showHR)],
    ["Show BP", QGVAR(showBP), GVAR(showBP)],
    ["Show Resp", QGVAR(showResp), GVAR(showResp)],
    ["Show SpO2", QGVAR(showSpO2), GVAR(showSpO2)],
    ["Show State Timer", QGVAR(showStateTimer), GVAR(showStateTimer)],
    ["Sound On State Change", QGVAR(soundOnStateChange), GVAR(soundOnStateChange)],
    ["Default Tab", QGVAR(defaultTab), GVAR(defaultTab)],
    ["Health View Default", QGVAR(viewModeDefault), GVAR(viewModeDefault)]
];

{
    _x params ["_label", "", "_value"];
    _list lnbAddRow [_label, str _value];
} forEach _settings;
