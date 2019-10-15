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
private _stHudEnabled = !(isNil "STHud_UIMode");

if (_state) then {
    showHUD GVAR(vanillaHUD);
    if (_aceEnabled) then {
        _staminaBar ctrlShow GVAR(staminaBarContainer);
        ace_nametags_showplayernames = GVAR(playerNames);
    };
    if (_stHudEnabled) then {
        STHud_UIMode = GVAR(stUIMode);
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
    if (_stHudEnabled) then {
        GVAR(stUIMode) = STHud_UIMode;
        STHud_UIMode = 0;
    };
};
