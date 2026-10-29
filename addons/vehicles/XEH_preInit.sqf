#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(driverCompartmentHash) = createHashMap;
GVAR(cargoCompartmentHash) = createHashMap;
GVAR(turretCompartmentHash) = createHashMap;

[QGVAR(swapDriver), {call FUNC(swapDriverLocal)}] call CBA_fnc_addEventHandler;

GVAR(spotlightVehicles) = [
    "UK3CB_BAF_Jackal_Base",
    "UK3CB_BAF_Husky_Base",
    "UK3CB_BAF_LandRover_WMIK_Base",
    "CUP_Mastiff_Base",
    "CUP_Ridgback_Base",
    "CUP_Wolfhound_Base",
    "UK3CB_BAF_FV432_Mk3_Base",
    "CUP_Challenger2_base",
    "UK3CB_BAF_RHIB_Base",
    "RHICC_MAIN",
    "Helmatic"
];
GVAR(markingLaserClasses) = createHashMap;
GVAR(spotlightTurretCache) = createHashMap;
GVAR(spotlights) = [];
GVAR(spotlightCleanupHandle) = -1;
[QGVAR(setSpotlight), {call FUNC(setSpotlight)}] call CBA_fnc_addEventHandler;

ADDON = true;
