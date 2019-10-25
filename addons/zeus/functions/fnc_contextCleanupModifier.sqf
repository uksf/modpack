#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Modifier for cleanup context action

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
    private _state = (_selectedObjects findIf {!(_x getVariable [QEGVAR(cleanup,excluded), false])}) != -1; // At least 1 included = true
    _action set [1, ["Include In Cleanup", "Exclude From Cleanup"] select _state]; // If any objects included, show exclude
    _action set [2, [QPATHTOF(ui\Icon_Module_Cleanup_Include_ca.paa), QPATHTOF(ui\Icon_Module_Cleanup_Exclude_ca.paa)] select _state];
};

if (!(_selectedObjects isEqualTo [])) exitWith {
    private _state = (_selectedObjects findIf {!(_x getVariable [QEGVAR(cleanup,excluded), false])}) != -1; // At least 1 included = true
    _action set [1, ["Include In Cleanup", "Exclude From Cleanup"] select _state]; // If any objects included, show exclude
    _action set [2, [QPATHTOF(ui\Icon_Module_Cleanup_Include_ca.paa), QPATHTOF(ui\Icon_Module_Cleanup_Exclude_ca.paa)] select _state];
};
