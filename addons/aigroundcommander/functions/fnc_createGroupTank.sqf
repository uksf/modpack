#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create Tank with only crew, no dismounts

    Parameters:
        0: Spawn position <ARRAY>
        1: Staging area position <ARRAY>
        2: Player position <ARRAY>
        3: Spawn count <SCALAR>

    Return value:
        Nothing
*/
params ["_spawnPosition", "_stagingAreaPosition", "_playerPosition", "_count"];

private _nearRoads = _spawnPosition nearRoads 100;
private _roadSpawn = selectRandom _nearRoads;
_spawnPosition = [getPos _roadSpawn, _spawnPosition getPos [20, random 360]] select (isNull _roadSpawn);

[_spawnPosition, 1, 0, EAST, EGVAR(gear,gearCrew), EGVAR(gear,gearTank), {
    params ["_vehicle", "_turrets"];

    (_vehicle emptyPositions "driver") + count _turrets
}, {
    params ["", "", "", "", "_group"];

    GVAR(responseGroups) pushBack _group;
    call FUNC(addWaypoints);
}, [_spawnPosition, _stagingAreaPosition, _playerPosition, _count]] call EFUNC(common,spawnGroup);
