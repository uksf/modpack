#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts statistics collection. Calls all registered provider setup functions
        based on locality, and starts the client sync PFH.

    Parameters:
        None

    Return Value:
        None
*/
// Guard against double-start
if (GVAR(clientSyncPFH) != -1 || {isServer && {GVAR(serverSyncPFH) != -1}}) exitWith {
    WARNING("Statistics collection already started");
};

private _isServer = isServer;
private _isClient = hasInterface;

{
    _y params ["_setupFunction", "_locality"];
    switch (_locality) do {
        case "client": {
            if (_isClient) then {
                call _setupFunction;
            };
        };
        case "server": {
            if (_isServer) then {
                call _setupFunction;
            };
        };
    };
} forEach GVAR(providers);

// Start client sync PFH (every 30 seconds)
if (_isClient) then {
    GVAR(clientSyncPFH) = [{
        call FUNC(clientSync);
    }, 30, []] call CBA_fnc_addPerFrameHandler;
};

// Start server sync PFH (every 60 seconds)
if (_isServer) then {
    GVAR(serverSyncPFH) = [{
        call FUNC(serverSync);
    }, 60, []] call CBA_fnc_addPerFrameHandler;
};

INFO("Statistics collection started");
