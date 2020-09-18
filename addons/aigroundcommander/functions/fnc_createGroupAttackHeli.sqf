#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create attack heli group

    Parameters:
        0: Spawn position <ARRAY>
        1: Staging area position <ARRAY>
        2: Player position <ARRAY>
        3: Spawn count <SCALAR>

    Return value:
        Nothing
*/
params ["_spawnPosition", "_stagingAreaPosition", "_playerPosition", "_count"];

[_spawnPosition, 1, 0, EAST, EGVAR(gear,gearHeliPilot), EGVAR(gear,gearAttackHeli), {
    params ["_vehicle", "_turrets"];

    (_vehicle emptyPositions "driver") + count _turrets
}, {
    params ["", "", "", "", "_group", "_vehicle"];

    _vehicle flyInHeight 150;
    GVAR(responseGroups) pushBack _group;
    call FUNC(addWaypoints);
}, [_spawnPosition, _stagingAreaPosition, _playerPosition, _count]] call EFUNC(common,spawnGroup);
