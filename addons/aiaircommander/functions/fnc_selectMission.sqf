#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Select mission to run based on RNG

    Parameters:
        None

    Return value:
        Nothing
*/
#define MAX_RETRIES 4

params [["_retries", 0]];

if (_retries > MAX_RETRIES) exitWith {};

private _chance = random 10;
private _aircraftChance = random 10;

// CAP
if (_chance <= 5) exitWith {
    if (_aircraftChance <= 5) then {
        [{call FUNC(CAP)}, [], _retries] call FUNC(createGroupPlane);
    } else {
        [{call FUNC(CAP)}, [], _retries] call FUNC(createGroupAttackHeli);
    };
};

// CAS
if ((_chance > 5) && (_chance <= 8) && (EGVAR(aigroundcommander,enemyAggressionLevel) >= 80)) exitWith {
    if (_aircraftChance <= 5) then {
        [{call FUNC(CAS)}, [], _retries] call FUNC(createGroupPlane);
    } else {
        [{call FUNC(CAS)}, [], _retries] call FUNC(createGroupAttackHeli);
    };
};

// SEAD
if (_chance > 8) exitWith {
    [{call FUNC(SEAD)}, [], _retries] call FUNC(createGroupPlane);
};
