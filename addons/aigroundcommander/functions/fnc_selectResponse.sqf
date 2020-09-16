#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Checks aggression level and executes appropriate response script

    Parameters:
        None

    Return value:
        Nothing
*/
// TODO: Should be settings
#define AGGRESSION_LEVEL_MIN 22
#define AGGRESSION_LEVEL_40 40
#define AGGRESSION_LEVEL_80 80
#define AGGRESSION_LEVEL_120 120
#define AGGRESSION_LEVEL_160 160

call FUNC(cleanup);
if (!isServer || {count GVAR(responseGroups) > GVAR(groupLimit)}) exitWith {};

GVAR(readyAtStagingArea) = 0;

// inf or motor inf
if (GVAR(enemyAggressionLevel) < AGGRESSION_LEVEL_40 && GVAR(enemyAggressionLevel) > AGGRESSION_LEVEL_MIN) exitWith {
    if (random 10 <= 5) then {
        [GVAR(infantrySpawns), 30, 3, FUNC(createGroupInfantry)] call FUNC(response);
    } else {
        [GVAR(carSpawns), 15, 2, FUNC(createGroupCarTransport)] call FUNC(response);
    };
};

// infantry + combat light vehicles
if (GVAR(enemyAggressionLevel) >= AGGRESSION_LEVEL_40 && GVAR(enemyAggressionLevel) < AGGRESSION_LEVEL_80) exitWith {
    [GVAR(carSpawns), 5, 4, FUNC(createGroupCar)] call FUNC(response);
    [GVAR(infantrySpawns), 30, 3, FUNC(createGroupInfantry)] call FUNC(response);
};

// motor inf + APC
if (GVAR(enemyAggressionLevel) >= AGGRESSION_LEVEL_80 && GVAR(enemyAggressionLevel) < AGGRESSION_LEVEL_120) exitWith {
    [GVAR(apcSpawns), 15, 3, FUNC(createGroupAPC)] call FUNC(response);
    [GVAR(carSpawns), 15, 2, FUNC(createGroupCarTransport)] call FUNC(response);
};

// Tank + APC -- TIER 2 response
if (GVAR(enemyAggressionLevel) >= AGGRESSION_LEVEL_120 && GVAR(enemyAggressionLevel) < AGGRESSION_LEVEL_160) exitWith {
    if (GVAR(tier2ResponseDeployed)) exitWith {
        if (random 10 <= 5) then {
            [GVAR(infantrySpawns), 30, 3, FUNC(createGroupInfantry)] call FUNC(response);
        } else {
            [GVAR(carSpawns), 15, 2, FUNC(createGroupCarTransport)] call FUNC(response);
        };
    };

    GVAR(tier2ResponseDeployed) = true;
    [GVAR(apcSpawns), 12, 2, FUNC(createGroupAPC)] call FUNC(response);
    [GVAR(tankSpawns), 12, 2, FUNC(createGroupTank)] call FUNC(response);
};

// Motor Inf + Attack Heli -- TIER 1 response
if (GVAR(enemyAggressionLevel) >= AGGRESSION_LEVEL_160) exitWith {
    if (GVAR(tier1ResponseDeployed)) exitWith {
        [GVAR(carSpawns), 5, 4, FUNC(createGroupCar)] call FUNC(response);
        [GVAR(infantrySpawns), 30, 3, FUNC(createGroupInfantry)] call FUNC(response);
    };

    GVAR(tier1ResponseDeployed) = true;
    [GVAR(carSpawns), 15, 2, FUNC(createGroupCarTransport)] call FUNC(response);
    [EGVAR(aiaircommander,heliSpawns), 30, 2, FUNC(createGroupAttackHeli)] call FUNC(response);
};
