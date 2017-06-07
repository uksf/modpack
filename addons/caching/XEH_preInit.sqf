#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

if (isServer) then {
    [QGVAR(disableCache), {_this call FUNC(disableCache)}] call CBA_fnc_addEventHandler;
};
[QGVAR(setDynamicSimulation), {(_this select 0) enableDynamicSimulation (_this select 1)}] call CBA_fnc_addEventHandler;

ADDON = true;
