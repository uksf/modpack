#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

//Curator access
GVAR(curatorGroup) = creategroup sideLogic;
GVAR(curatorObjects) = [];
GVAR(curatorsLocked) = false;
GVAR(curatorLogged) = false;

//Anti-ping
GVAR(pingCount) = 0;
GVAR(pingTime) = 0;

//Loadout copying
GVAR(loadout) = "";

ADDON = true;
