#include "script_component.hpp"

/*
    Author:
        Codex

    Description:
        Spawns aircraft in FLY mode and executes strike effect near target.
*/

params [
    ["_commander", objNull, [objNull]],
    ["_spawnModule", objNull, [objNull]],
    ["_request", createHashMap, [createHashMap]]
];

if (isNull _commander || {isNull _spawnModule}) exitWith {[false, "bad_inputs", objNull]};

private _aircraftTypes = _spawnModule getVariable [QGVAR(aircraftTypes), []];
if (_aircraftTypes isEqualTo []) exitWith {[false, "no_aircraft_types", objNull]};

private _requestedType = _request getOrDefault ["requestedAircraftType", ""];
private _aircraftType = if (_requestedType isEqualTo "" || {!(_requestedType in _aircraftTypes)}) then {
    selectRandom _aircraftTypes
} else {
    _requestedType
};

private _targetPosition = _request getOrDefault ["targetPosition", []];
if !(_targetPosition isEqualType [] && {count _targetPosition >= 2}) exitWith {[false, "missing_target_position", objNull]};

private _spawnPosition = getPosATL _spawnModule;
_spawnPosition set [2, (_spawnModule getVariable [QGVAR(spawnAltitudeM), 600]) max 50];

private _moduleSide = _spawnModule getVariable [QGVAR(side), sideUnknown];
private _commanderSide = _commander getVariable [QGVAR(side), sideUnknown];
private _spawnSide = [_moduleSide, _commanderSide] select (_moduleSide isEqualTo sideUnknown);
if (_spawnSide isEqualTo sideUnknown) then {
    _spawnSide = east;
};

private _spawnResult = [_spawnPosition, _spawnPosition getDir _targetPosition, _aircraftType, _spawnSide] call BIS_fnc_spawnVehicle;
_spawnResult params [["_vehicle", objNull, [objNull]], ["_crew", [], [[]]], ["_group", grpNull, [grpNull]]];
if (isNull _vehicle || {isNull _group} || {_crew isEqualTo []}) exitWith {[false, "vehicle_spawn_failed", objNull]};

_vehicle setPosATL _spawnPosition;
_vehicle setDir (_spawnPosition getDir _targetPosition);
_vehicle flyInHeight ((_spawnModule getVariable [QGVAR(spawnAltitudeM), 600]) max 50);
_vehicle engineOn true;
_vehicle setVelocityModelSpace [0, 120, 0];
_group setBehaviourStrong "CARELESS";
_group setCombatMode "BLUE";

{
    _x setSkill 0.8;
    _x disableAI "TARGET";
    _x disableAI "AUTOTARGET";
    _x disableAI "AUTOCOMBAT";
} forEach units _group;

private _waypoints = waypoints _group;
{
    deleteWaypoint _x;
} forEach _waypoints;

private _bigBombChance = _request getOrDefault ["bigBombChanceOverride", -1];
if (_bigBombChance < 0) then {
    _bigBombChance = _request getOrDefault ["moduleBigBombChance", 0.25];
};
_bigBombChance = (_bigBombChance max 0) min 1;
private _bombClass = ["Bo_Mk82", "Bomb_04_F"] select ((random 1) <= _bigBombChance);

_group setVariable [QGVAR(strikeCommander), _commander];
_group setVariable [QGVAR(strikeTargetPos), _targetPosition];
_group setVariable [QGVAR(strikeBombClass), _bombClass];

private _wpAttack = _group addWaypoint [_targetPosition, 0];
_wpAttack setWaypointType "MOVE";
_wpAttack setWaypointBehaviour "CARELESS";
_wpAttack setWaypointCombatMode "BLUE";
_wpAttack setWaypointSpeed "FULL";
_wpAttack setWaypointStatements [
    "true",
    format [
        "[format ['AIC AIR: target waypoint reached (%1)', typeOf (vehicle this)]] remoteExec ['systemChat', 0]; private _g = group this; private _cmd = _g getVariable ['%1', objNull]; private _tgt = _g getVariable ['%2', []]; private _bombClass = _g getVariable ['%3', 'Bomb_04_F']; [format ['AIC AIR: bombing in 1s at %1 class=%2', mapGridPosition _tgt, _bombClass]] remoteExec ['systemChat', 0]; [{[_this#0, _this#1, _this#2, _this#3] call %4;}, [_cmd, vehicle this, _tgt, _bombClass], 1] call CBA_fnc_waitAndExecute;",
        QGVAR(strikeCommander),
        QGVAR(strikeTargetPos),
        QGVAR(strikeBombClass),
        QFUNC(executeBombStrike)
    ]
];

private _wpRtb = _group addWaypoint [_spawnPosition, 0];
_wpRtb setWaypointType "MOVE";
_wpRtb setWaypointBehaviour "CARELESS";
_wpRtb setWaypointCombatMode "BLUE";
_wpRtb setWaypointSpeed "FULL";
_wpRtb setWaypointStatements [
    "true",
    "[format ['AIC AIR: RTB complete, despawning %1', typeOf (vehicle this)]] remoteExec ['systemChat', 0]; deleteVehicle (vehicle this); {deleteVehicle _x} forEach units (group this); deleteGroup (group this);"
];

[true, "spawned", _vehicle]
