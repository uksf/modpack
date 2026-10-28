#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles a cTab mode change raised by the patched cTab_fnc_updateInterface.
        Shows the launcher or an app on the Android dialog, and hides the UKSF content in cTab's own modes.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: cTab display name <STRING>
        2: New mode <STRING>

    Return Value:
        Nothing

    Example:
        [_display, "cTab_Android_dlg", "UKSF_APPS"] call uksf_ctab_fnc_onModeChanged
*/
params ["_display", "_displayName", "_mode"];

if (_displayName != ANDROID_DIALOG) exitWith {};

private _container = _display displayCtrl IDC_APPS_GROUP;
if (isNull _container) exitWith {};

if (isNil {_display getVariable QGVAR(unloadHandler)}) then {
    _display setVariable [QGVAR(unloadHandler), _display displayAddEventHandler ["Unload", {call FUNC(onDialogUnload)}]];
};

[_display] call FUNC(closeContent);

if (_mode == MODE_LAUNCHER) then {
    [_display, _container] call FUNC(showLauncher);
};

if (_mode find MODE_APP_PREFIX == 0) then {
    [_display, _container, _mode select [count MODE_APP_PREFIX]] call FUNC(openApp);
};

_container ctrlShow (_mode find MODE_PREFIX == 0);
