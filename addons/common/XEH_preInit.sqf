#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(moduleInitCollection) = [];
GVAR(HCs) = [];
GVAR(fpsState) = false;
GVAR(fpsArray) = [];

if (isServer) then {
    INFO("Calling settings");
    call FUNC(loadSettings);
};

ADDON = true;
