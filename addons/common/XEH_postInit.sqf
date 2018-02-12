#include "script_component.hpp"
#include "keybinds.sqf"


// Set server object
if (isServer) then {
    GVAR(server) = player;
    publicVariable QGVAR(server);

    // Delete empty groups every 5 minutes
    [{
        [QGVAR(deleteEmptyGroups), []] call CBA_fnc_globalEvent;
    }, 300, []] call cba_fnc_addPerFrameHandler;
};

// Set headless client array. Player if singleplayer
GVAR(HCs) = [];
if (isMultiplayer && !is3DENMultiplayer) then {
    GVAR(HCs) = (entities "HeadlessClient_F");
} else {
    GVAR(HCs) pushBack player;
};

[QEGVAR(lobby,respawned), {
    // Add FPS action
    if (hasInterface) then {
        call FUNC(fpsAction);
    };
}] call CBA_fnc_addEventHandler;

if (hasInterface) then {
    ["visibleMap", {
        params ["", "_mapOn"];
        [_mapOn] call FUNC(mapPosition);
    }] call CBA_fnc_addPlayerEventHandler;
};

if (isServer) then {
    if (GVAR(mainOp)) then {
        ["ace_medical_useLocation_PAK", 3, 0, "server", false] call CBA_settings_fnc_set;
        ["uksf_curator_curatorsLocked", true, 0, "server", false] call CBA_settings_fnc_set;
    } else {
        ["ace_medical_useLocation_PAK", 0, 0, "server", false] call CBA_settings_fnc_set;
        ["uksf_curator_curatorsLocked", false, 0, "server", false] call CBA_settings_fnc_set;
    };
};
