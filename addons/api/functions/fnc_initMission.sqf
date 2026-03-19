#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers mission-scoped event handlers and starts the periodic
        server status push. Called from preInit after the extension has
        already been started in preStart.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_api_fnc_initMission
*/

addMissionEventHandler ["ExtensionCallback", {
    params ["_name", "_function", "_data"];
    if (_name != "uksf") exitWith {};
    [_function, _data] call FUNC(handleCommand);
}];

// Generate session ID for this mission run — used by statistics, persistence, and presence
GVAR(sessionId) = call CBA_fnc_createUUID;
INFO_1("Mission session: %1",GVAR(sessionId));

// Fallback for non-persistence-shutdown mission ends (e.g. mission restart)
// During controlled shutdown, shuttingDown handler sends mission_ended instead
addMissionEventHandler ["MPEnded", {
    if (EGVAR(persistence,shutdownInProgress)) exitWith {};

    ["mission_ended", createHashMapFromArray [
        ["sessionId", GVAR(sessionId)],
        ["map", worldName],
        ["mission", missionName],
        ["duration", time]
    ]] call FUNC(sendEvent);

    if (GVAR(statusPerFrameHandler) != -1) then {
        [GVAR(statusPerFrameHandler)] call CBA_fnc_removePerFrameHandler;
        GVAR(statusPerFrameHandler) = -1;
    };
    call FUNC(stop);
}];

["mission_started", createHashMapFromArray [
    ["sessionId", GVAR(sessionId)],
    ["map", worldName],
    ["mission", missionName]
]] call FUNC(sendEvent);

// Periodic server status push (every 15 seconds), only if extension started
if (GVAR(processId) != -1) then {
    GVAR(statusPerFrameHandler) = [{
        call FUNC(sendServerStatus);
    }, 15, []] call CBA_fnc_addPerFrameHandler;
};

// Player presence tracking — debounced to prevent spam from rapid reconnects
GVAR(lastPlayerEvent) = createHashMap;

addMissionEventHandler ["PlayerConnected", {
    params ["_id", "_uid", "_name", "_jip", "_owner", "_idstr"];
    private _key = format ["connected_%1", _uid];
    private _lastTime = GVAR(lastPlayerEvent) getOrDefault [_key, -10];
    if (diag_tickTime - _lastTime < 5) exitWith {};
    GVAR(lastPlayerEvent) set [_key, diag_tickTime];

    ["player_connected", createHashMapFromArray [
        ["sessionId", GVAR(sessionId)],
        ["name", _name],
        ["uid", _uid]
    ]] call FUNC(sendEvent);
}];

addMissionEventHandler ["PlayerDisconnected", {
    params ["_id", "_uid", "_name", "_jip", "_owner", "_idstr"];
    private _key = format ["disconnected_%1", _uid];
    private _lastTime = GVAR(lastPlayerEvent) getOrDefault [_key, -10];
    if (diag_tickTime - _lastTime < 5) exitWith {};
    GVAR(lastPlayerEvent) set [_key, diag_tickTime];

    ["player_disconnected", createHashMapFromArray [
        ["sessionId", GVAR(sessionId)],
        ["name", _name],
        ["uid", _uid]
    ]] call FUNC(sendEvent);
}];
