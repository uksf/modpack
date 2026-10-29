#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates the content group for the launcher or an app, filling its container over a dark background.
        The content group is deleted when the launcher or app closes.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: Container control group <CONTROL>
        2: Close code, called with [display, content group] before the content group is deleted <CODE>
        3: Background opacity <NUMBER>

    Return Value:
        Content group <CONTROL>

    Example:
        [_display, _container, {}, 1] call uksf_ctab_fnc_createContent
*/
params ["_display", "_container", "_onClose", "_opacity"];

(ctrlPosition _container) params ["", "", "_width", "_height"];

private _group = _display ctrlCreate ["RscControlsGroupNoScrollbars", -1, _container];
_group ctrlSetPosition [0, 0, _width, _height];
_group ctrlCommit 0;

private _background = _display ctrlCreate ["cTab_RscText", -1, _group];
_background ctrlSetPosition [0, 0, _width, _height];
_background ctrlSetBackgroundColor [0.05, 0.05, 0.05, _opacity];
_background ctrlCommit 0;

GVAR(content) = [_group, _onClose];
_group
