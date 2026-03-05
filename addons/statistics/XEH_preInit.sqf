#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// Provider registry: key -> [setupFunction, locality]
GVAR(providers) = createHashMap;

// Client-side event buffer (array of event hashmaps)
GVAR(eventBuffer) = [];
GVAR(clientSyncPFH) = -1;

// Performance monitoring: per-frame overhead tracking
// Each provider adds its execution time here during the frame; the PFH sums and resets
GVAR(frameTimings) = createHashMap;
GVAR(frameOverhead) = 0;
GVAR(performancePFH) = -1;

if (isServer) then {
    // Server-side event buffer: flat array of event hashmaps
    GVAR(serverBuffer) = [];
    GVAR(serverSyncPFH) = -1;

    // Global killswitch — set via debug console to disable all collection and pushing
    // Usage: uksf_statistics_killswitch = true; publicVariable "uksf_statistics_killswitch";
    GVAR(killswitch) = false;
    publicVariable QGVAR(killswitch);

    // Handle incoming client reports
    [QGVAR(clientReport), {
        _this call FUNC(handleClientReport);
    }] call CBA_fnc_addEventHandler;

    // Flush and stop when persistence shutdown starts
    [QEGVAR(persistence,shutdownStarted), {
        call FUNC(serverSync);
        call FUNC(stopCollection);
    }] call CBA_fnc_addEventHandler;

    // MPEnded fallback for non-persistence-shutdown scenarios (e.g. mission restart)
    addMissionEventHandler ["MPEnded", {
        call FUNC(serverSync);
        call FUNC(stopCollection);
    }];
};

#include "initSettings.inc.sqf"

ADDON = true;
