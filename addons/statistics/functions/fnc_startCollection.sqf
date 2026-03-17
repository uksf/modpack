#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Starts statistics collection. Calls all registered provider setup functions
        based on locality, and starts sync PFHs for the local machine type.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_startCollection
*/
// Guard against double-start (works on all machines including HC)
if (GVAR(collectionStarted)) exitWith {
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
        case "all": {
            call _setupFunction;
        };
    };
} forEach GVAR(providers);

// Start client sync PFH (every 30 seconds)
if (_isClient) then {
    GVAR(clientSyncPFH) = [{
        call FUNC(clientSync);
    }, 30, []] call CBA_fnc_addPerFrameHandler;
};

// Start performance monitoring PFH (every frame)
if (_isClient) then {
    GVAR(performancePFH) = [{
        call FUNC(performancePFH);
    }, 0, []] call CBA_fnc_addPerFrameHandler;
};

// Start HC sync PFH (every 30 seconds) — same as client sync but for headless clients
if (!_isServer && !_isClient) then {
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

GVAR(collectionStarted) = true;
INFO("Statistics collection started");
