#include "..\script_component.hpp"
#include "..\defines.hpp"
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
ace_arsenal_center setVariable ["ace_arsenal_virtualItems", nil];

GVAR(useMainOpGear) = !GVAR(useMainOpGear);
if (GVAR(useMainOpGear)) then {
    if ((count GVAR(cachedMainOpGear)) == 0) then {
        [ace_arsenal_center, call FUNC(getMainOpGear), false] call ace_arsenal_fnc_addVirtualItems;
        GVAR(cachedMainOpGear) = ace_arsenal_center getVariable "ace_arsenal_virtualItems";
    };
    ace_arsenal_virtualItems = GVAR(cachedMainOpGear);

    private _filteredLoadout = [[ace_arsenal_center] call CBA_fnc_getLoadout] call ace_arsenal_fnc_verifyLoadout;
    [ace_arsenal_center, _filteredLoadout#0] call CBA_fnc_setLoadout;
} else {
    if ((count GVAR(cachedFullGear)) == 0) then {
        [ace_arsenal_center, true, false] call ace_arsenal_fnc_addVirtualItems;
        GVAR(cachedFullGear) = ace_arsenal_center getVariable "ace_arsenal_virtualItems";
    };
    ace_arsenal_virtualItems = GVAR(cachedFullGear);
};

_buttonMainOpGear ctrlSetText (["Turn On Main Op Gear", "Turn Off Main Op Gear"] select GVAR(useMainOpGear));
call ace_arsenal_fnc_updateUniqueItemsList;
[_display, _display displayCtrl ace_arsenal_currentLeftPanel] call ace_arsenal_fnc_fillLeftPanel;
[_display, _display displayCtrl ace_arsenal_currentRightPanel] call ace_arsenal_fnc_fillRightPanel;
