#include "script_component.hpp"

ADDON = false;

["CAManBase", "respawn", {
    player setVariable ["UK3CB_voice_enabled", 0, true];
}, true, nil, true] call CBA_fnc_addClassEventHandler;

ADDON = true;
