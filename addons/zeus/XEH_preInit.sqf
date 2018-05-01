#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(loadout) = "";
GVAR(fpsEnabled) = false;
GVAR(EHIDArray) = [];
GVAR(curatorUnconciousMapID) = 999;

[QEGVAR(lobby,respawned), {
    if (hasInterface && {isMultiplayer}) then {
        GVAR(fpsEnabled) = MULTIPLAYER_ADMIN_OR_WHITELISTED;
        [{
            player setVariable [QGVAR(fps), floor diag_fps, true];
        }, 1, []] call CBA_fnc_addPerFrameHandler;
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
