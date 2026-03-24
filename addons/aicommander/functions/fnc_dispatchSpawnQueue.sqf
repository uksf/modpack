#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Dispatch one queued spawn job for this commander when interval allows.

    Parameters:
        0: Commander module <OBJECT>

    Return Value:
        None
*/

params [["_commander", objNull, [objNull]]];

if (!isServer || {isNull _commander}) exitWith {};

private _now = if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time};
private _nextSpawnAt = _commander getVariable [QGVAR(nextSpawnAt), _now];
if (_now < _nextSpawnAt) exitWith {};

private _queue = _commander getVariable [QGVAR(spawnQueue), []];
if (_queue isEqualTo []) exitWith {};

private _managedGroups = [_commander] call FUNC(refreshManagedGroups);
private _managedCap = (_commander getVariable [QGVAR(managedGroupsCap), 9]) max 1;
if ((count _managedGroups) >= _managedCap) exitWith {
    _commander setVariable [QGVAR(nextSpawnAt), _now + 2];
};

private _job = _queue deleteAt 0;
if (_job isEqualType createHashMap && {_job isNotEqualTo createHashMap}) then {
    private _catalogEntry = [
        _commander,
        _job getOrDefault ["actionType", "reinforce"],
        _job getOrDefault ["actionId", ""]
    ] call FUNC(selectCatalogGroup);
    if (_catalogEntry isEqualTo createHashMap) then {
        ["SPAWN_SKIP", _commander, createHashMapFromArray [
            ["actionId", _job getOrDefault ["actionId", "none"]],
            ["reason", "no_catalog_entry"],
            ["message", "No validated catalog group available for action type"]
        ]] call FUNC(logExecution);
    } else {
        private _spawnResult = [_commander, _job, _catalogEntry] call FUNC(spawnGroupFromCatalog);
        _spawnResult params ["_ok", "_reason"];

        if (!_ok && {_reason in ["staging_pool_empty", "no_staging_objective"]}) then {
            private _attempts = (_job getOrDefault ["attempts", 0]) + 1;
            if (_attempts < 4) then {
                _job set ["attempts", _attempts];
                _queue pushBack _job;
            };
        };

        ["SPAWN", _commander, createHashMapFromArray [
            ["actionId", _job getOrDefault ["actionId", "none"]],
            ["reason", _reason],
            ["message", format ["queue=%1 managed=%2/%3", count _queue, count (_commander getVariable [QGVAR(managedGroups), []]), _managedCap]]
        ]] call FUNC(logExecution);
    };
};

_commander setVariable [QGVAR(spawnQueue), _queue];
_commander setVariable [QGVAR(nextSpawnAt), _now + 2];
