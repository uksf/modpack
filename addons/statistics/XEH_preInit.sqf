#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// Provider registry: key -> [setupFunction, locality]
GVAR(providers) = createHashMap;

// Event buffer (used on all machines — clients, HCs, and server)
GVAR(eventBuffer) = [];
GVAR(clientSyncPFH) = -1;

// Performance monitoring: per-frame overhead tracking
// Each provider adds its execution time here during the frame; the PFH sums and resets
GVAR(frameTimings) = createHashMap;
GVAR(frameOverhead) = 0;
GVAR(performancePFH) = -1;

// Explosives deduplication: netId -> classname
// Entries removed on defuse; remaining entries emitted at sync
GVAR(placedExplosives) = createHashMap;

// Sampler state for movement, fuel, and FPS tracking
GVAR(samplerPFH) = -1;
GVAR(lastPosition) = [0, 0, 0];
GVAR(accumulatedDistanceOnFoot) = 0;
GVAR(accumulatedDistanceInVehicle) = 0;
GVAR(lastFuelLevel) = -1;
GVAR(lastFuelVehicle) = objNull;
GVAR(accumulatedFuel) = 0;

// Global killswitch — initialised on all machines so inline checks don't error
// Server broadcasts changes via publicVariable
GVAR(killswitch) = false;

// Guard against double-start (works on all machines including HC)
GVAR(collectionStarted) = false;

if (isServer) then {
    // Server-side event buffer: flat array of event hashmaps
    GVAR(serverBuffer) = [];
    GVAR(serverSyncPFH) = -1;

    // Usage: uksf_statistics_killswitch = true; publicVariable "uksf_statistics_killswitch";
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
