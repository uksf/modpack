#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(audio), {call FUNC(audio)}] call CBA_fnc_addEventHandler;

GVAR(trackedMissiles) = [];

ADDON = true;
