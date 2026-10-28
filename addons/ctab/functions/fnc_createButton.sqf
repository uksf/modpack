#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates a button inside an app's content group.
        The code runs on the next frame, so it can change the cTab mode or delete the button safely.

    Parameter(s):
        0: App content group <CONTROL>
        1: Position as [x, y, w, h] fractions of the group <ARRAY>
        2: Text <STRING>
        3: Code, called with [button] <CODE>

    Return Value:
        Button control <CONTROL>

    Example:
        [_group, [0, 0.9, 0.5, 0.1], "Clear", {call uksf_ctab_fnc_routeClear}] call uksf_ctab_fnc_createButton
*/
params ["_group", "_rect", "_text", "_code"];

private _button = [_group, "cTab_RscButton", _rect, _text] call FUNC(createCtrl);
_button setVariable [QGVAR(code), _code];
_button ctrlAddEventHandler ["ButtonClick", {
    params ["_button"];
    [_button getVariable QGVAR(code), [_button]] call CBA_fnc_execNextFrame;
}];
_button
