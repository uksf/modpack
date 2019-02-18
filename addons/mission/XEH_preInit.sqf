#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

[QGVAR(initPatrol), {call FUNC(initPatrol)}] call CBA_fnc_addEventHandler;
[QGVAR(spawnGroup), {call FUNC(spawnGroup)}] call CBA_fnc_addEventHandler;
[QGVAR(reTask), {call CBA_fnc_taskPatrol;}] call CBA_fnc_addEventHandler;

ADDON = true;
