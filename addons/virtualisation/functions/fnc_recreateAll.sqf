#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Recreates all groups
        Admin function, not available unless killswitch is on

    Parameters:
        None

    Return value:
        Nothing

    Example:
        call uksf_virtualisation_fnc_recreateAll
*/
if (!GVAR(killswitched)) exitWith {};

INFO("Recreating all virtualised groups");

[{
    params ["", "_idPFH"];

    if (!GVAR(killswitched)) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if (count GVAR(groupPositionMap) == 0) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
        GVAR(groupDataMap) = createHashMap;
        GVAR(groupPositionMap) = [];
        GVAR(simulatedGroupIds) = [];
        GVAR(simPhases) = createHashMap;
    };

    [0] call FUNC(devirtualiseGroup);
}, 0.2, []] call CBA_fnc_addPerFrameHandler;
