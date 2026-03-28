#include "script_component.hpp"

/*
    Author:
        Codex

    Description:
        Processes a normalized air strike request and spawns strike aircraft.
*/

params [
    ["_commander", objNull, [objNull]],
    ["_request", createHashMap, [createHashMap]],
    ["_forceIgnoreCooldown", false, [false]]
];

if (!isServer) exitWith {
    [QGVAR(staffRequest), [_commander, _request, _forceIgnoreCooldown]] call CBA_fnc_serverEvent;
    [false, createHashMap, "forwarded_to_server"]
};

private _normalizedResult = [_commander, _request] call FUNC(normalizeAirStrikeRequest);
_normalizedResult params ["_okNormalized", "_normalized", "_normalizeReason"];
if (!_okNormalized) exitWith {[false, _normalized, _normalizeReason]};

private _spawnSelection = [_commander, _forceIgnoreCooldown] call FUNC(selectAirStrikeSpawn);
_spawnSelection params ["_spawnModule", "_spawnReason"];
if (isNull _spawnModule) exitWith {[false, _normalized, _spawnReason]};

_normalized set ["moduleBigBombChance", _spawnModule getVariable [QGVAR(bombChance), 0.25]];

private _spawnResult = [_commander, _spawnModule, _normalized] call FUNC(spawnAirStrikeAircraft);
_spawnResult params ["_okSpawn", "_spawnExecReason", "_vehicle"];
if (!_okSpawn) exitWith {[false, _normalized, _spawnExecReason]};

private _now = if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time};
_spawnModule setVariable [QGVAR(lastStrikeAt), _now, true];
_commander setVariable [QGVAR(nextAirStrikeAt), _now + ((_commander getVariable [QGVAR(globalAirStrikeCooldownSec), 30]) max 0)];

["AIR_STRIKE", _commander, createHashMapFromArray [
    ["actionId", _normalized getOrDefault ["actionId", "air_strike"]],
    ["reason", "accepted"],
    ["message", format ["veh=%1 module=%2 src=%3", typeOf _vehicle, str _spawnModule, _normalized getOrDefault ["source", "internal"]]]
]] call FUNC(logExecution);

[true, _normalized, "accepted"]
