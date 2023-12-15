#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Modifier for virtualisation exclude action

    Parameter(s):
        0: Action
        1: Action Parameters

    Return Value:
        None
*/
params ["_action", "_actionParams"];
_actionParams params ["", ["_selectedObjects", []], ["_selectedGroups", []]];

if (_selectedObjects isNotEqualTo []) then {
    {
        _selectedGroups pushBackUnique (group _x);
    } forEach (_selectedObjects select {_x isKindOf "CAManBase" && {alive _x}});
};

if (_selectedGroups isNotEqualTo []) exitWith {
    _selectedGroups = _selectedGroups select {({alive _x} count (units _x)) > 0};

    private _anyIncluded = [_selectedGroups, {!(_x getVariable [QEGVAR(virtualisation,excluded), false])}] call EFUNC(common,arrayAny); // At least 1 included = true
    _action set [1, ["Include In Virtualisation", "Exclude From Virtualisation"] select _anyIncluded]; // If any group included, show exclude
    _action set [2, [QPATHTOF(ui\Icon_Module_Caching_Include_ca.paa), QPATHTOF(ui\Icon_Module_Caching_Exclude_ca.paa)] select _anyIncluded];
};
