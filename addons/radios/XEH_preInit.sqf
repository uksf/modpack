#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(presetsDone) = false;

[QEGVAR(lobby,respawned), {
    [] call FUNC(setChannelNames);
}] call CBA_fnc_addEventHandler;

ADDON = true;
