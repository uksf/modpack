#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Hides all dialog controls (spectator + medical). Called before switching tabs to ensure clean state.

    Parameter(s):
        None

    Return Value:
        None

    Example:
        call uksf_medical_fnc_hidePreviousTabs
*/

private _display = findDisplay IDD_UNCON;
if (isNull _display) exitWith {};

private _ids = [
    IDC_SPEC_TOO_FAR, IDC_SPEC_INFO, IDC_SPEC_PIP, IDC_SPEC_NO_SIGNAL,
    IDC_SPEC_NVG_0, IDC_SPEC_NVG_1, IDC_SPEC_NVG_2,
    IDC_HEALTH_HR, IDC_HEALTH_BP, IDC_HEALTH_RESP, IDC_HEALTH_SPO2,
    IDC_HEALTH_STATE_TIMER, IDC_HEALTH_TABFOCUS
];

{
    private _ctrl = _display displayCtrl _x;
    _ctrl ctrlEnable false;
    _ctrl ctrlShow false;
} forEach _ids;
