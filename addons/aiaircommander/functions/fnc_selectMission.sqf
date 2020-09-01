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
private _chance = random 10;
private _aircraftChance = random 10;

// CAP
if (_chance <= 5) exitWith {
    if (_aircraftChance <= 5) then {
        [{call FUNC(CAP)}] call FUNC(createGroupPlane);
    } else {
        [{call FUNC(CAP)}] call FUNC(createGroupAttackHeli);
    };
};

// CAS
if ((_chance > 5) && (_chance <= 8) && (EGVAR(aigroundcommander,enemyAggressionLevel) >= 80)) exitWith {
    if (_aircraftChance <= 5) then {
        [{call FUNC(CAS)}] call FUNC(createGroupPlane);
    } else {
        [{call FUNC(CAS)}] call FUNC(createGroupAttackHeli);
    };
};

// SEAD
if (_chance > 8) exitWith {
    [{call FUNC(SEAD)}] call FUNC(createGroupPlane);
};
