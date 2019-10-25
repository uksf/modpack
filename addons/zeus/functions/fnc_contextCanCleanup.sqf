#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Can use toggle cleanup context action

    Parameter(s):
        0: Action Parameters

    Return Value:
        Boolean
*/
params ["", "_selectedObjects", "_selectedGroups"];

if (!EGVAR(cleanup,enabled)) exitWith {false};

if (!(_selectedGroups isEqualTo [])) exitWith {
    ({(count (units _x)) > 0} count _selectedGroups) > 0
};

if (!(_selectedObjects isEqualTo [])) exitWith {
    (count _selectedObjects) > 0
};

false
