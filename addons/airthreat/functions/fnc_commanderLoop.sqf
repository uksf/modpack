#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Single server PFH that coordinates all air threat scheduling.
        Caches player lists once per tick, then checks three subsystems:
        CAP/recon timer, intercept zone monitoring, CAS/strike zone monitoring.
        Dispatches missions via local event (server only).
        Also performs stale mission cleanup as a safety net.
        Server only — started in XEH_postInit.

    Parameters:
        None (reads from global state)

    Return Value:
        Nothing

    Example:
        Called as a PFH, not directly
*/

params ["", "_idPFH"];

if !(isServer) exitWith {
    [_idPFH] call CBA_fnc_removePerFrameHandler;
};

if !(GVAR(controllerInitialised)) exitWith {};

// Cache player lists once per tick
private _players = ALL_PLAYERS;
private _airPlayers = _players select {
    alive _x && {vehicle _x isKindOf "Air"}
};

// --- CAP/Recon scheduling ---
if (GVAR(capReconEnabled)) then {
    // Initialise on first run
    if (isNil QGVAR(nextCapReconTime)) then {
        GVAR(nextCapReconTime) = time + GVAR(initialDelayMin) + random (GVAR(initialDelayMax) - GVAR(initialDelayMin));
        TRACE_1("CAP/recon loop started — first mission at %1",GVAR(nextCapReconTime));
    };

    if (time >= GVAR(nextCapReconTime)) then {
        if (call FUNC(canSpawnMission)) then {
            if (random 1 < 0.5) then {
                [QGVAR(spawnCap), []] call CBA_fnc_localEvent;
            } else {
                [QGVAR(spawnRecon), []] call CBA_fnc_localEvent;
            };
            // Full interval before next mission
            GVAR(nextCapReconTime) = time + GVAR(capReconMinTime) + random (GVAR(capReconMaxTime) - GVAR(capReconMinTime));
        } else {
            // Can't spawn (at max missions) — retry after 60s, not every tick
            GVAR(nextCapReconTime) = time + 60;
        };
    };
};

// --- Intercept zone monitoring (two-phase) ---

// Phase 1: commit pending intercept if scramble elapsed
if (GVAR(pendingIntercept) isNotEqualTo []) then {
    GVAR(pendingIntercept) params ["_pendingTarget", "_pendingZoneIndex", "_commitTime"];
    if (time >= _commitTime) then {
        private _valid = alive _pendingTarget
            && {vehicle _pendingTarget isKindOf "Air"}
            && {call FUNC(canSpawnMission)};
        if (_valid) then {
            [QGVAR(spawnIntercept), [_pendingTarget, _pendingZoneIndex]] call CBA_fnc_localEvent;
            TRACE_2("Intercept committed after scramble",_pendingTarget,_pendingZoneIndex);
        } else {
            TRACE_1("Intercept pending dropped at commit (target lost or max missions)",_pendingTarget);
        };
        GVAR(pendingIntercept) = [];
    };
};

// Phase 2: detect new trigger (only if no pending and cooldown expired)
if (
    GVAR(interceptEnabled)
    && {GVAR(pendingIntercept) isEqualTo []}
    && {time >= GVAR(nextInterceptTime)}
    && {_airPlayers isNotEqualTo []}
) then {
    private _validTargets = [];

    {
        _x params ["_zoneArea", "_maxIntercepts"];
        private _zoneIndex = _forEachIndex;

        private _activeIntercepts = {
            (_x select 2) isEqualTo "intercept" && {(_x select 3) isEqualTo _zoneIndex}
        } count GVAR(activeMissions);

        if (_activeIntercepts >= _maxIntercepts) then { continue };

        {
            if ((getPosATL _x) inArea _zoneArea) then {
                _validTargets pushBackUnique [_x, _zoneIndex];
            };
        } forEach _airPlayers;
    } forEach GVAR(interceptZones);

    if (_validTargets isNotEqualTo [] && {call FUNC(canSpawnMission)}) then {
        private _selected = selectRandom _validTargets;
        _selected params ["_target", "_zoneIndex"];
        private _scrambleDelay = INTERCEPT_SCRAMBLE_DELAY * (0.75 + random 0.5);
        GVAR(pendingIntercept) = [_target, _zoneIndex, time + _scrambleDelay];
        GVAR(nextInterceptTime) = time + GVAR(interceptCooldownMin) + random (GVAR(interceptCooldownMax) - GVAR(interceptCooldownMin));
        TRACE_3("Intercept scramble triggered",_target,_zoneIndex,_scrambleDelay);
    };
};

// --- CAS/Strike zone monitoring ---
if (GVAR(casStrikeEnabled) && {call FUNC(canSpawnMission)}) then {
    {
        _x params ["_zoneArea", "_casProbability", "_nextTriggerTime"];

        if (time < _nextTriggerTime) then { continue };

        private _groundPlayersInZone = _players select {
            alive _x
            && {(getPosATL _x) inArea _zoneArea}
            && {!(vehicle _x isKindOf "Air")}
        };

        if (_groundPlayersInZone isEqualTo []) then { continue };

        [QGVAR(spawnCasOrStrike), [_casProbability]] call CBA_fnc_localEvent;
        _x set [2, time + GVAR(casStrikeCooldownMin) + random (GVAR(casStrikeCooldownMax) - GVAR(casStrikeCooldownMin))];
    } forEach GVAR(casStrikeZones);
};

// --- Stale mission cleanup (safety net) ---
// Threshold: longest configured timeout + 10 minute buffer
private _staleThreshold = (GVAR(capTimeout) max GVAR(reconTimeout) max GVAR(casTimeout) max GVAR(strikeTimeout) max GVAR(interceptTimeout)) + 600;
private _staleMissions = GVAR(activeMissions) select {
    private _vehicle = _x select 1;
    !isNull _vehicle
    && {(_vehicle getVariable [QGVAR(spawnTime), time]) + _staleThreshold < time}
};

{
    _x params ["_group", "_vehicle"];
    WARNING_1("Cleaning up stale mission: %1",_vehicle getVariable [ARR_2(QGVAR(missionType),"unknown")]);
    [QGVAR(missionComplete), [_group, _vehicle]] call CBA_fnc_localEvent;
    [_group, _vehicle] call FUNC(cleanupAircraft);
} forEach _staleMissions;
