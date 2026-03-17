#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Kills provider setup. Installs an EntityKilled mission event handler on the server
        to capture every entity death. Reads the damage ledger to identify all players
        who contributed damage (assists) and emits a single kill event with full attribution.

        Registered after ACE medical's handleKilledMission so killer/instigator info
        is corrected by ACE before we read it.

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

    // Determine victim type
    private _victimType = "unknown";
    if (_victim isKindOf "CAManBase") then {
        _victimType = "infantry";
    } else {
        if (_victim isKindOf "LandVehicle" || {_victim isKindOf "Air"} || {_victim isKindOf "Ship"}) then {
            _victimType = "vehicle";
        } else {
            if (_victim isKindOf "StaticWeapon") then {
                _victimType = "static";
            };
        };
    };

    // Look up damage ledger for this target
    private _targetNetId = netId _victim;
    private _damageHistory = GVAR(damageLedger) getOrDefault [_targetNetId, []];

    // Build assists: aggregate damage per player UID, excluding the killer
    private _killerUid = if (isPlayer _attacker) then {getPlayerUID _attacker} else {""};
    private _assistMap = createHashMap;
    {
        private _uid = _x get "uid";
        if (_uid != _killerUid && {_uid != ""}) then {
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
    if (_killerUid == "" && {count _assists == 0}) exitWith {
        ["kills", _startTime] call FUNC(addProviderTiming);
    };

    private _distance = if (isNull _attacker) then {0} else {_attacker distance _victim};
    private _weapon = if (isPlayer _attacker) then {currentWeapon _attacker} else {""};

    private _event = createHashMapFromArray [
        ["type", "kill"],
        ["killerUid", _killerUid],
        ["weapon", _weapon],
        ["targetClassname", typeOf _victim],
        ["targetSide", str (side group _victim)],
        ["targetType", _victimType],
        ["distance", round _distance],
        ["assists", _assists]
    ];

    GVAR(serverBuffer) pushBack _event;

    ["kills", _startTime] call FUNC(addProviderTiming);
}];
