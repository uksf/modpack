#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Support radio context action

    Parameter(s):
        0: Action Parameters

    Return Value:
        None
*/
params ["", "_selectedObjects", "_selectedGroups"];

if (!(_selectedGroups isEqualTo [])) exitWith {
    _selectedGroups apply {_selectedObjects append (units _x)};
    _selectedObjects = _selectedObjects select {_x isKindOf "CAManBase" && {alive _x}};
    private _state = [_selectedObjects, {_x getVariable [QEGVAR(mission,hasSupportRadio), true]}] call FUNC(arrayAny);
    [QEGVAR(mission,setSupportRadio), [_selectedObjects, !_state]] call CBA_fnc_serverEvent; // If any unit of any group has radio, remove
};

if (!(_selectedObjects isEqualTo [])) exitWith {
    _selectedObjects = _selectedObjects select {_x isKindOf "CAManBase" && {alive _x}};
    private _state = [_selectedObjects, {_x getVariable [QEGVAR(mission,hasSupportRadio), true]}] call FUNC(arrayAny);
    [QEGVAR(mission,setSupportRadio), [_selectedObjects, !_state]] call CBA_fnc_serverEvent; // If any unit has radio, remove
};
