#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Condition for the Watch context action. Requires at least one alive
        selected object.

    Parameter(s):
        0: Action Parameters

    Return Value:
        Boolean

    Example:
        [_selectedObjects, _selectedGroups] call uksf_zeus_fnc_contextCanWatch
*/
params ["", "_selectedObjects"];

_selectedObjects isNotEqualTo [] && {alive (_selectedObjects # 0)}
