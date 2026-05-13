#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Switches to the Spectator tab. Shows spec info, hides medical controls. NVG buttons shown based on setting.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_medical_fnc_openSpectatorTab
*/

private _display = findDisplay IDD_UNCON;
if (isNull _display) exitWith {};

call FUNC(hidePreviousTabs);

GVAR(currentTab) = "spectator";

// PiPZone and tab buttons are always visible (declared in dialog with no show toggle here).
// Spectator info text controls toggled by spectatorUpdate based on state (too-far / no-signal / signal).

private _nvgMode = GVAR(spectatorNVGMode);

if (_nvgMode == 2) then {
    (_display displayCtrl IDC_SPEC_NVG_0) ctrlEnable true;
    (_display displayCtrl IDC_SPEC_NVG_0) ctrlShow true;
    (_display displayCtrl IDC_SPEC_NVG_1) ctrlEnable true;
    (_display displayCtrl IDC_SPEC_NVG_1) ctrlShow true;
};

if (_nvgMode == 3) then {
    (_display displayCtrl IDC_SPEC_NVG_0) ctrlEnable true;
    (_display displayCtrl IDC_SPEC_NVG_0) ctrlShow true;
    (_display displayCtrl IDC_SPEC_NVG_1) ctrlShow true;
};

if (_nvgMode == 4) then {
    (_display displayCtrl IDC_SPEC_NVG_0) ctrlEnable true;
    (_display displayCtrl IDC_SPEC_NVG_0) ctrlShow true;
    (_display displayCtrl IDC_SPEC_NVG_1) ctrlEnable true;
    (_display displayCtrl IDC_SPEC_NVG_1) ctrlShow true;
    (_display displayCtrl IDC_SPEC_NVG_2) ctrlEnable true;
    (_display displayCtrl IDC_SPEC_NVG_2) ctrlShow true;
};
