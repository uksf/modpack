#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

GVAR(lastGesture) = 0;
GVAR(stop_statemachine) = locationNull;
GVAR(stop_statemachine_vehicles) = [];

[QGVAR(fireHorn), {call FUNC(fireHorn)}] call CBA_fnc_addEventHandler;

ADDON = true;
