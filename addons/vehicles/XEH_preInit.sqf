#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(driverCompartmentHash) = createHashMap;
GVAR(cargoCompartmentHash) = createHashMap;
GVAR(turretCompartmentHash) = createHashMap;

ADDON = true;
