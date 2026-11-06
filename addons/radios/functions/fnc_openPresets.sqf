#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Opens the radio presets manager

    Parameter(s):
        0: Parent display <DISPLAY> (Default: mission display)

    Return Value:
        None

    Example:
        [findDisplay 46] call uksf_radios_fnc_openPresets
*/
params [["_parent", findDisplay 46, [displayNull]]];

private _display = _parent createDisplay QGVAR(presets);
if (isNull _display) exitWith {};

[_display, "refresh"] call FUNC(presetsAction);
