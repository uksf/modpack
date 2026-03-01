#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(ammoConfigCache) = createHashMap;
GVAR(fortificationClassCache) = createHashMap;

#include "initSettings.inc.sqf"

ADDON = true;
