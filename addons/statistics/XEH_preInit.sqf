#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(providers) = createHashMap;

GVAR(eventBuffer) = [];
GVAR(clientSyncPFH) = -1;

GVAR(placedExplosives) = createHashMap;

GVAR(ammoCategoryCache) = createHashMap;

GVAR(samplerPFH) = -1;
GVAR(lastPosition) = [0, 0, 0];
GVAR(samplerDistanceOnFoot) = [];
GVAR(samplerDistanceInVehicle) = [];
GVAR(samplerFuelLitres) = [];
GVAR(lastFuelLevel) = -1;
GVAR(lastFuelVehicle) = objNull;

GVAR(killswitch) = false;
GVAR(collectionStarted) = false;

if (isDedicated) then {
    GVAR(serverBuffer) = [];
    GVAR(serverSyncPFH) = -1;

    [QGVAR(clientReport), {
        _this call FUNC(handleClientReport);
    }] call CBA_fnc_addEventHandler;

    [QEGVAR(persistence,shutdownStarted), {
        call FUNC(stopCollection);
    }] call CBA_fnc_addEventHandler;

    [QEGVAR(persistence,shutdownFinishing), {
        TRACE_1("Shutdown: final server sync",count GVAR(serverBuffer));
        call FUNC(serverSync);
    }] call CBA_fnc_addEventHandler;

    [QEGVAR(api,missionEnding), {
        TRACE_1("Mission ending: flushing and stopping",count GVAR(serverBuffer));
        call FUNC(serverSync);
        call FUNC(stopCollection);
    }] call CBA_fnc_addEventHandler;
};

if (!isServer) then {
    [QEGVAR(persistence,shutdownFinishing), {
        TRACE_1("Shutdown: flushing client buffers",count GVAR(eventBuffer));
        call FUNC(clientSync);
        call FUNC(stopCollection);
    }] call CBA_fnc_addEventHandler;
};

#include "initSettings.inc.sqf"

ADDON = true;
