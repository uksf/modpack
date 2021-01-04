#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

[QGVAR(reTask), {call FUNC(returnToStartPosition)}] call CBA_fnc_addEventHandler;
[QGVAR(initPatrol), {call FUNC(initPatrol)}] call CBA_fnc_addEventHandler;

[QGVAR(hitFiltered), {call FUNC(support)}] call CBA_fnc_addEventHandler;

["CAManBase", "init", {_this#0 addMPEventHandler ["MPHit", {call FUNC(hit)}]}] call CBA_fnc_addClassEventHandler;

ADDON = true;
