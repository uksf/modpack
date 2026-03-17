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
        0: Event hashmap <HASHMAP> — must contain targetNetId, targetClassname,
           targetType, uid, damage, weapon, hitPoint, distance2D, distance3D

    Return Value:
        None

    Example:
        [_event] call uksf_statistics_fnc_handleDamageRelay
*/
params ["_event"];

private _targetNetId = _event get "targetNetId";
private _instigatorUid = _event get "uid";
private _damageDelta = _event get "damage";

if (isNil "_targetNetId" || {_targetNetId == "" || {_targetNetId == "0:0"}}) exitWith {};
if (isNil "_instigatorUid" || {_instigatorUid == ""}) exitWith {};
if (isNil "_damageDelta" || {_damageDelta <= 0}) exitWith {};

private _entry = createHashMapFromArray [
    ["uid", _instigatorUid],
    ["damage", _damageDelta],
    ["weapon", _event getOrDefault ["weapon", ""]],
    ["hitPoint", _event getOrDefault ["hitPoint", ""]],
    ["distance2D", _event getOrDefault ["distance2D", 0]],
    ["distance3D", _event getOrDefault ["distance3D", 0]],
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
