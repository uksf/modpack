#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns dynamic patrol visualisation data for Zeus.

    Parameter(s):
        None

    Return Value:
        Array of patrol data
*/

private _areas = GVAR(dynamicPatrolAreas) apply {
    _x params ["_logic", "_area"];
    private _position = getPosATL _logic;
    private _groups = _logic getVariable [QGVAR(groups), []];
    private _groupCount = {!isNull _x} count _groups;
    private _groupLimit = _logic getVariable [QGVAR(groupLimit), 0];
    private _distance = _logic getVariable [QGVAR(distance), 500];
    private _sideIndex = _logic getVariable [QGVAR(side), 0];
    private _side = [east, independent, west] param [_sideIndex, east];

    [_position, _area, _groupCount, _groupLimit, _distance, _side]
};

private _excludeAreas = GVAR(dynamicPatrolExcludeAreas) apply {
    _x params ["_logic", "_area"];
    [getPosATL _logic, _area]
};

private _includeAreas = GVAR(dynamicPatrolIncludeAreas) apply {
    _x params ["_logic", "_area"];
    [getPosATL _logic, _area]
};

[_areas, _excludeAreas, _includeAreas]
