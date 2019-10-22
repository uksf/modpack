#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

if (isServer) then {
    [QGVAR(addKilled), {GVAR(killed) pushback [_this, CBA_missionTime]}] call CBA_fnc_addEventHandler;
};

ADDON = true;
