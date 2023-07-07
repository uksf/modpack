#include "script_component.hpp"

#include "XEH_PREP.hpp"

// Cache main op gear
call FUNC(getMainOpGear);

uiNamespace setVariable [QGVAR(configLoadouts), ("true" configClasses (configFile >> QGVAR(loadouts)))];
