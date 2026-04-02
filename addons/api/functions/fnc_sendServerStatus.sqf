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

if (!isServer) exitWith {};

private _data = createHashMapFromArray [
    ["map", worldName],
    ["mission", missionName],
    ["players", ALL_PLAYERS apply {getPlayerUID _x}],
    ["uptime", time],
    ["processId", GVAR(processId)],
    ["entityCount", count allUnits + count vehicles],
    ["aiCount", {!isPlayer _x} count allUnits]
];

_data set ["headlessClientCount", count entities "HeadlessClient_F"];

["server_status", _data] call FUNC(sendEvent);
