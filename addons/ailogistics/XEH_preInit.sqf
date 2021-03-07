#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// #include "initSettings.sqf"

GVAR(unitPoolString) = [];
GVAR(logisticVehiclePoolString) = [];
GVAR(routePickets) = false;
GVAR(picketLocations) = [];
GVAR(picketUnitPoolString) = [];
GVAR(picketGroupSize) = 0;
GVAR(logisticsObject) = ObjNull;
GVAR(logisticalVehicleNumber) = 0;

ADDON = true;
