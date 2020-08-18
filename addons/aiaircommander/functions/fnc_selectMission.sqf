#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Select mission to run based on RNG

    Parameters:
        None.
        
    Return value:
        Nothing
*/

// for debug
// private _chance = 6;
// private _aircraftChance = 1;



private _chance = random 10;
private _aircraftChance = random 10;



// CAP
if (_chance <= 5) exitWith {
    if (_aircraftChance <= 5) then {
        (call FUNC(createGroupPlane)) params ["_group","_spawnPosition"];
        [_group,_spawnPosition] call FUNC(CAP);
    } else {
        (call FUNC(createGroupAttackHeli)) params ["_group","_spawnPosition"];
        [_group,_spawnPosition] call FUNC(CAP);
    };
};

// CAS
if ((_chance > 5) && (_chance <= 8) && (EGVAR(groundCommander,enemyAggressionLevel) >= 40)) exitWith {
    if (_aircraftChance <= 5) then {
        (call FUNC(createGroupPlane)) params ["_group","_spawnPosition"];
        [_group,_spawnPosition] call FUNC(CAS);
    } else {
        (call FUNC(createGroupAttackHeli)) params ["_group","_spawnPosition"];
        [_group,_spawnPosition] call FUNC(CAS);
    };
};

// SEAD
if (_chance > 8) exitWith {
    (call FUNC(createGroupPlane)) params ["_group","_spawnPosition"];
    [_group,_spawnPosition] call FUNC(SEAD);
};