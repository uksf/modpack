#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creates ground hunter force type

    Parameters:
        0: Spawn position <ARRAY>
        1: Mortar position <ARRAY>

    Return value:
        Nothing
*/
params ["_spawnPosition", "_mortarPosition"];

[_spawnPosition, 1, 0, EAST, GVAR(unitPool), GVAR(groundVehiclePool), {-1}, {
    params ["_mortarPosition", "_group", "_vehicle"];

    _vehicle setUnloadInCombat [true, true];
    [_group, _mortarPosition] call FUNC(assignWaypoints);

    _vehicle addMPEventHandler ["MPHit", {
        [{GVAR(counterInProgress) = 0}, [], 900] call CBA_fnc_waitAndExecute; // 15 minute wait time between tasks so mortars dont get spammed each time they fire
    }];
}, [_mortarPosition]] call EFUNC(common,spawnGroup);
