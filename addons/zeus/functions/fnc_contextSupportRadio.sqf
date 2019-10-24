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
params ["", "_selectedObjects", "_selectedGroups", "", "", "_hoveredEntity"];

if (!isNull _hoveredEntity) exitWith {
    private _state = _hoveredEntity getVariable [QEGVAR(mission,hasSupportRadio), true];
    [QEGVAR(mission,setSupportRadio), [_hoveredEntity, !_state]] call CBA_fnc_serverEvent;
};

if (!(_selectedObjects isEqualTo [])) exitWith {
    _selectedObjects = _selectedObjects select {_x isKindOf "CAManBase" && {alive _x}};
    private _state = (_selectedObjects findIf {_x getVariable [QEGVAR(mission,hasSupportRadio), true]}) != -1;
    [[QEGVAR(mission,setSupportRadio), [_hoveredEntity, !_state]] call CBA_fnc_serverEvent; false] count _selectedObjects; // If any unit has radio, remove
};

if (!(_selectedGroups isEqualTo [])) exitWith {
    _selectedGroups apply {_selectedObjects append (units _x)};
    _selectedObjects = _selectedObjects select {_x isKindOf "CAManBase" && {alive _x}};
    private _state = (_selectedObjects findIf {_x getVariable [QEGVAR(mission,hasSupportRadio), true]}) != -1;
    [[QEGVAR(mission,setSupportRadio), [_hoveredEntity, !_state]] call CBA_fnc_serverEvent; false] count _selectedObjects; // If any unit of any group has radio, remove
};
