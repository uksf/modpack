#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// Killswitches — set via debug console to disable mission types at runtime
// e.g. uksf_airthreat_capReconEnabled = false;
GVAR(capReconEnabled) = true;
GVAR(interceptEnabled) = true;
GVAR(casStrikeEnabled) = true;

// Configuration — populated by controller module
GVAR(capReconBaseTime) = 1200;
GVAR(capReconOffsetTime) = 600;
GVAR(initialDelay) = 1800;
GVAR(initialDelayOffset) = 900;
GVAR(interceptCooldown) = 600;
GVAR(interceptCooldownOffset) = 600;
GVAR(maxConcurrentMissions) = 3;
GVAR(fighterClassnames) = [];
GVAR(casClassnames) = [];
GVAR(strikeClassnames) = [];
GVAR(reconClassnames) = [];
GVAR(excludedClasses) = [];
GVAR(exclusionMarkers) = [];

// State — server only
GVAR(activeMissions) = [];
GVAR(spawnPoints) = [];
GVAR(airspaces) = [];
GVAR(casStrikeZones) = [];
GVAR(interceptZones) = [];
GVAR(controllerInitialised) = false;

// Intercept state
GVAR(nextInterceptTime) = 0;

// Server events — mission tracking
[QGVAR(missionComplete), {
    params ["_group", "_vehicle"];
    [_group, _vehicle] call FUNC(unregisterMission);
}] call CBA_fnc_addEventHandler;

[QGVAR(registerMission), {
    params ["_group", "_vehicle", "_missionType"];
    GVAR(activeMissions) pushBack [_group, _vehicle, _missionType];
    INFO_2("Mission registered: %1 (active: %2)",_missionType,count GVAR(activeMissions));
}] call CBA_fnc_addEventHandler;

// HC events — mission spawn handlers (headlessEvent routes here, or to server if no HC)
[QGVAR(spawnCap), { _this call FUNC(cap) }] call CBA_fnc_addEventHandler;
[QGVAR(spawnRecon), { _this call FUNC(recon) }] call CBA_fnc_addEventHandler;
[QGVAR(spawnCas), { _this call FUNC(cas) }] call CBA_fnc_addEventHandler;
[QGVAR(spawnStrike), { _this call FUNC(strike) }] call CBA_fnc_addEventHandler;
[QGVAR(spawnIntercept), { _this call FUNC(intercept) }] call CBA_fnc_addEventHandler;
[QGVAR(spawnCasOrStrike), { _this call FUNC(selectCasOrStrike) }] call CBA_fnc_addEventHandler;

ADDON = true;
