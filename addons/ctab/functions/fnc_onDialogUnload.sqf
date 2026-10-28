#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Handles the Unload event of the cTab Android dialog.
        Closes the open launcher or app, and returns the dialog to BFT so the next open and the small Android display start on a cTab page.

    Parameter(s):
        0: cTab display <DISPLAY>

    Return Value:
        False, so the engine still runs cTab's own onUnload. A true result marks the event handled and skips it, which leaves cTab open and blocks the next open <BOOL>

    Example:
        _display displayAddEventHandler ["Unload", {call uksf_ctab_fnc_onDialogUnload}]
*/
params ["_display"];

[_display, true] call FUNC(closeContent);
if (([ANDROID_DIALOG, "mode"] call cTab_fnc_getSettings) find MODE_PREFIX == 0) then {
    [ANDROID_DIALOG, [["mode", DEFAULT_MODE]], false] call cTab_fnc_setSettings;
};

false
