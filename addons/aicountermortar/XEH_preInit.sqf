#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// #include "initSettings.sqf"

GVAR(groundSpawns) = [];
GVAR(airSpawns) = [];
GVAR(unitPool) = [];
GVAR(groundVehiclePool) = [];
GVAR(airVehiclePool) = [];
GVAR(counterBatteryUnits) = [];
GVAR(counterInProgress) = false;

ADDON = true;
