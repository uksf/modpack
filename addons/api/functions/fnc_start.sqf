#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts the API bridge extension and sends an initial status handshake.
        Called from preStart so the API knows the server is alive before mission load.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_api_fnc_start
*/

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
if (isNil "_startData" || {!(_startData isEqualType createHashMap)}) exitWith {
    ERROR_1("Invalid JSON response from extension start: %1",_result);
};
GVAR(processId) = _startData getOrDefault ["processId", -1];

// Send initial handshake so the API knows the server is alive during mission load
private _data = createHashMapFromArray [
    ["processId", GVAR(processId)],
    ["players", []],
    ["uptime", 0],
    ["entityCount", 0],
    ["aiCount", 0],
    ["headlessClientCount", 0]
];

["server_status", _data] call FUNC(sendEvent);
