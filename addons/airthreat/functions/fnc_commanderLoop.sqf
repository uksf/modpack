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
// Killswitch flip aborts pending — admin disabling intercepts should stop everything.
if (GVAR(pendingIntercept) isNotEqualTo []) then {
    if !(GVAR(interceptEnabled)) then {
        TRACE_1("Intercept pending dropped — killswitch off",GVAR(pendingIntercept));
        GVAR(pendingIntercept) = [];
    } else {
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

// --- CAS/Strike zone monitoring (two-phase per zone) ---
{
    _x params ["_zoneArea", "_casProbability", "_nextTriggerTime", "_pendingType", "_pendingCommitTime"];

    // Killswitch flip aborts pending — admin disabling CAS/strike should stop everything.
    if (!GVAR(casStrikeEnabled) && {_pendingType isNotEqualTo ""}) then {
        TRACE_2("CAS/strike pending dropped — killswitch off",_pendingType,_forEachIndex);
        _x set [3, ""];
        _x set [4, 0];
        continue;
    };

    // Phase 1: commit pending spawn if scramble elapsed
    if (_pendingType isNotEqualTo "") then {
        if (time >= _pendingCommitTime) then {
            if (call FUNC(canSpawnMission)) then {
                private _eventName = if (_pendingType isEqualTo "cas") then {
                    QGVAR(spawnCas)
                } else {
                    QGVAR(spawnStrike)
                };
                [_eventName, []] call CBA_fnc_localEvent;
                TRACE_2("CAS/strike committed after scramble",_pendingType,_forEachIndex);
            } else {
                TRACE_1("CAS/strike pending dropped at commit (max missions)",_pendingType);
            };
            _x set [3, ""];
            _x set [4, 0];
        };
        continue;
    };

    // Phase 2: detect new trigger (only if no pending, enabled, cooldown expired, can spawn)
    if (!GVAR(casStrikeEnabled)) then { continue };
    if (time < _nextTriggerTime) then { continue };
    if !(call FUNC(canSpawnMission)) then { continue };

    private _groundPlayersInZone = _players select {
        alive _x
        && {(getPosATL _x) inArea _zoneArea}
        && {!(vehicle _x isKindOf "Air")}
    };

    if (_groundPlayersInZone isEqualTo []) then { continue };

    // Decide type + scramble delay at trigger
    private _isCas = random 100 < _casProbability;
    private _type = if (_isCas) then { "cas" } else { "strike" };
    private _scrambleBase = if (_isCas) then { CAS_SCRAMBLE_DELAY } else { STRIKE_SCRAMBLE_DELAY };
    private _scrambleDelay = _scrambleBase * (0.75 + random 0.5);

    _x set [3, _type];
    _x set [4, time + _scrambleDelay];
    _x set [2, time + GVAR(casStrikeCooldownMin) + random (GVAR(casStrikeCooldownMax) - GVAR(casStrikeCooldownMin))];
    TRACE_3("CAS/strike scramble triggered",_type,_forEachIndex,_scrambleDelay);
} forEach GVAR(casStrikeZones);

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

// --- Orphan aircraft cleanup ---
// Aircraft whose mission ended via handleMissionEnd while the airframe was
// still alive (pilot dead/ejected). Delete after the orphan timeout, or
// immediately if the wreck has appeared / vehicle is gone.
private _expiredOrphans = GVAR(orphanedAircraft) select {
    _x params ["", "_vehicle"];
    isNull _vehicle
    || {!alive _vehicle}
    || {(_vehicle getVariable [QGVAR(orphanedAt), time]) + GVAR(orphanTimeout) < time}
};
{
    _x params ["_group", "_vehicle"];
    if (!isNull _vehicle && {alive _vehicle}) then {
        deleteVehicleCrew _vehicle;
        deleteVehicle _vehicle;
    };
    if (!isNull _group) then { deleteGroup _group };
} forEach _expiredOrphans;
GVAR(orphanedAircraft) = GVAR(orphanedAircraft) - _expiredOrphans;
