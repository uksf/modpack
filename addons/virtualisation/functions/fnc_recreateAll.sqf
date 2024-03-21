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
    };

    private _id = GVAR(groupPositionMap)#0#0;
    GVAR(groupPositionMap) deleteAt 0;

    private _groupData = GVAR(groupDataMap) deleteAt _id;
    [QGVAR(recreateGroup), [_groupData]] call EFUNC(common,headlessEvent);

    call FUNC(sendDataToClients);
}, 0.2, []] call CBA_fnc_addPerFrameHandler;
