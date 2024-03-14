#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sends virtualisation data to clients

    Parameters:
        None

    Return value:
        Nothing
*/

{
    [QGVAR(streamData), [GVAR(groupPositionMap), GVAR(groupDataMap)], _x] call CBA_fnc_targetEvent;
} forEach GVAR(dataStreamClientObjects);
