#include "script_component.hpp"

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

//Setup events
if (hasInterface) then {
    GVAR(fpsArray) = [];
    call FUNC(fpsAction);

    [QGVAR(adminHint), {_this call FUNC(adminHint)}] call CBA_fnc_addEventHandler;
};
if (!isServer && !hasInterface) then {
    GVAR(fpsEventID) = [QGVAR(fpsGet), {_this call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;
};
if (isServer) then {
    GVAR(server) = player;
    publicVariable QGVAR(server);
    GVAR(fpsEventID) = [QGVAR(fpsGet), {_this call FUNC(fpsGet)}] call CBA_fnc_addEventHandler;

    [QGVAR(addObjectsToCurators), {_this call FUNC(addObjectsToCurators)}] call CBA_fnc_addEventHandler;
    [QGVAR(serverLog), {INFO(_this select 0)}] call CBA_fnc_addEventHandler;
};
