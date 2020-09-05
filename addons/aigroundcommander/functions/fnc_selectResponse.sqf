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
    call FUNC(responseInfantryOrMotorInfantry);
};

// infantry + combat light vehicles
if (GVAR(enemyAggressionLevel) >= AGGRESSION_LEVEL_40 && GVAR(enemyAggressionLevel) < AGGRESSION_LEVEL_80) exitWith {
    call FUNC(responseCarAndInfantry);
};

// motor motor inf + APC
if (GVAR(enemyAggressionLevel) >= AGGRESSION_LEVEL_80 && GVAR(enemyAggressionLevel) < AGGRESSION_LEVEL_120) exitWith {
   call FUNC(responseMotorInfantryAndAPC);
};

// Tank + APC -- TIER 2 response
if (GVAR(enemyAggressionLevel) >= AGGRESSION_LEVEL_120 && GVAR(enemyAggressionLevel) < AGGRESSION_LEVEL_160) exitWith {
    if (GVAR(tier2ResponseDeployed)) exitWith {
        call FUNC(responseInfantryOrMotorInfantry);
    };

    GVAR(tier2ResponseDeployed) = true;
    call FUNC(responseTankAndAPC);
};

// Motor Inf + Attack Heli -- TIER 1 response
if (GVAR(enemyAggressionLevel) >= AGGRESSION_LEVEL_160) exitWith {
    if (GVAR(tier1ResponseDeployed)) exitWith {
        call FUNC(responseCarAndInfantry);
    };

    GVAR(tier1ResponseDeployed) = true;
    call FUNC(responseMotorInfantryAndHeliPair);
};
