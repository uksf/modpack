#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Checks aggression level and executes appropriate response script
    Parameters:
        None.

    Return value:
        Nothing
*/

#define AGGRESSION_LEVEL_40 40;
#define AGGRESSION_LEVEL_80 80;
#define AGGRESSION_LEVEL_120 120;
#define AGGRESSION_LEVEL_160 160;

if (!isServer) exitWith {};
if (GVAR(currentUnitCount) >= GVAR(maxUnitcount)) exitWith {};

// inf or motor inf
if (GVAR(enemyAggressionLevel) < GVAR(aggressionLevel40) && GVAR(enemyAggressionLevel) > 22) exitWith {
    call FUNC(responseInfantryOrMotorInfantry);
};

// infantry + combat light vehicles
if (GVAR(enemyAggressionLevel) >= GVAR(aggressionLevel40) && GVAR(enemyAggressionLevel) <= 79) exitWith {
    call FUNC(responseCarAndInfantry);
};

// motor motor inf + APC
if (GVAR(enemyAggressionLevel) >= GVAR(aggressionLevel80) && GVAR(enemyAggressionLevel) <= 119) exitWith {
   call FUNC(responseMotorInfantryAndAPC);
};

// Tank + APC -- TIER 2 response
if (GVAR(enemyAggressionLevel) >= GVAR(aggressionLevel120) && GVAR(enemyAggressionLevel) <= 159) exitWith {
    if (GVAR(tier2ResponseDeployed) == 1) exitWith {
        call FUNC(responseInfantryOrMotorInfantry);
    };
    GVAR(tier2ResponseDeployed) = 1;
    call FUNC(responseTankAndAPC);
};

// Motor Inf + Attack Heli -- TIER 1 response
if (GVAR(enemyAggressionLevel) >= GVAR(aggressionLevel160)) exitWith {
    if (GVAR(tier1ResponseDeployed) == 1) exitWith {
        call FUNC(responseCarAndInfantry);
    };
    GVAR(tier1ResponseDeployed) = 1;
    call FUNC(responseMotorInfantryAndHeliPair);
};
