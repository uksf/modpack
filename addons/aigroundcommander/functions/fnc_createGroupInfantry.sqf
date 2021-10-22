#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create Infantry group

    Parameters:
        0: Spawn position <ARRAY>
        1: Staging area position <ARRAY>
        2: Player position <ARRAY>
        3: Spawn count <SCALAR>

    Return value:
        Nothing
*/
params ["_spawnPosition", "_stagingAreaPosition", "_playerPosition", "_count"];
TRACE_1("",_this);

private _unitCount = ceil ((random 4) + 6);
[_spawnPosition getPos [10, random 360], _unitCount, EAST, EGVAR(gear,gearSoldier), {
    params ["", "", "", "", "_group"];

    GVAR(responseGroups) pushBack _group;
    TRACE_1("",_this);
    call FUNC(addWaypoints);
}, [_spawnPosition, _stagingAreaPosition, _playerPosition, _count]] call EFUNC(common,spawnGroupInfantry);
