#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Validate and submit a typed commander action request.

    Parameters:
        0: Commander module <OBJECT>
        1: Request <HASHMAP>

    Return Value:
        [Accepted <BOOL>, Normalized request <HASHMAP>, Reason <STRING>] <ARRAY>
*/

params [
    ["_commander", objNull, [objNull]],
    ["_request", createHashMap, [createHashMap]]
];

if (isNull _commander) exitWith {[false, createHashMap, "no_commander"]};
if !(_request isEqualType createHashMap) exitWith {[false, createHashMap, "bad_request_type"]};

private _targetObjectiveName = _request getOrDefault ["targetObjectiveName", ""];
private _actionType = _request getOrDefault ["actionType", ""];
if (_targetObjectiveName isEqualTo "" || {_actionType isEqualTo ""}) exitWith {
    [false, createHashMap, "missing_required_fields"]
};

private _slotsMax = (_commander getVariable [QGVAR(maxConcurrentActions), 3]) max 1;
private _waveLimit = ((_commander getVariable [QGVAR(maxWave), 3]) max 1) min 3;
private _actionId = _request getOrDefault ["actionId", format ["%1|%2", _targetObjectiveName, _actionType]];
private _priority = _request getOrDefault ["priority", 0];
private _desiredGroups = _request getOrDefault ["desiredGroups", _waveLimit];
private _waveSize = _request getOrDefault ["waveSize", _waveLimit];

_desiredGroups = (_desiredGroups max 1) min _waveLimit;
_waveSize = (_waveSize max 1) min _waveLimit;

private _normalized = createHashMapFromArray [
    ["actionId", _actionId],
    ["actionType", _actionType],
    ["targetObjectiveName", _targetObjectiveName],
    ["priority", _priority],
    ["desiredGroups", _desiredGroups],
    ["waveSize", _waveSize],
    ["slotsMax", _slotsMax],
    ["issuedAt", _request getOrDefault ["issuedAt", if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time}]],
    ["source", _request getOrDefault ["source", "internal_assess"]]
];

[true, _normalized, "ok"]

