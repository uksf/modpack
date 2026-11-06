#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Switches the open cTab Android dialog to a mode.
        cTab hides its own pages and raises uksf_ctab_modeChanged, which shows the launcher or an app.

    Parameter(s):
        0: cTab mode, "UKSF_APPS" for the launcher or "UKSF_APP_<id>" for an app <STRING>

    Return Value:
        Nothing

    Example:
        ["UKSF_APP_route"] call uksf_ctab_fnc_setMode
*/
params [["_mode", MODE_LAUNCHER, [""]]];

[ANDROID_DIALOG, [["mode", _mode]]] call cTab_fnc_setSettings;
