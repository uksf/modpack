#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Can use support radio context action

    Parameter(s):
        0: Action Parameters

    Return Value:
        Boolean
*/
params ["", "_selectedObjects", "_selectedGroups"];

if (!EGVAR(mission,support) && {!EGVAR(mission,artillerySupport)}) exitWith {false};

if (_selectedGroups isNotEqualTo []) exitWith {
    _selectedGroups apply {_selectedObjects append (units _x)};
    ({_x isKindOf "CAManBase" && {alive _x}} count _selectedObjects) > 0
};

if (_selectedObjects isNotEqualTo []) exitWith {
    ({_x isKindOf "CAManBase" && {alive _x}} count _selectedObjects) > 0
};

false
