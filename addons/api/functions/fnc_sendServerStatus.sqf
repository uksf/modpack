#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sends current server status and performance metrics to the API. Called periodically.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_api_fnc_sendServerStatus
*/

private _data = createHashMapFromArray [
    ["map", worldName],
    ["mission", missionName],
    ["players", ALL_PLAYERS apply {getPlayerUID _x}],
    ["uptime", time],
    ["processId", GVAR(processId)],
    ["fps", diag_fps],
    ["entityCount", count allUnits + count vehicles],
    ["aiCount", {!isPlayer _x} count allUnits]
];

if (isServer) then {
    _data set ["headlessClientCount", count entities "HeadlessClient_F"];
};

["server_status", _data] call FUNC(sendEvent);
