#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Closes the launcher or app shown in the cTab Android dialog.
        Removes the app's map handlers and cancels a map click still waiting for its double-click window, calls its close code, then deletes its content group unless the display is unloading.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: Display is unloading, so the engine deletes the controls (Optional, default false) <BOOL>

    Return Value:
        Nothing

    Example:
        [_display] call uksf_ctab_fnc_closeContent
*/
params ["_display", ["_unloading", false]];

{
    _x params ["_map", "_event", "_handler"];
    _map ctrlRemoveEventHandler [_event, _handler];
    _map setVariable [QGVAR(pendingClick), -1];
    _map setVariable [QGVAR(clickCode), {}];
} forEach GVAR(mapHandlers);
GVAR(mapHandlers) = [];

if (GVAR(content) isEqualTo []) exitWith {};

GVAR(content) params ["_group", "_onClose"];
GVAR(content) = [];
GVAR(currentApp) = "";

[_display, _group] call _onClose;
if (!_unloading) then {
    ctrlDelete _group;
};
