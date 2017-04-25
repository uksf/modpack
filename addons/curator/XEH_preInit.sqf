#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

//Curator access
GVAR(curatorGroup) = creategroup sideLogic;
GVAR(curatorObjects) = [];

ADDON = true;
