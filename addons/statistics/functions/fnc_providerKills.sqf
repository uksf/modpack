#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Kills provider setup. Installs an EntityKilled mission event handler on the server
        to capture every entity death. Reads the damage ledger to identify all players
        who contributed damage (assists) and emits a single kill event with attribution.

        When no player is directly attributed as killer (e.g. chain reaction explosions,
        cookoff), searches the damage ledger for nearby entities that were recently
        damaged by a player and attributes the kill indirectly.

        Weapon and distance data is NOT included here — the API correlates kills with
        hit events from the client's projectile tracking for accurate weapon/distance.

    Parameters:
        None

    Return Value:
        None

    Example:
        call uksf_statistics_fnc_providerKills
*/
addMissionEventHandler ["EntityKilled", {
    params ["_victim", "_killer", "_instigator"];
    private _startTime = diag_tickTime;

    // Use instigator if available (e.g. gunner in vehicle), fall back to killer
    private _attacker = if (!isNull _instigator) then {_instigator} else {_killer};

    // Determine target type
    private _targetType = "unknown";
    if (_victim isKindOf "CAManBase") then {
        _targetType = "infantry";
    } else {
        if (_victim isKindOf "LandVehicle" || {_victim isKindOf "Air"} || {_victim isKindOf "Ship"}) then {
            _targetType = "vehicle";
        } else {
            if (_victim isKindOf "StaticWeapon") then {
                _targetType = "static";
            };
        };
    };

    // Look up damage ledger for this target
    private _targetNetId = netId _victim;
    private _damageHistory = GVAR(damageLedger) getOrDefault [_targetNetId, []];

    private _killerUid = if (isPlayer _attacker) then {getPlayerUID _attacker} else {""};
    private _indirect = false;

    // Chain reaction attribution: if no player instigator, search for a nearby
    // entity in the ledger that was recently damaged by a player (within 15m and 60s).
    // Handles cookoff, ammo detonation, and explosion chain kills.
    if (_killerUid isEqualTo "") then {
        private _victimPosition = getPosATL _victim;
        private _currentTime = CBA_missionTime;
        private _bestUid = "";
        private _bestTime = 0;

        {
            private _nearbyNetId = _x;
            private _nearbyObject = objectFromNetId _nearbyNetId;
            if (!isNull _nearbyObject && {_nearbyObject distance _victimPosition <= 15}) then {
                private _nearbyHistory = _y;
                {
                    private _entryTime = _x get "time";
                    if (_currentTime - _entryTime <= 60 && {_entryTime > _bestTime}) then {
                        _bestUid = _x get "uid";
                        _bestTime = _entryTime;
                    };
                } forEach _nearbyHistory;
            };
        } forEach GVAR(damageLedger);

        if (_bestUid isNotEqualTo "") then {
            _killerUid = _bestUid;
            _indirect = true;
        };
    };

    // Build assists: aggregate damage per player UID, excluding the killer
    private _assistMap = createHashMap;
    {
        private _uid = _x get "uid";
        if (_uid isNotEqualTo _killerUid && {_uid isNotEqualTo ""}) then {
            private _existing = _assistMap getOrDefault [_uid, 0];
            _assistMap set [_uid, _existing + (_x get "damage")];
        };
    } forEach _damageHistory;

    // Convert assist map to array sorted by highest damage first
    private _assists = [];
    {
        _assists pushBack [_y, _x];
    } forEach _assistMap;
    _assists sort false;
    _assists = _assists apply {
        createHashMapFromArray [
            ["uid", _x#1],
            ["totalDamage", _x#0]
        ]
    };

    // Clean up ledger
    GVAR(damageLedger) deleteAt _targetNetId;
    GVAR(damageLedgerMeta) deleteAt _targetNetId;

    // Only emit event if a player was involved (as killer or assist)
    if (_killerUid isEqualTo "" && {_assists isEqualTo []}) exitWith {
        ["kills", _startTime] call FUNC(addProviderTiming);
    };

    private _event = createHashMapFromArray [
        ["type", "kill"],
        ["killerUid", _killerUid],
        ["indirect", _indirect],
        ["targetClassname", typeOf _victim],
        ["targetSide", str ([west, east, resistance, civilian] select (getNumber (configOf _victim >> "side")))],
        ["targetType", _targetType],
        ["assists", _assists]
    ];

    GVAR(serverBuffer) pushBack _event;

    ["kills", _startTime] call FUNC(addProviderTiming);
}];
