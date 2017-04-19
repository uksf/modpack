#include "script_component.hpp"

//Activate all addons
private _addons = [];
private _cfgPatches = configFile >> "CfgPatches";
for "_i" from 0 to (count _cfgPatches - 1) do {
    private _class = _cfgPatches select _i;
    if (isClass _class) then {
        _addons set [count _addons, configName _class];
    };
};
_addons call bis_fnc_activateaddons;

//Delete groups every 5 minutes
[{
    {deleteGroup _x; false} count allGroups;
}, 300, []] call cba_fnc_addPerFrameHandler;

//Set headless client array. Player if singleplayer
GVAR(HCs) = [];
if (isMultiplayer && !is3DENMultiplayer) then {
    GVAR(HCs) = (entities "HeadlessClient_F");
} else {
    GVAR(HCs) pushBack player;
};

//Setup FPS display events
if (hasInterface) then {
    GVAR(fpsArray) = [];
    call FUNC(fpsAction);
};
if (!isServer && !hasInterface) then {
    GVAR(fpsEventID) = [QGVAR(fpsGet), {_this call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;
};
if (isServer) then {
    GVAR(server) = player;
    publicVariable QGVAR(server);
    GVAR(fpsEventID) = [QGVAR(fpsGet), {_this call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;
};
