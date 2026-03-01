#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// Provider registry: key -> [setupFunction, locality]
GVAR(providers) = createHashMap;

// Client-side event buffer (array of event hashmaps)
GVAR(eventBuffer) = [];
GVAR(clientSyncPFH) = -1;

if (isServer) then {
    // Server-side event buffer: flat array of event hashmaps
    GVAR(serverBuffer) = [];
    GVAR(serverSyncPFH) = -1;

    // Handle incoming client reports
    [QGVAR(clientReport), {
        _this call FUNC(handleClientReport);
    }] call CBA_fnc_addEventHandler;

    // Flush remaining data on mission end
    // Delay server flush to allow client final syncs to arrive first
    addMissionEventHandler ["MPEnded", {
        [{
            call FUNC(serverSync);
            call FUNC(stopCollection);
        }, [], 5] call CBA_fnc_waitAndExecute;
    }];
};

if (hasInterface) then {
    addMissionEventHandler ["MPEnded", {
        call FUNC(clientSync);
        call FUNC(stopCollection);
    }];
};

#include "initSettings.inc.sqf"

ADDON = true;
