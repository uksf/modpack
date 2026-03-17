#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Processes a combat damage event into the damage ledger.
        Called by handleClientReport when it encounters a "combatDamage" event.
        Records damage attribution keyed by target netId for later correlation
        with EntityKilled events.

    Parameters:
        0: Event hashmap <HASHMAP>

    Return Value:
        None

    Example:
        [_event] call uksf_statistics_fnc_handleDamageRelay
*/
params ["_event"];

private _targetNetId = _event get "targetNetId";
private _instigatorUid = _event get "uid";
private _damageDelta = _event get "damage";

if (isNil "_targetNetId" || {_targetNetId isEqualTo "" || {_targetNetId isEqualTo "0:0"}}) exitWith {};
if (isNil "_instigatorUid" || {_instigatorUid isEqualTo ""}) exitWith {};
if (isNil "_damageDelta" || {_damageDelta <= 0}) exitWith {};

private _entry = createHashMapFromArray [
    ["uid", _instigatorUid],
    ["damage", _damageDelta],
    ["time", CBA_missionTime]
];

private _ledgerEntry = GVAR(damageLedger) getOrDefault [_targetNetId, []];
_ledgerEntry pushBack _entry;
GVAR(damageLedger) set [_targetNetId, _ledgerEntry];

// Store target metadata for kill event enrichment
GVAR(damageLedgerMeta) set [_targetNetId, createHashMapFromArray [
    ["classname", _event getOrDefault ["targetClassname", ""]],
    ["targetType", _event getOrDefault ["targetType", ""]]
]];
