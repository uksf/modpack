#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns true if all elements meet the condition

    Parameters:
        0: Array <ARRAY>
        1: Condition <CODE>

    Return value:
        Boolean

    Example:
        [_array, _condition] call uksf_common_fnc_arrayNone
*/
params ["_array", "_condition"];

(_array findIf _condition) == -1
