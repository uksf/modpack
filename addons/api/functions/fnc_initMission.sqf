#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers mission-scoped event handlers and starts the periodic
        server status push. First load is started from preStart. After an
        in-process mission restart, MPEnded has stopped the bridge — start
        it again here only in that case.

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

GVAR(sessionId) = call CBA_fnc_createUUID;
GVAR(missionEndedSent) = false;
INFO_1("Mission session: %1",GVAR(sessionId));

if (uiNamespace getVariable [QGVAR(needsStart), false]) then {
    uiNamespace setVariable [QGVAR(needsStart), false];
    call FUNC(start);
};

addMissionEventHandler ["MPEnded", {
    if (EGVAR(persistence,shutdownInProgress)) exitWith {
        TRACE_1("MPEnded skipped — shutdown in progress",EGVAR(persistence,shutdownInProgress));
    };

    [QGVAR(missionEnding)] call CBA_fnc_localEvent;
    [] call FUNC(sendMissionEnded);

    call FUNC(sendPerformance);
    "uksf" callExtension "flush";

    EGVAR(common,fpsStore) = createHashMap;
    EGVAR(common,fpsStoreTimestamps) = createHashMap;

    call FUNC(stop);
}];

["mission_started", createHashMapFromArray [
    ["sessionId", GVAR(sessionId)],
    ["map", worldName],
    ["mission", missionName]
]] call FUNC(sendEvent);

GVAR(statusPerFrameHandler) = [{
    call FUNC(sendServerStatus);
}, 15, []] call CBA_fnc_addPerFrameHandler;

GVAR(performancePerFrameHandler) = [{
    call FUNC(sendPerformance);
}, 5, []] call CBA_fnc_addPerFrameHandler;

GVAR(lastPlayerEvent) = createHashMap;

addMissionEventHandler ["PlayerConnected", {
    params ["_id", "_uid", "_name", "_jip", "_owner", "_idstr"];
    if (_name isEqualTo "__SERVER__" || {_uid isEqualTo ""} || {(_uid select [0, 2]) isEqualTo "HC"}) exitWith {};

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
    if (_name isEqualTo "__SERVER__" || {_uid isEqualTo ""} || {(_uid select [0, 2]) isEqualTo "HC"}) exitWith {};

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
