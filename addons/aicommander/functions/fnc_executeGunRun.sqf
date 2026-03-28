#include "script_component.hpp"

/*
    Author:
        Codex

    Description:
        Executes a scripted gun run with impact bursts through the target area.
*/

params [
    ["_commander", objNull, [objNull]],
    ["_vehicle", objNull, [objNull]],
    ["_targetPosition", [], [[]]]
];

if (isNull _commander || {isNull _vehicle}) exitWith {};
if !(_targetPosition isEqualType [] && {count _targetPosition >= 2}) exitWith {};

private _commanderSide = _commander getVariable [QGVAR(side), sideUnknown];
private _friendlies = (_targetPosition nearEntities ["CAManBase", 80]) select {
    alive _x && {side _x isEqualTo _commanderSide}
};
if (_friendlies isNotEqualTo []) exitWith {
    [format ["AIC AIR: gun run aborted (friendly risk) at %1", mapGridPosition _targetPosition]] remoteExec ["systemChat", 0];
    ["AIR_STRIKE", _commander, createHashMapFromArray [
        ["actionId", "air_strike"],
        ["reason", "aborted_friendly_risk"],
        ["message", format ["gun run aborted, friendly count=%1", count _friendlies]]
    ]] call FUNC(logExecution);
};

private _runDirection = _vehicle getDir _targetPosition;
private _runLength = 180;
private _spacing = 20;
private _start = _targetPosition getPos [_runLength * 0.5, _runDirection + 180];
private _roundCount = 1 + floor (_runLength / _spacing);
private _impactAmmo = "";

{
    private _weaponCfg = configFile >> "CfgWeapons" >> _x;
    if (!isClass _weaponCfg) then {continue};

    {
        private _magCfg = configFile >> "CfgMagazines" >> _x;
        if (!isClass _magCfg) then {continue};

        private _ammoClass = getText (_magCfg >> "ammo");
        if (_ammoClass isEqualTo "") then {continue};

        private _ammoCfg = configFile >> "CfgAmmo" >> _ammoClass;
        if (!isClass _ammoCfg) then {continue};

        private _sim = toLower (getText (_ammoCfg >> "simulation"));
        private _explosive = getNumber (_ammoCfg >> "explosive");
        private _indirectHit = getNumber (_ammoCfg >> "indirectHit");
        private _isExplosive = _explosive > 0
            || {_indirectHit > 0}
            || {(_sim find "missile") >= 0}
            || {(_sim find "rocket") >= 0}
            || {(_sim find "bomb") >= 0}
            || {(_sim find "grenade") >= 0}
            || {(_sim find "submunition") >= 0};
        if (_isExplosive) then {continue};

        private _isDirectGunSim = (_sim find "bullet") >= 0 || {(_sim find "shell") >= 0};
        if (!_isDirectGunSim) then {continue};

        _impactAmmo = _ammoClass;
    } forEach getArray (_weaponCfg >> "magazines");

    if (_impactAmmo isNotEqualTo "") exitWith {};
} forEach weapons _vehicle;

if (_impactAmmo isEqualTo "") then {
    _impactAmmo = "B_127x108_Ball";
};

[format ["AIC AIR: gun run ammo %1", _impactAmmo]] remoteExec ["systemChat", 0];

for "_i" from 0 to (_roundCount - 1) do {
    [{
        params ["_startPos", "_index", "_spacingStep", "_direction", "_ammoClass"];
        private _impact = _startPos getPos [_index * _spacingStep, _direction];
        _impact = _impact getPos [random 12, random 360];
        _impact set [2, 0];
        createVehicle [_ammoClass, _impact, [], 0, "CAN_COLLIDE"];
    }, [_start, _i, _spacing, _runDirection, _impactAmmo], _i * 0.08] call CBA_fnc_waitAndExecute;
};

["AIR_STRIKE", _commander, createHashMapFromArray [
    ["actionId", "air_strike"],
    ["reason", "gun_run_executed"],
    ["message", format ["veh=%1 dir=%2 rounds=%3 ammo=%4", typeOf _vehicle, round _runDirection, _roundCount, _impactAmmo]]
]] call FUNC(logExecution);
