#include "script_component.hpp"
#include "keybinds.sqf"

// Delete groups every 5 minutes
[{
    {deleteGroup _x; false} count allGroups;
}, 300, []] call cba_fnc_addPerFrameHandler;

// Set server object
if (isServer) then {
    GVAR(server) = player;
    publicVariable QGVAR(server);
};

// Set headless client array. Player if singleplayer
GVAR(HCs) = [];
if (isMultiplayer && !is3DENMultiplayer) then {
    GVAR(HCs) = (entities "HeadlessClient_F");
} else {
    GVAR(HCs) pushBack player;
};

[QEGVAR(lobby,respawned), {
    // Ensure rating never goes below 0.
    player addEventHandler ["HandleRating", {
        (_this select 1) max 0
    }];

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

if (GVAR(mainOp)) then {
    ["ace_medical_useLocation_PAK", 3, 0, "server", true] call CBA_settings_fnc_set;
} else {
    ["ace_medical_useLocation_PAK", 0, 0, "server", true] call CBA_settings_fnc_set;
};
