#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

#include "initSettings.sqf"

GVAR(iedExcludeAreas) = [];

[QGVAR(revealMineToAllExceptBlufor), {
    params ["_mine"];

    east revealMine _mine;
    civilian revealMine _mine;
    independent revealMine _mine;
}] call CBA_fnc_addEventHandler;

ADDON = true;
