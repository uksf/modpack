#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates a control inside an app's content group.
        The position is given in fractions of the group, so a layout fits the full screen and the side panel alike.
        Every control uses the same font height, a fourteenth of the group height.

    Parameter(s):
        0: App content group <CONTROL>
        1: Control class <STRING>
        2: Position as [x, y, w, h] fractions of the group <ARRAY>
        3: Text (Optional, default "") <STRING>

    Return Value:
        Control <CONTROL>

    Example:
        [_group, "cTab_RscButton", [0, 0.9, 0.5, 0.1], "Clear"] call uksf_ctab_fnc_createCtrl
*/
params ["_group", "_class", "_rect", ["_text", ""]];
_rect params ["_left", "_top", "_width", "_height"];

(ctrlPosition _group) params ["", "", "_groupWidth", "_groupHeight"];

private _ctrl = (ctrlParent _group) ctrlCreate [_class, -1, _group];
_ctrl ctrlSetPosition [_left * _groupWidth, _top * _groupHeight, _width * _groupWidth, _height * _groupHeight];
_ctrl ctrlSetFontHeight (_groupHeight / 14);
if (_text != "") then {
    _ctrl ctrlSetText _text;
};
_ctrl ctrlCommit 0;
_ctrl
