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
//private _chance = 6;
//private _aircraftChance = 6;



private _chance = random 10;
private _aircraftChance = random 10;



// CAP
if (_chance <= 5) exitWith {
    if (_aircraftChance <= 5) then {
        private _group = call FUNC(createGroupPlane);
        [_group] call FUNC(CAP);
    } else {
        private _group = call FUNC(createGroupAttackHeli);
        [_group] call FUNC(CAP);
    };
};

// CAS
if ((_chance > 5) && (_chance <= 8) && (EGVAR(aigroundCommander,enemyAggressionLevel) >= 80)) exitWith {
    if (_aircraftChance <= 5) then {
        private _group = call FUNC(createGroupPlane);
        [_group] call FUNC(CAS);
    } else {
        private _group = call FUNC(createGroupAttackHeli);
        [_group] call FUNC(CAS);
    };
};

// SEAD
if (_chance > 8) exitWith {
    private _group = call FUNC(createGroupPlane);
    [_group] call FUNC(SEAD);
};
