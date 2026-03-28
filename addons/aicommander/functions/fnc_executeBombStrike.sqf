#include "script_component.hpp"

/*
    Author:
        Codex

    Description:
        Executes a bomb strike near target position.
*/

params [
    ["_commander", objNull, [objNull]],
    ["_vehicle", objNull, [objNull]],
    ["_targetPosition", [], [[]]],
    ["_bombClass", "Bomb_04_F", [""]]
];

if (isNull _commander || {isNull _vehicle}) exitWith {};
if !(_targetPosition isEqualType [] && {count _targetPosition >= 2}) exitWith {};

private _commanderSide = _commander getVariable [QGVAR(side), sideUnknown];
private _friendlies = (_targetPosition nearEntities ["CAManBase", 80]) select {
    alive _x && {side _x isEqualTo _commanderSide}
};

if (_friendlies isNotEqualTo []) exitWith {
    [format ["AIC AIR: bomb run aborted (friendly risk) at %1", mapGridPosition _targetPosition]] remoteExec ["systemChat", 0];
    ["AIR_STRIKE", _commander, createHashMapFromArray [
        ["actionId", "air_strike"],
        ["reason", "aborted_friendly_risk"],
        ["message", format ["bomb aborted, friendly count=%1", count _friendlies]]
    ]] call FUNC(logExecution);
};

[{
    params ["_center", "_class"];
    private _impact = _center getPos [random 20, random 360];
    _impact set [2, 0];
    createVehicle [_class, _impact, [], 0, "NONE"];
}, [_targetPosition, _bombClass], 0.15] call CBA_fnc_waitAndExecute;

[format ["AIC AIR: bomb spawned at %1 class=%2", mapGridPosition _targetPosition, _bombClass]] remoteExec ["systemChat", 0];

["AIR_STRIKE", _commander, createHashMapFromArray [
    ["actionId", "air_strike"],
    ["reason", "bomb_executed"],
    ["message", format ["veh=%1 bombClass=%2", typeOf _vehicle, _bombClass]]
]] call FUNC(logExecution);
