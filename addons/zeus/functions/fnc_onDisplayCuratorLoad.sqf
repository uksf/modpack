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
#include "\A3\ui_f_curator\ui\defineResinclDesign.inc"

["onLoad", _this ,"RscDisplayCurator", "CuratorDisplays"] call (uinamespace getvariable "BIS_fnc_initDisplay");

disableSerialization;
private _displayReload = false;
if (isNil "Achilles_curator_init_done") then {
    private _mainDisplay = findDisplay 46;
    _mainDisplay displayAddEventHandler ["KeyDown", { _this call Achilles_fnc_HandleRemoteKeyPressed; }];
    Ares_Ctrl_Key_Pressed = false;
    Ares_Shift_Key_Pressed = false;
    _displayReload = [] call Achilles_fnc_onCuratorStart;
    Achilles_curator_init_done = true;
};
if (_displayReload) exitWith {};    
private _display = (_this select 0);
_display displayAddEventHandler ["KeyDown", {_this call Achilles_fnc_HandleCuratorKeyPressed;}];
_display displayAddEventHandler ["KeyUp", {_this call Achilles_fnc_HandleCuratorKeyReleased;}];
[] spawn {
    waitUntil {!(isNull (findDisplay 312))};
    [] call Achilles_fnc_OnModuleTreeLoad;
};
