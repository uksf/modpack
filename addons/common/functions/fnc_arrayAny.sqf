#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns true if any element meets the condition

    Parameters:
        0: Array <ARRAY>
        1: Condition <CODE>

    Return value:
        Boolean
*/
params ["_array", "_condition"];

(_array findIf _condition) != -1
