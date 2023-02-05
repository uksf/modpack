#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(cachedGroupsData) = createHashMap;
GVAR(cachedGroupsPositions) = [];

#include "initSettings.sqf"

ADDON = true;
