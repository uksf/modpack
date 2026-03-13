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

    Example:
        call uksf_api_fnc_start
*/

if (hasInterface) exitWith {};

private _result = "uksf" callExtension "start";
INFO_1("Extension start result: %1",_result);

if (_result == "") exitWith {
    ERROR("Failed to start API extension - DLL may not be loaded");
};

if (toLower (_result select [0, 5]) == "error") exitWith {
    ERROR_1("Extension start returned error: %1",_result);
};

// Result is JSON: {"port":1234,"processId":5678}
private _startData = [_result] call CBA_fnc_parseJSON;
GVAR(processId) = _startData getOrDefault ["processId", -1];

addMissionEventHandler ["ExtensionCallback", {
    params ["_name", "_function", "_data"];
    if (_name != "uksf") exitWith {};
    [_function, _data] call FUNC(handleCommand);
}];

addMissionEventHandler ["MPEnded", {
    if (isServer) then {
        ["mission_ended", createHashMapFromArray [
            ["map", worldName],
            ["mission", missionName],
            ["duration", time]
        ]] call FUNC(sendEvent);

        [GVAR(statusPerFrameHandler)] call CBA_fnc_removePerFrameHandler;
    };
    call FUNC(stop);
}];

if (isServer) then {
    // Send mission started event
    ["mission_started", createHashMapFromArray [
        ["map", worldName],
        ["mission", missionName],
        ["processId", GVAR(processId)]
    ]] call FUNC(sendEvent);

    // Periodic server status push (every 15 seconds)
    GVAR(statusPerFrameHandler) = [{
        call FUNC(sendServerStatus);
        call FUNC(sendPerformance);
    }, 15, []] call CBA_fnc_addPerFrameHandler;

    // Player connect/disconnect events
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
