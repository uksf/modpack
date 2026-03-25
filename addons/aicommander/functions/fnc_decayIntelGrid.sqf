#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Age commander intel grid and decay stale enemy cells to unknown.

    Parameters:
        0: Commander module <OBJECT>

    Return Value:
        None
*/

params [["_commander", objNull, [objNull]]];

if (isNull _commander) exitWith {};

private _intelGrid = _commander getVariable [QGVAR(intelGrid), createHashMap];
if !(_intelGrid isEqualType createHashMap) exitWith {};

private _now = if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time};
private _ttl = (_commander getVariable [QGVAR(intelStaleTtlSec), 600]) max 60;
private _decayed = 0;

{
    private _cell = _intelGrid getOrDefault [_x, createHashMap];
    if !(_cell isEqualType createHashMap) then {continue};

    private _state = _cell getOrDefault ["state", "unknown"];
    private _lastSeenAt = _cell getOrDefault ["lastSeenAt", -1];

    if (_state isEqualTo "enemy_present" && {_lastSeenAt >= 0} && {(_now - _lastSeenAt) > _ttl}) then {
        _cell set ["state", "unknown"];
        _cell set ["lastUpdatedAt", _now];
        _intelGrid set [_x, _cell];
        _decayed = _decayed + 1;
    };
} forEach keys _intelGrid;

if (_decayed > 0) then {
    ["INTEL_DECAY", _commander, createHashMapFromArray [
        ["reason", "stale_to_unknown"],
        ["message", format ["cells=%1 ttl=%2", _decayed, _ttl]]
    ]] call FUNC(logExecution);
};

_commander setVariable [QGVAR(intelGrid), _intelGrid];
