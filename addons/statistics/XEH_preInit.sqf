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

// Explosives deduplication: object reference -> classname
// Entries removed on defuse; remaining entries emitted at sync
GVAR(placedExplosives) = createHashMap;

// Sampler state for movement, fuel, and FPS tracking
GVAR(samplerPFH) = -1;
GVAR(lastPosition) = [0, 0, 0];
GVAR(accumulatedDistance) = 0;
GVAR(lastFuelLevel) = -1;
GVAR(lastFuelVehicle) = objNull;
GVAR(accumulatedFuel) = 0;

// Global killswitch — initialised on all machines so client checks don't error
// Server broadcasts changes via publicVariable; clients listen in XEH_postInit
GVAR(killswitch) = false;

// Guard against double-start (works on all machines including HC)
GVAR(collectionStarted) = false;

if (isServer) then {
    // Server-side event buffer: flat array of event hashmaps
    GVAR(serverBuffer) = [];
    GVAR(serverSyncPFH) = -1;

    // Usage: uksf_statistics_killswitch = true; publicVariable "uksf_statistics_killswitch";
    publicVariable QGVAR(killswitch);

    // Damage attribution ledger: netId -> array of damage entries
    // Each entry: {uid, damage, weapon, hitPoint, distance2D, distance3D, time}
    GVAR(damageLedger) = createHashMap;
    GVAR(damageLedgerMeta) = createHashMap;

    // Periodic ledger cleanup: remove entries for targets that no longer exist
    // Runs every 120 seconds to catch entities removed by garbage collection
    // Emits surviving damage entries as standalone events so no attribution data is lost
    [{
        private _keysToRemove = [];
        {
            private _object = objectFromNetId _x;
            if (isNull _object) then {
                _keysToRemove pushBack _x;
            };
        } forEach (keys GVAR(damageLedger));
        {
            private _damageHistory = GVAR(damageLedger) get _x;
            private _meta = GVAR(damageLedgerMeta) getOrDefault [_x, createHashMap];
            // Emit each contributor's total damage as a standalone event
            private _contributorMap = createHashMap;
            {
                private _uid = _x get "uid";
                private _existing = _contributorMap getOrDefault [_uid, 0];
                _contributorMap set [_uid, _existing + (_x get "damage")];
            } forEach _damageHistory;
            {
                GVAR(serverBuffer) pushBack createHashMapFromArray [
                    ["type", "damage"],
                    ["uid", _x],
                    ["totalDamage", _y],
                    ["targetClassname", _meta getOrDefault ["classname", ""]],
                    ["targetType", _meta getOrDefault ["targetType", ""]]
                ];
            } forEach _contributorMap;
            GVAR(damageLedger) deleteAt _x;
            GVAR(damageLedgerMeta) deleteAt _x;
        } forEach _keysToRemove;
    }, 120, []] call CBA_fnc_addPerFrameHandler;

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
