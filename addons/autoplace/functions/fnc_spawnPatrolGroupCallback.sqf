#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Re-enables virtualisation and assigns patrol task for spawned patrol group.

    Parameters:
        0: Patrol spawn position <ARRAY>
        1: Patrol radius <NUMBER>
        2: Spawned group <GROUP>

    Return Value:
        Nothing

    Example:
        [_spawnPosition, _patrolRadius, _group] call uksf_autoplace_fnc_spawnPatrolGroupCallback
*/
params ["_spawnPosition", "_patrolRadius", "_group"];

if (isNull _group) exitWith {};

[_group, _spawnPosition, _patrolRadius, 4, "MOVE", "SAFE", "YELLOW", "NORMAL", "COLUMN"] call EFUNC(common,taskPatrol);
[_group] call FUNC(storeAndDeleteGroup);
