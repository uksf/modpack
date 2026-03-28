#include "script_component.hpp"

/*
    Author:
        Codex

    Description:
        Registers an air strike spawn module with typed runtime values.
*/

(_this select 1) params ["_module"];
if (!isServer || {isNull _module}) exitWith {};

private _fnc_toNumber = {
    params ["_value", "_default"];
    if (_value isEqualType 0) exitWith {_value};
    if (_value isEqualType "") exitWith {parseNumber _value};
    _default
};

private _aircraftRaw = _module getVariable [QGVAR(aircraftTypes), "[]"];
private _aircraftTypes = [_aircraftRaw] call EFUNC(common,convertToArray);
_aircraftTypes = (_aircraftTypes select {_x isEqualType "" && {_x isNotEqualTo ""}}) arrayIntersect _aircraftTypes;

private _cooldownSec = [(_module getVariable [QGVAR(cooldownSec), 300]), 300] call _fnc_toNumber;
private _bombChance = [(_module getVariable [QGVAR(bombChance), 0.25]), 0.25] call _fnc_toNumber;
private _spawnAltitudeM = [(_module getVariable [QGVAR(spawnAltitudeM), 600]), 600] call _fnc_toNumber;
private _sideNumber = [(_module getVariable [QGVAR(sideNumber), -1]), -1] call _fnc_toNumber;
private _side = [_sideNumber] call FUNC(getSideFromIndex);

_module setVariable [QGVAR(isAirStrikeSpawn), true];
_module setVariable [QGVAR(aircraftTypes), _aircraftTypes, true];
_module setVariable [QGVAR(cooldownSec), (_cooldownSec max 0), true];
_module setVariable [QGVAR(bombChance), (_bombChance max 0) min 1, true];
_module setVariable [QGVAR(spawnAltitudeM), (_spawnAltitudeM max 50), true];
_module setVariable [QGVAR(sideNumber), _sideNumber, true];
_module setVariable [QGVAR(side), _side, true];
_module setVariable [QGVAR(lastStrikeAt), -1, true];

GVAR(airStrikeSpawns) pushBackUnique _module;
