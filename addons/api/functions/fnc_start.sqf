#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the API bridge extension. Only runs on dedicated servers and headless clients.

    Parameters:
        None

    Return Value:
        None
*/

if (hasInterface) exitWith {};

private _result = "uksf" callExtension "start";
INFO_1("Extension start: %1",_result);

addMissionEventHandler ["ExtensionCallback", {
    params ["_name", "_function", "_data"];
    if (_name != "uksf") exitWith {};
    [_function, _data] call FUNC(handleCommand);
}];

addMissionEventHandler ["MPEnded", {
    ["mission_ended", createHashMapFromArray [
        ["map", worldName],
        ["mission", missionName],
        ["duration", time]
    ]] call FUNC(sendEvent);
    call FUNC(stop);
}];

// Send mission started event
["mission_started", createHashMapFromArray [
    ["map", worldName],
    ["mission", missionName]
]] call FUNC(sendEvent);

// Periodic server status push (every 15 seconds)
[{
    call FUNC(sendServerStatus);
    call FUNC(sendPerformance);
}, 15, []] call CBA_fnc_addPerFrameHandler;

// Player connect/disconnect events (server only)
if (isServer) then {
    addMissionEventHandler ["PlayerConnected", {
        params ["_id", "_uid", "_name", "_jip", "_owner", "_idstr"];
        ["player_connected", createHashMapFromArray [
            ["name", _name],
            ["uid", _uid]
        ]] call FUNC(sendEvent);
    }];

    addMissionEventHandler ["PlayerDisconnected", {
        params ["_id", "_uid", "_name", "_jip", "_owner", "_idstr"];
        ["player_disconnected", createHashMapFromArray [
            ["name", _name],
            ["uid", _uid]
        ]] call FUNC(sendEvent);
    }];
};
