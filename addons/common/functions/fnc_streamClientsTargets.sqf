#include "script_component.hpp"
/*
    Author:
        UKSF

    Description:
        Prunes a stream-client list and returns the live player objects.

    Parameter(s):
        0: List <ARRAY>

    Return Value:
        Players <ARRAY>

    Example:
        [_list] call uksf_common_fnc_streamClientsTargets
*/
params ["_list"];

[_list] call FUNC(streamClientsPrune);
_list apply {_x select 0}
