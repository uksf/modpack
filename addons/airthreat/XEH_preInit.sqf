#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// Killswitches — set via debug console to disable mission types at runtime
// e.g. uksf_airthreat_capReconEnabled = false;
GVAR(capReconEnabled) = true;
GVAR(interceptEnabled) = true;
GVAR(casStrikeEnabled) = true;

// Configuration — populated by controller module
GVAR(capReconMinTime) = 1200;
GVAR(capReconMaxTime) = 1800;
GVAR(initialDelayMin) = 1800;
GVAR(initialDelayMax) = 2700;
GVAR(interceptCooldownMin) = 600;
GVAR(interceptCooldownMax) = 1200;
GVAR(casStrikeCooldownMin) = 300;
GVAR(casStrikeCooldownMax) = 600;
GVAR(maxConcurrentMissions) = 3;
GVAR(fighterClassnames) = [];
GVAR(helicopterClassnames) = [];
GVAR(jetClassnames) = [];
GVAR(reconClassnames) = [];
GVAR(excludedClasses) = [];
GVAR(exclusionZones) = [];
GVAR(capTimeout) = 900;
GVAR(reconTimeout) = 600;
GVAR(casTimeout) = 600;
GVAR(strikeTimeout) = 600;
GVAR(interceptTimeout) = 600;

// State — server only
GVAR(activeMissions) = [];
GVAR(spawnPoints) = [];
GVAR(airspaces) = [];
GVAR(casStrikeZones) = [];
GVAR(interceptZones) = [];
GVAR(controllerInitialised) = false;

// Intercept state
GVAR(nextInterceptTime) = 0;

// Debug provider static data (used by draw closures — must be GVAR, not private, due to SQF dynamic scoping)
GVAR(debugColourMap) = createHashMapFromArray [
    ["cap", [0.4, 0.7, 1, 0.9]],
    ["recon", [1, 1, 0.3, 0.9]],
    ["cas", [1, 0.5, 0, 0.9]],
    ["strike", [1, 0.2, 0.2, 0.9]],
    ["intercept", [1, 0.3, 1, 0.9]]
];
GVAR(debugHexColourMap) = createHashMapFromArray [
    ["cap", "#66b3ff"],
    ["recon", "#ffff4d"],
    ["cas", "#ff8000"],
    ["strike", "#ff3333"],
    ["intercept", "#ff4dff"]
];
GVAR(debugTimeoutMap) = createHashMapFromArray [
    ["cap", QGVAR(capTimeout)],
    ["recon", QGVAR(reconTimeout)],
    ["cas", QGVAR(casTimeout)],
    ["strike", QGVAR(strikeTimeout)],
    ["intercept", QGVAR(interceptTimeout)]
];
GVAR(debugFormatTime) = {
    params ["_seconds"];
    private _minutes = floor (_seconds / 60);
    private _secs = floor (_seconds mod 60);
    if (_secs < 10) then {
        format ["%1:0%2", _minutes, _secs]
    } else {
        format ["%1:%2", _minutes, _secs]
    };
};

// Server events — mission tracking
[QGVAR(missionComplete), {
    params ["_group", "_vehicle"];
    [_group, _vehicle] call FUNC(unregisterMission);
}] call CBA_fnc_addEventHandler;

// Server events — mission spawn handlers
[QGVAR(spawnCap), { _this call FUNC(cap) }] call CBA_fnc_addEventHandler;
[QGVAR(spawnRecon), { _this call FUNC(recon) }] call CBA_fnc_addEventHandler;
[QGVAR(spawnCas), { _this call FUNC(cas) }] call CBA_fnc_addEventHandler;
[QGVAR(spawnStrike), { _this call FUNC(strike) }] call CBA_fnc_addEventHandler;
[QGVAR(spawnIntercept), { _this call FUNC(intercept) }] call CBA_fnc_addEventHandler;
[QGVAR(spawnCasOrStrike), { _this call FUNC(selectCasOrStrike) }] call CBA_fnc_addEventHandler;
[QGVAR(reconFollowUp), { _this call FUNC(reconFollowUp) }] call CBA_fnc_addEventHandler;

ADDON = true;
