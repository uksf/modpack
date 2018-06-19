#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(variableHandler) = call CBA_fnc_createNamespace;
GVAR(shockwaveArray) = [];

ADDON = true;
