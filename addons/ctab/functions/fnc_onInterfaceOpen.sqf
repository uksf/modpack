#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles cTab's interface open event.
        On the Android dialog, adds the app overlays to both cTab maps and returns to the app that was open when the dialog last closed.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: cTab display name <STRING>

    Return Value:
        Nothing

    Example:
        [_display, "cTab_Android_dlg"] call uksf_ctab_fnc_onInterfaceOpen
*/
params ["_display", "_displayName"];

if (_displayName != ANDROID_DIALOG) exitWith {};

{
    (_display displayCtrl _x) ctrlAddEventHandler ["Draw", {call FUNC(drawOverlays)}];
} forEach [IDC_MAP_SCREEN, IDC_MAP_TOPO];

if (GVAR(lastMode) != "") then {
    [FUNC(setMode), [GVAR(lastMode)]] call CBA_fnc_execNextFrame;
};
