/*
    Author:
        Kex, edited by Tim Beswick

    Description:
        Called when display curator is loaded

    Parameter(s):
        0: Curator display <DISPLAY>

    Return Value:
        Boolean
*/
#include "script_component.hpp"

["onLoad", _this ,"RscDisplayCurator", "CuratorDisplays"] call (uinamespace getvariable "BIS_fnc_initDisplay");

disableSerialization;
private _displayReload = false;
if (isNil "Achilles_curator_init_done") then {
    private _mainDisplay = findDisplay 46;
    _mainDisplay displayAddEventHandler ["KeyDown", { _this call Achilles_fnc_HandleRemoteKeyPressed; }];
    Ares_Ctrl_Key_Pressed = false;
    Ares_Shift_Key_Pressed = false;
    (getAssignedCuratorLogic player) addCuratorAddons (EGVAR(common,addons) - (curatorAddons (getAssignedCuratorLogic player)));
    if (!(missionnamespace getvariable ["bis_fnc_drawMinefields_active", false])) then {
        missionnamespace setvariable ["bis_fnc_drawMinefields_active", true, true];
    };
    Achilles_var_reloadDisplay = nil; 
    Achilles_var_reloadVisionModes = nil;
    Achilles_curator_init_done = true;
};

private _display = (_this select 0);
_display displayAddEventHandler ["KeyDown", { _this call Achilles_fnc_HandleCuratorKeyPressed; }];
_display displayAddEventHandler ["KeyUp", { _this call Achilles_fnc_HandleCuratorKeyReleased; }];
[] spawn {
    waitUntil { !(isNull (findDisplay 312)) };
    [] call Achilles_fnc_OnModuleTreeLoad;
};
