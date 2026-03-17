#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Processes a combat damage event into the damage ledger.
        Called by handleClientReport when it encounters a "combatDamage" event.
        Records damage attribution keyed by target netId for later correlation
        with EntityKilled events.

        Computes 2D and 3D distances on the server using the launch position map
        (updated from shot events) and the target position from the damage event.

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

// Compute distances using server-side launch position map
private _targetPosition = _event getOrDefault ["targetPosition", []];
private _launchPosition = GVAR(launchPositions) getOrDefault [_instigatorUid, []];
private _distance2D = 0;
private _distance3D = 0;
if (_launchPosition isNotEqualTo [] && {_targetPosition isNotEqualTo []}) then {
    _distance2D = round (_launchPosition distance2D _targetPosition);
    _distance3D = round (_launchPosition vectorDistance _targetPosition);
};

private _entry = createHashMapFromArray [
    ["uid", _instigatorUid],
    ["damage", _damageDelta],
    ["weapon", _event getOrDefault ["weapon", ""]],
    ["hitPoint", _event getOrDefault ["hitPoint", ""]],
    ["distance2D", _distance2D],
    ["distance3D", _distance3D],
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
