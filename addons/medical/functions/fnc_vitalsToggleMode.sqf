#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Toggles between Full and Minimal health view. Minimal hides BP / Resp / SpO2.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_medical_fnc_vitalsToggleMode
*/

private _display = findDisplay IDD_UNCON;
if (isNull _display) exitWith {};

GVAR(viewMode) = if (GVAR(viewMode) == "full") then { "minimal" } else { "full" };

private _showExtras = GVAR(viewMode) == "full";
private _healthTabOpen = GVAR(currentTab) == "health";

(_display displayCtrl IDC_HEALTH_BP) ctrlShow (_showExtras && GVAR(showBP) && _healthTabOpen);
(_display displayCtrl IDC_HEALTH_RESP) ctrlShow (_showExtras && GVAR(showResp) && _healthTabOpen);
(_display displayCtrl IDC_HEALTH_SPO2) ctrlShow (_showExtras && GVAR(showSpO2) && _healthTabOpen);
