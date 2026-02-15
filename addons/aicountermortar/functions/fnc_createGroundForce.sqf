#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Creates ground hunter force type

    Parameters:
        0: Spawn position <ARRAY>
        1: Target position <ARRAY>

    Return value:
        Nothing
*/
params ["_spawnPosition", "_targetPosition"];

[_spawnPosition, east, GVAR(unitPool), GVAR(groundVehiclePool), {-1}, {
    params ["_targetPosition", "_group", "_vehicle"];

    _vehicle setUnloadInCombat [true, true];
    [_group, _targetPosition] call FUNC(assignWaypoints);

    private _index = _vehicle addMPEventHandler ["MPHit", {
        params ["_vehicle"];

        private _index = _vehicle getVariable [QGVAR(hitEHID), -1];
        _vehicle removeMPEventHandler ["MPKilled", _index];

        [{GVAR(counterInProgress) = false}, [], 900] call CBA_fnc_waitAndExecute; // 15 minute wait time between tasks so mortars dont get spammed each time they fire
    }];

    _vehicle setVariable [QGVAR(hitEHID), _index, true];
}, [_targetPosition]] call EFUNC(common,spawnGroupVehicle);
