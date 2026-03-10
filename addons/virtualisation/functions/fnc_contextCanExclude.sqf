#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Can use virtualisation exclude context action

    Parameter(s):
        0: Action Parameters

    Return Value:
        Boolean

    Example:
        [_selectedObjects, _selectedGroups] call uksf_virtualisation_fnc_contextCanExclude
*/
params ["", "_selectedObjects", "_selectedGroups"];

if (!GVAR(enabled)) exitWith {false};

if (_selectedGroups isNotEqualTo []) exitWith {
    ({({alive _x && !isPlayer _x} count (units _x)) > 0} count _selectedGroups) > 0
};

if (_selectedObjects isNotEqualTo []) exitWith {
    ({
        ({alive _x && !isPlayer _x} count (units _x)) > 0
    } count (_selectedObjects select {_x isKindOf "CAManBase" && alive _x && !isPlayer _x})) > 0
};

false
