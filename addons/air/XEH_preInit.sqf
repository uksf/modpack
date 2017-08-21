#include "script_component.hpp"

ADDON = false;

[{
    player setVariable ["UK3CB_voice_enabled", 0];
}, []] call CBA_fnc_execNextFrame;

ADDON = true;
