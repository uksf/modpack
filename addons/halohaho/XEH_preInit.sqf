#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(systemPFHID) = -1;
GVAR(oxygenConnected) = false;
GVAR(hypoxiaLevel) = 0;
GVAR(maxHypoxiaLevel) = 0;

ADDON = true;
