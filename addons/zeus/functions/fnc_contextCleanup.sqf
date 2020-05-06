#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Cleanup toggle context action

    Parameter(s):
        0: Action Parameters

    Return Value:
        None
*/
params ["", "_selectedObjects", "_selectedGroups"];

if (!(_selectedGroups isEqualTo [])) exitWith {
    _selectedGroups apply {_selectedObjects append (units _x)};
    private _state = [_selectedGroups, {!(_x getVariable [QEGVAR(cleanup,excluded), false])}] call FUNC(arrayAny); // At least 1 included = true
    [QEGVAR(cleanup,setCleanupState), [_selectedObjects, _state]] call CBA_fnc_serverEvent; // If included, exclude
};

if (!(_selectedObjects isEqualTo [])) exitWith {
    private _state = [_selectedObjects, {!(_x getVariable [QEGVAR(cleanup,excluded), false])}] call FUNC(arrayAny); // At least 1 included = true
    [QEGVAR(cleanup,setCleanupState), [_selectedObjects, _state]] call CBA_fnc_serverEvent; // If included, exclude
};
