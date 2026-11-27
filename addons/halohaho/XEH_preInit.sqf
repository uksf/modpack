#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(systemPFHID) = -1;
GVAR(previousTime) = -1;
GVAR(oxygenConnected) = false;
GVAR(oxygenGeneration) = 0;
GVAR(oxygenSound) = -1;
GVAR(oxygenUnit) = objNull;
GVAR(oxygenKilledEH) = -1;
GVAR(hypoxiaLevel) = 0;
GVAR(maxHypoxiaLevel) = 0;

ADDON = true;
