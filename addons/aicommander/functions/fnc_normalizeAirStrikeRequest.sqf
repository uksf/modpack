#include "script_component.hpp"

/*
    Author:
        Codex

    Description:
        Normalizes and validates air strike requests.
*/

params [
    ["_commander", objNull, [objNull]],
    ["_request", createHashMap, [createHashMap]]
];

if (isNull _commander) exitWith {[false, createHashMap, "no_commander"]};
if !(_request isEqualType createHashMap) exitWith {[false, createHashMap, "bad_request_type"]};

private _targetPosition = _request getOrDefault ["targetPosition", []];
private _targetUnit = _request getOrDefault ["targetUnit", objNull];
if (!isNull _targetUnit) then {
    _targetPosition = getPosATL _targetUnit;
};
if !(_targetPosition isEqualType [] && {count _targetPosition >= 2}) exitWith {[false, createHashMap, "missing_target_position"]};

_targetPosition = +_targetPosition;
if ((count _targetPosition) < 3) then {
    _targetPosition pushBack 0;
};

private _bigBombChanceOverride = _request getOrDefault ["bigBombChanceOverride", -1];
if (_bigBombChanceOverride isEqualTo -1) then {
    _bigBombChanceOverride = _request getOrDefault ["bombChanceOverride", -1];
};
if (_bigBombChanceOverride isEqualTo -1) then {
    _bigBombChanceOverride = _request getOrDefault ["bombChance", -1];
};
if (!(_bigBombChanceOverride isEqualType 0)) then {
    _bigBombChanceOverride = -1;
};
if (_bigBombChanceOverride >= 0) then {
    _bigBombChanceOverride = (_bigBombChanceOverride max 0) min 1;
};

private _issuedAt = if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time};
private _source = _request getOrDefault ["source", "internal"];
private _requestedAircraftType = _request getOrDefault ["requestedAircraftType", ""];

private _normalized = createHashMapFromArray [
    ["type", "air_strike"],
    ["actionId", _request getOrDefault ["actionId", format ["AIRSTRIKE|%1", round _issuedAt]]],
    ["targetPosition", _targetPosition],
    ["bigBombChanceOverride", _bigBombChanceOverride],
    ["requestedAircraftType", _requestedAircraftType],
    ["source", _source],
    ["issuedAt", _issuedAt]
];

[true, _normalized, "ok"]
