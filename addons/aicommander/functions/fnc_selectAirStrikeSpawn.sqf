#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Selects a valid air strike spawn module respecting cooldowns.
*/

params [
    ["_commander", objNull, [objNull]],
    ["_ignoreCooldown", false, [false]]
];

if (isNull _commander) exitWith {[objNull, "no_commander"]};

private _now = if (!isNil "CBA_missionTime") then {CBA_missionTime} else {time};
private _commanderSide = _commander getVariable [QGVAR(side), sideUnknown];
private _nextGlobal = _commander getVariable [QGVAR(nextAirStrikeAt), 0];
if (!_ignoreCooldown && {_now < _nextGlobal}) exitWith {[objNull, "global_cooldown"]};

private _candidates = synchronizedObjects _commander select {_x getVariable [QGVAR(isAirStrikeSpawn), false]};
if (_candidates isEqualTo []) then {
    _candidates = +GVAR(airStrikeSpawns);
};

_candidates = _candidates select {
    !isNull _x
    && {(_x getVariable [QGVAR(aircraftTypes), []]) isNotEqualTo []}
    && {
        private _moduleSide = _x getVariable [QGVAR(side), sideUnknown];
        _moduleSide isEqualTo sideUnknown || {_moduleSide isEqualTo _commanderSide}
    }
};
if (_candidates isEqualTo []) exitWith {[objNull, "no_airstrike_spawn_modules"]};

if (!_ignoreCooldown) then {
    _candidates = _candidates select {
        private _last = _x getVariable [QGVAR(lastStrikeAt), -1];
        private _cooldown = (_x getVariable [QGVAR(cooldownSec), 300]) max 0;
        _last < 0 || {_now >= (_last + _cooldown)}
    };
};

if (_candidates isEqualTo []) exitWith {[objNull, "module_cooldown"]};
[selectRandom _candidates, "ok"]
