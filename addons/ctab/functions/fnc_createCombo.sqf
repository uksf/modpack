#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Creates a combo box inside an app's content group and selects one entry.
        Each entry is a [text, value] pair. The code runs with the selected value when the selection changes.

    Parameter(s):
        0: App content group <CONTROL>
        1: Position as [x, y, w, h] fractions of the group <ARRAY>
        2: Entries as [text, value] pairs <ARRAY>
        3: Value to select, the first entry if no entry has it <ANY>
        4: Code, called with [selected value, combo] on a selection change <CODE>

    Return Value:
        Combo control <CONTROL>

    Example:
        [_group, [0, 0, 1, 0.1], [["2 m", 2], ["10 m", 10]], 2, {params ["_height"]}] call uksf_ctab_fnc_createCombo
*/
params ["_group", "_rect", "_entries", "_selected", "_code"];

private _combo = [_group, QGVAR(combo), _rect] call FUNC(createCtrl);
{
    _combo lbAdd (_x select 0);
} forEach _entries;
_combo setVariable [QGVAR(values), _entries apply {_x select 1}];
_combo lbSetCurSel (0 max (_entries findIf {(_x select 1) isEqualTo _selected}));
_combo setVariable [QGVAR(code), _code];
_combo ctrlAddEventHandler ["LBSelChanged", {
    params ["_combo", "_index"];
    if (_index < 0) exitWith {};
    [(_combo getVariable QGVAR(values)) select _index, _combo] call (_combo getVariable QGVAR(code));
}];
_combo
