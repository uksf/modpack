#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.inc.sqf"

if (isServer) then {
    GVAR(stagingAreas) = [];
    GVAR(infantrySpawns) = [];
    GVAR(carSpawns) = [];
    GVAR(apcSpawns) = [];
    GVAR(tankSpawns) = [];

    GVAR(responseGroups) = [];
    GVAR(transportGroups) = [];
    GVAR(killerPlayers) = [];
    GVAR(stayBehindGroupSelected) = false;
    GVAR(tier1ResponseDeployed) = false;
    GVAR(tier2ResponseDeployed) = false;
    GVAR(readyAtStagingArea) = 0;
    GVAR(enemyAggressionLevel) = 0;
};

ADDON = true;
