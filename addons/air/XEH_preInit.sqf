#include "script_component.hpp"

ADDON = false;

[QEGVAR(lobby,respawned), {
    player setVariable ["UK3CB_voice_enabled", 0, true];
}] call CBA_fnc_addEventHandler;

ADDON = true;
