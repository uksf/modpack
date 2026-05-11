#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(katLoaded) = isClass (configFile >> "CfgPatches" >> "kat_airway");
GVAR(interfaceHidden) = false;

#include "initSettings.inc.sqf"
#include "initKeybinds.inc.sqf"

ADDON = true;
