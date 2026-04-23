#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Initialises a vehicle patrol spawn module and starts its server PFH.

    Parameters:
        0: Arguments <ARRAY>
        1: Module logic <OBJECT>

    Return Value:
        Nothing

    Example:
        [_this, _logic] call uksf_vehiclepatrols_fnc_modulePatrolSpawn
*/

(_this select 1) params ["_logic"];

if !(local _logic) exitWith {};
if !(isServer) exitWith {};
if (_logic getVariable [QGVAR(initialised), false]) exitWith {};

private _unitClasses = [_logic getVariable [QGVAR(patrolUnitClasses), "[]"]] call EFUNC(common,convertToArray);
private _vehicleClasses = [_logic getVariable [QGVAR(patrolVehicleClasses), "[]"]] call EFUNC(common,convertToArray);
private _spawnRate = (_logic getVariable [QGVAR(spawnRate), 120]) max 1;
private _spawnOffset = (_logic getVariable [QGVAR(spawnOffset), 30]) max 0;
private _conditionString = _logic getVariable [QGVAR(condition), "true"];
private _turnAround = (_logic getVariable [QGVAR(turnAround), 0]) isEqualTo 1;
private _fillPercentage = ((_logic getVariable [QGVAR(fillPercentage), 100]) max 0) min 100;
private _waypointBehaviour = ["SAFE", "AWARE", "COMBAT"]#((_logic getVariable [QGVAR(waypointBehaviour), 0]) max 0 min 2);
private _waypointSpeed = ["LIMITED", "NORMAL", "FULL"]#((_logic getVariable [QGVAR(waypointSpeed), 1]) max 0 min 2);
private _startDelay = (_logic getVariable [QGVAR(startDelay), 0]) max 0;
private _vehiclesPerWave = (_logic getVariable [QGVAR(vehiclesPerWave), 1]) max 1;
private _waveSpawnDelay = (_logic getVariable [QGVAR(waveSpawnDelay), 7]) max 0;
private _side = [east, independent, west]#((_logic getVariable [QGVAR(side), 0]) max 0 min 2);

if (_vehicleClasses isEqualTo []) exitWith {
    WARNING("Vehicle patrol spawn module has no vehicle classes configured");
};

private _destinationModules = synchronizedObjects _logic select {_x isKindOf QGVAR(modulePatrolDestination)};
if (_destinationModules isEqualTo []) exitWith {
    WARNING("Vehicle patrol spawn module has no synced destination modules");
};

private _condition = compile _conditionString;
private _conditionResult = [_logic] call _condition;
if !(_conditionResult isEqualType true) then {
    WARNING("Vehicle patrol spawn module condition is invalid. Defaulting to true");
    _condition = {true};
};

_logic setVariable [QGVAR(initialised), true, true];

[{
    params ["_args", "_idPFH"];
    _args params ["_logic", "_unitClasses", "_vehicleClasses", "_spawnRate", "_spawnOffset", "_condition", "_turnAround", "_fillPercentage", "_waypointBehaviour", "_waypointSpeed", "_vehiclesPerWave", "_waveSpawnDelay", "_side", "_nextSpawnTime", "_destinationModules"];

    if !(alive _logic) exitWith {
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };

    if (CBA_missionTime < _nextSpawnTime) exitWith {};

    _args set [13, CBA_missionTime + _spawnRate + random _spawnOffset];

    if !([_logic] call _condition) exitWith {};

    _destinationModules = _destinationModules select {!isNull _x};
    if (_destinationModules isEqualTo []) exitWith {};

    private _spawnPosition = getPosASL _logic;

    for "_waveIndex" from 0 to (_vehiclesPerWave - 1) do {
        [{
            params ["_spawnPosition", "_destinationModules", "_unitClasses", "_vehicleClasses", "_side", "_fillPercentage", "_waypointBehaviour", "_waypointSpeed", "_turnAround"];

            _destinationModules = _destinationModules select {!isNull _x};
            if (_destinationModules isEqualTo []) exitWith {};

            private _destinationModule = selectRandom _destinationModules;
            private _destinationPosition = getPosASL _destinationModule;

            [QGVAR(spawnPatrol), [_spawnPosition, _destinationPosition, _unitClasses, _vehicleClasses, _side, _fillPercentage, _waypointBehaviour, _waypointSpeed, _turnAround]] call EFUNC(common,headlessEvent);
        }, [_spawnPosition, _destinationModules, _unitClasses, _vehicleClasses, _side, _fillPercentage, _waypointBehaviour, _waypointSpeed, _turnAround], _waveIndex * _waveSpawnDelay] call CBA_fnc_waitAndExecute;
    };
}, 1, [_logic, _unitClasses, _vehicleClasses, _spawnRate, _spawnOffset, _condition, _turnAround, _fillPercentage, _waypointBehaviour, _waypointSpeed, _vehiclesPerWave, _waveSpawnDelay, _side, CBA_missionTime + _startDelay, _destinationModules]] call CBA_fnc_addPerFrameHandler;
