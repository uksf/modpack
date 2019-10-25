#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Modifier for caching context action

    Parameter(s):
        0: Action
        1: Action Parameters

    Return Value:
        None
*/
params ["_action", "_actionParams"];
_actionParams params ["", "_selectedObjects", "_selectedGroups"];

if (!(_selectedGroups isEqualTo [])) exitWith {
    _selectedGroups = _selectedGroups select {({alive _x} count (units _x)) > 0};
    private _state = (_selectedGroups findIf {!(_x getVariable [QEGVAR(caching,excluded), false])}) != -1; // At least 1 included = true
    _action set [1, ["Include In Caching", "Exclude From Caching"] select _state]; // If any group included, show exclude
    _action set [2, [QPATHTOF(ui\Icon_Module_Caching_Include_ca.paa), QPATHTOF(ui\Icon_Module_Caching_Exclude_ca.paa)] select _state];
};

if (!(_selectedObjects isEqualTo [])) exitWith {
    _selectedGroups = [];
    {
        if (({alive _x} count (units _x)) > 0) then {
            _selectedGroups pushBackUnique (group _x);
        };
        false
    } count (_selectedObjects select {_x isKindOf "CAManBase" && {alive _x}});
    private _state = (_selectedGroups findIf {!(_x getVariable [QEGVAR(caching,excluded), false])}) != -1; // At least 1 included = true
    _action set [1, ["Include In Caching", "Exclude From Caching"] select _state]; // If any group included, show exclude
    _action set [2, [QPATHTOF(ui\Icon_Module_Caching_Include_ca.paa), QPATHTOF(ui\Icon_Module_Caching_Exclude_ca.paa)] select _state];
};
