#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles the Unload event of the cTab Android dialog.
        Closes the open launcher or app and remembers it, so the next open of the dialog returns to it.
        Returns the cTab mode to BFT so the small Android display starts on a cTab page.

    Parameter(s):
        0: cTab display <DISPLAY>

    Return Value:
        False, so the engine still runs cTab's own onUnload. A true result marks the event handled and skips it, which leaves cTab open and blocks the next open <BOOL>

    Example:
        _display displayAddEventHandler ["Unload", {call uksf_ctab_fnc_onDialogUnload}]
*/
params ["_display"];

[_display, true] call FUNC(closeContent);

private _mode = [ANDROID_DIALOG, "mode"] call cTab_fnc_getSettings;
GVAR(lastMode) = ["", _mode] select (_mode find MODE_PREFIX == 0);
if (GVAR(lastMode) != "") then {
    [ANDROID_DIALOG, [["mode", DEFAULT_MODE]], false] call cTab_fnc_setSettings;
};

false
