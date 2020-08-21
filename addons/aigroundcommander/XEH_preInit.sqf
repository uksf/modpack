#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        PreInit for:
            - Init AI Aggression Level <NUMBER>
            - Add MP Killed EH to units for aggression calc <EH>

    Parameters:
        None
        
    Return value:
        Nothing
*/

if (!isServer) exitWith {};

["O_Soldier_base_F","init", {
    _this#0 addMPEventHandler ["MPKilled", {
        if (!(_this#1 isKindOf "Air")) then {
            GVAR(enemyAggressionLevel) = GVAR(enemyAggressionLevel) + 1;
            if ((_this#2) isEqualTo objNull || !isPlayer (_this#2) || surfaceIsWater (getPos (_this#2))) exitWith {};
            GVAR(playersThatHaveFired) pushBack [(_this#2), time];
        };
}]}] call cba_fnc_addClassEventHandler;

GVAR(stagingAreas) = [];

// spawn locations
GVAR(infantryLocations) = [];
GVAR(carLocations) = [];
GVAR(apcLocations) = [];
GVAR(tankLocations) = [];

// unit cap
GVAR(maxUnitCount) = 80;
GVAR(currentUnitCount) = 0;

// response groups
GVAR(responseGroups) = [];
GVAR(numberOfStayBehindGroups) = 1;
GVAR(tier1ResponseDeployed) = 0;
GVAR(tier2ResponseDeployed) = 0;
GVAR(readyAtStagingArea) = 0;


// up to date aggression level variable
GVAR(enemyAggressionLevel) = 0;

// list of players that have fired their weapon
GVAR(playersThatHaveFired) = [];

ADDON = true;
