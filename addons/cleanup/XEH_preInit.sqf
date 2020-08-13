#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

if (isServer) then {
    [QGVAR(addKilled), {GVAR(killed) pushback [_this, CBA_missionTime]}] call CBA_fnc_addEventHandler;
    [QGVAR(setCleanupState), {call FUNC(setCleanupState)}] call CBA_fnc_addEventHandler;

    {
        [_x, "init", {[QGVAR(addKilled), _this#0] call CBA_fnc_serverEvent}] call CBA_fnc_addClassEventHandler;
    } forEach ["UK3CB_BAF_1Rnd_60mm_Mo_Shells_spent", "UK3CB_BAF_1Rnd_81mm_Mo_Shells_spent"];
};

ADDON = true;
