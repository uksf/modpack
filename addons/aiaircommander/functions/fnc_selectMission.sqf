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
        (call FUNC(createGroupPlane)) params ["_group"];
        [_group] call FUNC(CAP);
    } else {
        (call FUNC(createGroupAttackHeli)) params ["_group"];
        [_group] call FUNC(CAP);
    };
};

// CAS
if ((_chance > 5) && (_chance <= 8) && (EGVAR(aigroundCommander,enemyAggressionLevel) >= 80)) exitWith {
    if (_aircraftChance <= 5) then {
        (call FUNC(createGroupPlane)) params ["_group"];
        [_group] call FUNC(CAS);
    } else {
        (call FUNC(createGroupAttackHeli)) params ["_group"];
        [_group] call FUNC(CAS);
    };
};

// SEAD
if (_chance > 8) exitWith {
    (call FUNC(createGroupPlane)) params ["_group"];
    [_group] call FUNC(SEAD);
};