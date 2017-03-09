#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(settingsInitFinished) = false;
GVAR(HCs) = [];
GVAR(fpsState) = false;
GVAR(fpsArray) = [];

if (isServer) then {
    call FUNC(loadSettings);
};

ADDON = true;
