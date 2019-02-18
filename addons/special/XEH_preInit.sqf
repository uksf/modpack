#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

[QGVAR(movingTarget), {call FUNC(movingTarget)}] call CBA_fnc_addEventHandler;

ADDON = true;
