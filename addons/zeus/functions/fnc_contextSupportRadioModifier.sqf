#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Modifier for support radio context action

    Parameter(s):
        0: Action
        1: Action Parameters

    Return Value:
        None
*/
params ["_action", "_actionParams"];
_actionParams params ["", "_selectedObjects", "_selectedGroups"];

if (!(_selectedGroups isEqualTo [])) exitWith {
    _selectedGroups apply {_selectedObjects append (units _x)};
    _selectedObjects = _selectedObjects select {_x isKindOf "CAManBase" && {alive _x}};
    private _state = [_selectedObjects, {_x getVariable [QEGVAR(mission,hasSupportRadio), true]}] call EFUNC(common,arrayAny); // At least 1 has radio = true
    _action set [1, ["Give Support Radio", "Remove Support Radio"] select _state]; // If any unit of any group has radio, show remove
};

if (!(_selectedObjects isEqualTo [])) exitWith {
    _selectedObjects = _selectedObjects select {_x isKindOf "CAManBase" && {alive _x}};
    private _state = [_selectedObjects, {_x getVariable [QEGVAR(mission,hasSupportRadio), true]}] call EFUNC(common,arrayAny); // At least 1 has radio = true
    _action set [1, ["Give Support Radio", "Remove Support Radio"] select _state]; // If any unit has radio, show remove
};
