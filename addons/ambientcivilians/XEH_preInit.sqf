#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

GVAR(dynamicPatrolAreasEnabled) = false;

GVAR(dynamicPatrolAreaAttributeConfig) = EGVAR(common,configVehicles) >> QGVAR(moduleDynamicPatrolArea) >> "Attributes";

GVAR(dynamicPatrolGroups) = [];
GVAR(dynamicPatrolAreas) = [];
GVAR(dynamicPatrolExcludeAreas) = [];
GVAR(dynamicPatrolIncludeAreas) = [];

[QGVAR(dynamicPatrol), {call FUNC(dynamicPatrol)}] call CBA_fnc_addEventHandler;
[QGVAR(dynamicPatrolArea), {call FUNC(dynamicPatrolArea)}] call CBA_fnc_addEventHandler;
[QGVAR(dynamicPatrolSpawn), {call FUNC(dynamicPatrolSpawn)}] call CBA_fnc_addEventHandler;

["CAManBase", "init", {_this#0 addMPEventHandler ["MPHit", {call FUNC(hit)}]}] call CBA_fnc_addClassEventHandler;

GVAR(dynamicPatrolDebugMap) = createHashMap;
GVAR(dynamicPatrolDebugPlayers) = [];

ADDON = true;
