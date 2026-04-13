#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(destinationModules) = [];
GVAR(activePatrols) = [];

[QGVAR(spawnPatrol), {
    call FUNC(spawnPatrol);
}] call CBA_fnc_addEventHandler;

ADDON = true;
