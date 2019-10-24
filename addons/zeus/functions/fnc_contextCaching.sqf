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
params ["", "_selectedObjects", "_selectedGroups", "", "", "_hoveredEntity"];

if (!isNull _hoveredEntity) exitWith {
    private _state = (group _hoveredEntity) getVariable [QEGVAR(caching,excluded), false];
    [[QEGVAR(caching,disableCache), QEGVAR(caching,enableCache)] select _state, [(group _hoveredEntity)]] call CBA_fnc_serverEvent; // If excluded, include
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
    {
        [[QEGVAR(caching,enableCache), QEGVAR(caching,disableCache)] select _state, [(group _hoveredEntity)]] call CBA_fnc_serverEvent; // If included, exclude
        false
    } count _selectedGroups;
};

if (!(_selectedGroups isEqualTo [])) exitWith {
    _selectedGroups = _selectedGroups select {({alive _x} count (units _x)) > 0};
    private _state = (_selectedGroups findIf {!(_x getVariable [QEGVAR(caching,excluded), false])}) != -1; // At least 1 included = true
    {
        [[QEGVAR(caching,enableCache), QEGVAR(caching,disableCache)] select _state, [(group _hoveredEntity)]] call CBA_fnc_serverEvent; // If included, exclude
        false
    } count _selectedGroups;
};
