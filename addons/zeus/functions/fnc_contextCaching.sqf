#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Caching toggle context action

    Parameter(s):
        0: Action Parameters

    Return Value:
        None
*/
params ["", "_selectedObjects", "_selectedGroups"];

if (!(_selectedGroups isEqualTo [])) exitWith {
    _selectedGroups = _selectedGroups select {({alive _x} count (units _x)) > 0};
    private _state = [_selectedGroups, {!(_x getVariable [QEGVAR(caching,excluded), false])}] call FUNC(arrayAny); // At least 1 included = true
    {
        [[QEGVAR(caching,enableCache), QEGVAR(caching,disableCache)] select _state, [_x]] call CBA_fnc_serverEvent; // If included, exclude
    } forEach _selectedGroups;
};

if (!(_selectedObjects isEqualTo [])) exitWith {
    _selectedGroups = [];
    {
        if (({alive _x} count (units _x)) > 0) then {
            _selectedGroups pushBackUnique (group _x);
        };
    } forEach (_selectedObjects select {_x isKindOf "CAManBase" && {alive _x}});
    private _state = [_selectedObjects, {!(_x getVariable [QEGVAR(caching,excluded), false])}] call FUNC(arrayAny); // At least 1 included = true
    {
        [[QEGVAR(caching,enableCache), QEGVAR(caching,disableCache)] select _state, [_x]] call CBA_fnc_serverEvent; // If included, exclude
    } forEach _selectedGroups;
};
