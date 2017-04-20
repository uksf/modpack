/*
    Author:
        Tim Beswick

    Description:
        Function to call curatorStart. This function cannot be recompiled.

    Parameter(s):
        0: The module logic <OBJECT>
        1: Synchronized units <ARRAY>
        2: Activated <BOOL>

    Return Value:
        Boolean
*/
#include "script_component.hpp"

private _return = _this call FUNC(curatorStart);
_return
