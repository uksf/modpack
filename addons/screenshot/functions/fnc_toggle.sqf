#include "script_component.hpp"
/*
    Author:
        Tim Beswick, adapted from Gruppe Adler Mod https://github.com/gruppe-adler/gruppe_adler_mod/tree/master/addons/screenshotMode

    Description:
        Toggles screenshot mode

    Parameter(s):
        0: New state <BOOLEAN>

    Return Value:
        Nothing
*/
params [["_state", false]];

private _staminaBar = uiNamespace getVariable ["ace_advanced_fatigue_staminaBarContainer", controlNull];
private _aceEnabled = !(isNull _staminaBar);

if (_state) then {
    showHUD GVAR(vanillaHUD);

    if (_aceEnabled) then {
        _staminaBar ctrlShow GVAR(staminaBarContainer);
        ace_nametags_showplayernames = GVAR(playerNames);
    };

    if (GVAR(diwakoUiOn)) then {
        diwako_dui_main_toggled_off = false;
        ["diwako_dui_main_hudToggled", [diwako_dui_main_toggled_off]] call CBA_fnc_localEvent;
    };
} else {
    GVAR(vanillaHUD) = shownHUD;
    showHUD [false,false,false,false,false,false,false,false];

    if (_aceEnabled) then {
        GVAR(staminaBarContainer) = ctrlShown _staminaBar;
        GVAR(playerNames) = ace_nametags_showplayernames;

        _staminaBar ctrlShow false;
        ace_nametags_showplayernames = 0;
    };

    if !(diwako_dui_main_toggled_off) then { // ui on
        GVAR(diwakoUiOn) = true;
        diwako_dui_main_toggled_off = true;
        ["diwako_dui_main_hudToggled", [diwako_dui_main_toggled_off]] call CBA_fnc_localEvent;
    };
};
