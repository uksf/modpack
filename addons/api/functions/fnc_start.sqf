#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the API bridge extension. Only runs on the dedicated server.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_api_fnc_start
*/

if (!isServer) exitWith {};

private _result = "uksf" callExtension "start";
INFO_1("Extension start result: %1",_result);

if (_result == "") exitWith {
    ERROR("Failed to start API extension - DLL may not be loaded");
};

if (toLower (_result select [0, 5]) == "error") exitWith {
    ERROR_1("Extension start returned error: %1",_result);
};

// Result is JSON: {"port":1234,"processId":5678}
private _startData = [_result, 2] call CBA_fnc_parseJSON;
GVAR(processId) = _startData getOrDefault ["processId", -1];

addMissionEventHandler ["ExtensionCallback", {
    params ["_name", "_function", "_data"];
    if (_name != "uksf") exitWith {};
    [_function, _data] call FUNC(handleCommand);
}];

addMissionEventHandler ["MPEnded", {
    // TODO: re-enable when statistics branch lands — API needs to store these events
    // ["mission_ended", createHashMapFromArray [
    //     ["map", worldName],
    //     ["mission", missionName],
    //     ["duration", time]
    // ]] call FUNC(sendEvent);

    [GVAR(statusPerFrameHandler)] call CBA_fnc_removePerFrameHandler;
    call FUNC(stop);
}];

// TODO: re-enable when statistics branch lands — API needs to store these events
// ["mission_started", createHashMapFromArray [
//     ["map", worldName],
//     ["mission", missionName],
//     ["processId", GVAR(processId)]
// ]] call FUNC(sendEvent);

// Periodic server status push (every 15 seconds)
GVAR(statusPerFrameHandler) = [{
    call FUNC(sendServerStatus);
}, 15, []] call CBA_fnc_addPerFrameHandler;

// TODO: re-enable when statistics branch lands — API needs to store and track session durations
// GVAR(lastPlayerEvent) = createHashMap;
//
// addMissionEventHandler ["PlayerConnected", {
//     params ["_id", "_uid", "_name", "_jip", "_owner", "_idstr"];
//     private _key = format ["connected_%1", _uid];
//     private _lastTime = GVAR(lastPlayerEvent) getOrDefault [_key, -10];
//     if (diag_tickTime - _lastTime < 5) exitWith {};
//     GVAR(lastPlayerEvent) set [_key, diag_tickTime];
//
//     ["player_connected", createHashMapFromArray [
//         ["name", _name],
//         ["uid", _uid]
//     ]] call FUNC(sendEvent);
// }];
//
// addMissionEventHandler ["PlayerDisconnected", {
//     params ["_id", "_uid", "_name", "_jip", "_owner", "_idstr"];
//     private _key = format ["disconnected_%1", _uid];
//     private _lastTime = GVAR(lastPlayerEvent) getOrDefault [_key, -10];
//     if (diag_tickTime - _lastTime < 5) exitWith {};
//     GVAR(lastPlayerEvent) set [_key, diag_tickTime];
//
//     ["player_disconnected", createHashMapFromArray [
//         ["name", _name],
//         ["uid", _uid]
//     ]] call FUNC(sendEvent);
// }];
