#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Switches to the Health tab. Shows vital rows, hides spectator controls,
        tears down the spectator PFH + camera so they aren't running behind the health view.
        Triggers an immediate vitalsUpdate so the state timer (if active) appears without delay.

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

if (GVAR(activeSpectatorPFH) != -1) then {
    [GVAR(activeSpectatorPFH)] call CBA_fnc_removePerFrameHandler;
    GVAR(activeSpectatorPFH) = -1;
};
call FUNC(spectatorCleanup);

GVAR(currentTab) = "health";

{
    (_display displayCtrl _x) ctrlEnable true;
    (_display displayCtrl _x) ctrlShow true;
} forEach [IDC_HEALTH_HR, IDC_HEALTH_BP, IDC_HEALTH_RESP, IDC_HEALTH_SPO2, IDC_HEALTH_TABFOCUS];

[[], -1] call FUNC(vitalsUpdate);
