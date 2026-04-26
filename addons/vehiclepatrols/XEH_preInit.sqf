#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(spawnPatrol), {
    call FUNC(spawnPatrol);
}] call CBA_fnc_addEventHandler;

ADDON = true;
