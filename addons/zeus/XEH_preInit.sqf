#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(loadout) = "";
GVAR(fpsEnabled) = false;
GVAR(EHIDArray) = [];
GVAR(curatorUnconciousMapID) = 999;

["CAManBase", "respawn", {
    if (hasInterface && {isMultiplayer}) then {
        GVAR(fpsEnabled) = MULTIPLAYER_ADMIN_OR_WHITELISTED;
        [{
            player setVariable [QGVAR(fps), floor diag_fps, true];
        }, 1, []] call CBA_fnc_addPerFrameHandler;
    };
}] call CBA_fnc_addClassEventHandler;

[QGVAR(paradrop), {call FUNC(paradrop)}] call CBA_fnc_addEventHandler;
[QGVAR(moveInCargo), {_this#0 moveInCargo _this#1}] call CBA_fnc_addEventHandler;

if (hasInterface) then {
    call FUNC(addContextActions);
};

ADDON = true;
