#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Switches to the Health tab. Shows enabled vital rows, hides spectator controls.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_medical_fnc_openHealthTab
*/

private _display = findDisplay IDD_UNCON;
if (isNull _display) exitWith {};

call FUNC(hidePreviousTabs);

GVAR(currentTab) = "health";

private _showExtras = GVAR(viewMode) == "full";

if (GVAR(showHR)) then {
    (_display displayCtrl IDC_HEALTH_HR) ctrlEnable true;
    (_display displayCtrl IDC_HEALTH_HR) ctrlShow true;
};
if (GVAR(showBP) && _showExtras) then {
    (_display displayCtrl IDC_HEALTH_BP) ctrlEnable true;
    (_display displayCtrl IDC_HEALTH_BP) ctrlShow true;
};
if (GVAR(showResp) && _showExtras) then {
    (_display displayCtrl IDC_HEALTH_RESP) ctrlEnable true;
    (_display displayCtrl IDC_HEALTH_RESP) ctrlShow true;
};
if (GVAR(showSpO2) && _showExtras) then {
    (_display displayCtrl IDC_HEALTH_SPO2) ctrlEnable true;
    (_display displayCtrl IDC_HEALTH_SPO2) ctrlShow true;
};

// Invisible focus marker — tells vitalsUpdate the health tab is open (controls state-timer visibility)
(_display displayCtrl IDC_HEALTH_TABFOCUS) ctrlEnable true;
(_display displayCtrl IDC_HEALTH_TABFOCUS) ctrlShow true;
