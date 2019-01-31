#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

call FUNC(getConfigGroups);

[QGVAR(initPatrol), {_this call FUNC(initPatrol)}] call CBA_fnc_addEventHandler;
[QGVAR(spawnGroup), {_this call FUNC(spawnGroup)}] call CBA_fnc_addEventHandler;
[QGVAR(reTask), {_this call CBA_fnc_taskPatrol;}] call CBA_fnc_addEventHandler;

ADDON = true;
