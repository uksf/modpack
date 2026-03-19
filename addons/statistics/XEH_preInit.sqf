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

GVAR(samplerPFH) = -1;
GVAR(lastPosition) = [0, 0, 0];
GVAR(accumulatedDistanceOnFoot) = 0;
GVAR(accumulatedDistanceInVehicle) = 0;
GVAR(lastFuelLevel) = -1;
GVAR(lastFuelVehicle) = objNull;
GVAR(accumulatedFuel) = 0;

GVAR(killswitch) = false;
GVAR(collectionStarted) = false;

if (isServer) then {
    GVAR(serverBuffer) = [];
    GVAR(serverSyncPFH) = -1;

    [QGVAR(clientReport), {
        _this call FUNC(handleClientReport);
    }] call CBA_fnc_addEventHandler;

    [QEGVAR(persistence,shutdownStarted), {
        call FUNC(stopCollection);
    }] call CBA_fnc_addEventHandler;

    [QEGVAR(persistence,shuttingDown), {
        call FUNC(serverSync);
    }] call CBA_fnc_addEventHandler;

    // MPEnded fallback for non-persistence-shutdown scenarios (e.g. mission restart)
    addMissionEventHandler ["MPEnded", {
        call FUNC(stopCollection);
        call FUNC(serverSync);
    }];
};

if (!isServer) then {
    [QEGVAR(persistence,shuttingDown), {
        call FUNC(stopCollection);
        call FUNC(clientSync);
    }] call CBA_fnc_addEventHandler;
};

#include "initSettings.inc.sqf"

ADDON = true;
