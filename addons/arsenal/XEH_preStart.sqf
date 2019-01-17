#include "script_component.hpp"
#include "\u\uksf\addons\arsenal\script_mainOpGear.hpp"

#include "XEH_PREP.hpp"

uiNamespace setVariable [QGVAR(mainOpGear), MAIN_OP_GEAR];
uiNamespace setVariable [QGVAR(configLoadouts), ("true" configClasses (configFile >> QGVAR(loadouts)))];
