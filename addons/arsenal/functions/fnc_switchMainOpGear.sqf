#include "script_component.hpp"
#include "\u\uksf\addons\arsenal\script_mainOpGear.hpp"
#include "\z\ace\addons\arsenal\defines.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets the gear of the crate to either main op gear, or all gear.

    Parameter(s):
        0: Display <DISPLAY>

    Return Value:
        None
*/
params ["_display"];

ace_arsenal_center call cba_optics_fnc_changePIPOpticClass;
ace_arsenal_center call cba_optics_fnc_changeCarryHandleOpticClass;

private _buttonMainOpGear = _display displayCtrl IDC_buttonMainOpGear;
ace_arsenal_center setVariable ["ace_arsenal_virtualItems", [[[],[],[]],[[],[],[],[]],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[]]];

GVAR(useMainOpGear) = !GVAR(useMainOpGear);
if (GVAR(useMainOpGear)) then {
    if (GVAR(cachedMainOpGear) isEqualTo []) then {
        [ace_arsenal_center, uiNamespace getVariable [QGVAR(mainOpGear), MAIN_OP_GEAR], false] call ace_arsenal_fnc_addVirtualItems;
        GVAR(cachedMainOpGear) = ace_arsenal_center getVariable "ace_arsenal_virtualItems";
    };
    ace_arsenal_virtualItems = GVAR(cachedMainOpGear);

    private _filteredLoadout = [getUnitLoadout ace_arsenal_center] call ace_arsenal_fnc_verifyLoadout;
    ace_arsenal_center setUnitLoadout (_filteredLoadout#0);
} else {
    if (GVAR(cachedFullGear) isEqualTo []) then {
        [ace_arsenal_center, true, false] call ace_arsenal_fnc_addVirtualItems;
        GVAR(cachedFullGear) = ace_arsenal_center getVariable "ace_arsenal_virtualItems";
    };
    ace_arsenal_virtualItems = GVAR(cachedFullGear);
};

_buttonMainOpGear ctrlSetText (["Turn On Main Op Gear", "Turn Off Main Op Gear"] select GVAR(useMainOpGear));
call ace_arsenal_fnc_updateUniqueItemsList;
[_display, _display displayCtrl ace_arsenal_currentLeftPanel] call ace_arsenal_fnc_fillLeftPanel;
[_display, _display displayCtrl ace_arsenal_currentRightPanel] call ace_arsenal_fnc_fillRightPanel;
