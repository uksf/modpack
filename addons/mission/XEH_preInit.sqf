#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

GVAR(dynamicPatrolAreasEnabled) = false;

GVAR(dynamicPatrolAreaAttributeConfig) = EGVAR(common,configVehicles) >> QGVAR(moduleDynamicPatrolArea) >> "Attributes";

GVAR(artillerySupportUnits) = [];
GVAR(dynamicPatrolGroups) = [];
GVAR(dynamicPatrolAreas) = [];
GVAR(dynamicPatrolExcludeAreas) = [];
GVAR(dynamicPatrolIncludeAreas) = [];

GVAR(safehousePrefabAreaModules) = [];
GVAR(safehouseLocationModules) = [];
GVAR(safehousePrefabs) = [];

[QGVAR(reTask), {call CBA_fnc_taskPatrol}] call CBA_fnc_addEventHandler;
[QGVAR(initPatrol), {call FUNC(initPatrol)}] call CBA_fnc_addEventHandler;
[QGVAR(spawnGroup), {call FUNC(spawnGroup)}] call CBA_fnc_addEventHandler;
[QGVAR(fireMission), {call FUNC(fireMission)}] call CBA_fnc_addEventHandler;
[QGVAR(setSupportRadio), {call FUNC(setSupportRadio)}] call CBA_fnc_addEventHandler;

[QGVAR(hitFiltered), {call FUNC(support)}] call CBA_fnc_addEventHandler;
[QGVAR(hitFiltered), {call FUNC(artillerySupport)}] call CBA_fnc_addEventHandler;

[QGVAR(dynamicPatrol), {call FUNC(dynamicPatrol)}] call CBA_fnc_addEventHandler;
[QGVAR(dynamicPatrolArea), {call FUNC(dynamicPatrolArea)}] call CBA_fnc_addEventHandler;
[QGVAR(dynamicPatrolSpawn), {call FUNC(dynamicPatrolSpawn)}] call CBA_fnc_addEventHandler;

["CAManBase", "init", {_this#0 addMPEventHandler ["MPHit", {call FUNC(hit)}]}] call CBA_fnc_addClassEventHandler;
["StaticMortar", "init", {call FUNC(addArtillerySupportUnit)}] call CBA_fnc_addClassEventHandler;
["CUP_D30_base", "init", {call FUNC(addArtillerySupportUnit)}] call CBA_fnc_addClassEventHandler;
["CUP_BM21_Base", "init", {call FUNC(addArtillerySupportUnit)}] call CBA_fnc_addClassEventHandler;
["CUP_M270_HE_Base", "init", {call FUNC(addArtillerySupportUnit)}] call CBA_fnc_addClassEventHandler;

ADDON = true;
