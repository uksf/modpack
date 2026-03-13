#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sends current server status to the API. Called periodically.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_api_fnc_sendServerStatus
*/

private _playerCount = count ALL_PLAYERS;
private _data = createHashMapFromArray [
    ["map", worldName],
    ["mission", missionName],
    ["playerCount", _playerCount],
    ["uptime", time],
    ["processId", GVAR(processId)]
];

if (isServer) then {
    _data set ["fps", diag_fps];
};

["server_status", _data] call FUNC(sendEvent);
