#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// Addon globals are initialized here and filled by runtime functions.
GVAR(commanders) = [];
GVAR(objectives) = [];
GVAR(enabled) = false;
GVAR(debugGridRadius) = 2500;
GVAR(overlayEnabled) = false;
GVAR(overlayEH) = -1;
GVAR(safeSpawnOverlayEnabled) = false;
GVAR(safeSpawnOverlayEH) = -1;

ADDON = true;


