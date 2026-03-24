#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Single server PFH that coordinates all air threat scheduling.
        Caches player lists once per tick, then checks three subsystems:
        CAP/recon timer, intercept zone monitoring, CAS/strike zone monitoring.
        Dispatches missions to HC via headlessEvent.
        Also performs stale mission cleanup as a safety net.
        Server only — started in XEH_postInit.

    Parameters:
        None (reads from global state)

    Return Value:
        Nothing

    Example:
        Called as a PFH, not directly
*/

if !(isServer) exitWith {
    [_thisHandle] call CBA_fnc_removePerFrameHandler;
};

if !(GVAR(controllerInitialised)) exitWith {};

// Cache player lists once per tick
private _players = ALL_PLAYERS;
private _airPlayers = _players select {
    vehicle _x isKindOf "Air" && {!isNull objectParent _x} && {alive _x}
};

// --- CAP/Recon scheduling ---
if (GVAR(capReconEnabled)) then {
    // Initialise on first run
    if (isNil QGVAR(nextCapReconTime)) then {
        GVAR(nextCapReconTime) = time + GVAR(initialDelay) + random GVAR(initialDelayOffset);
        INFO_1("CAP/recon loop started — first mission at %1",GVAR(nextCapReconTime));
    };

    if (time >= GVAR(nextCapReconTime)) then {
        if (call FUNC(canSpawnMission)) then {
            if (random 1 < 0.5) then {
                [QGVAR(spawnCap), []] call EFUNC(common,headlessEvent);
            } else {
                [QGVAR(spawnRecon), []] call EFUNC(common,headlessEvent);
            };
            // Full interval before next mission
            GVAR(nextCapReconTime) = time + GVAR(capReconBaseTime) + random GVAR(capReconOffsetTime);
        } else {
            // Can't spawn (at max missions) — retry after 60s, not every tick
            GVAR(nextCapReconTime) = time + 60;
        };
    };
};

// --- Intercept zone monitoring ---
if (GVAR(interceptEnabled) && {time >= GVAR(nextInterceptTime)} && {!(_airPlayers isEqualTo [])}) then {
    private _validTargets = [];

    {
        _x params ["_marker", "_maxIntercepts"];

        private _activeIntercepts = {
            (_x select 2) isEqualTo "intercept"
        } count GVAR(activeMissions);

        if (_activeIntercepts >= _maxIntercepts) then { continue };

        {
            if ((getPosATL _x) inArea _marker) then {
                _validTargets pushBackUnique _x;
            };
        } forEach _airPlayers;
    } forEach GVAR(interceptZones);

    if (!(_validTargets isEqualTo []) && {call FUNC(canSpawnMission)}) then {
        private _target = selectRandom _validTargets;
        [QGVAR(spawnIntercept), [_target]] call EFUNC(common,headlessEvent);
        GVAR(nextInterceptTime) = time + GVAR(interceptCooldown) + random GVAR(interceptCooldownOffset);
    };
};

// --- CAS/Strike zone monitoring ---
if (GVAR(casStrikeEnabled)) then {
    {
        _x params ["_marker", "_casProbability", "_lastTriggered"];

        if (time - _lastTriggered < 300) then { continue };

        private _groundPlayersInZone = _players select {
            alive _x
            && {(getPosATL _x) inArea _marker}
            && {vehicle _x == _x || {!(vehicle _x isKindOf "Air")}}
        };

        if (_groundPlayersInZone isEqualTo []) then { continue };

        if (call FUNC(canSpawnMission)) then {
            [QGVAR(spawnCasOrStrike), [_casProbability]] call EFUNC(common,headlessEvent);
            _x set [2, time];
        };
    } forEach GVAR(casStrikeZones);
};

// --- Stale mission cleanup (safety net) ---
private _staleMissions = GVAR(activeMissions) select {
    private _vehicle = _x select 1;
    !isNull _vehicle
    && {(_vehicle getVariable [QGVAR(spawnTime), time]) + 1800 < time}
};

{
    _x params ["_group", "_vehicle"];
    WARNING_1("Cleaning up stale mission: %1",_vehicle getVariable [ARR_2(QGVAR(missionType),"unknown")]);
    [QGVAR(missionComplete), [_group, _vehicle]] call CBA_fnc_serverEvent;
} forEach _staleMissions;
