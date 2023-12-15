#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs dynamic patrol spawning

    Parameters:
        0: Values <ARRAY>
        1: Logic (Optional) <OBJECT>
        2: Area (Optional) <ARRAY>

    Return value:
        Nothing
*/
#define MAX_RETRIES 4

params ["_values", ["_logic", objNull], ["_area", []], ["_retries", 0]];
_values params ["", "_distance", "", "_minUnits", "_maxUnits", "", "", "_vehicleProbability", "_vehicleDistanceCoef", "_waypointDistance", "_vehicleWaypointDistance", "_unitPool", "_vehiclePool", "_combatMode", "_patrolSpeed", "_side", "", "_condition"];

private _id = _logic getVariable [QEGVAR(common,id), ""];
private _debugData = GVAR(dynamicPatrolDebugMap) getOrDefault [_id, createHashMap];
private _iteration = GVAR(dynamicPatrolDebugMap) getOrDefault [format ["%1_iteration", _id], 0];
if (_retries == 0) then {
    _iteration = _iteration + 1;
};
private _iterationDebugData = _debugData getOrDefault [_iteration, createHashMap];

if ((!GVAR(dynamicPatrolEnabled) && !GVAR(dynamicPatrolAreasEnabled)) || {_retries > MAX_RETRIES}) exitWith {
    TRACE_3("5) Dynamic spawn failed enabled or retries check",GVAR(dynamicPatrolEnabled),GVAR(dynamicPatrolAreasEnabled),_retries);
    TRACE_2("5) ...",!GVAR(dynamicPatrolEnabled) && !GVAR(dynamicPatrolAreasEnabled),_retries > MAX_RETRIES);
    _iterationDebugData set ["exitCode", 1];
};

TRACE_1("5) Dynamic spawn data",_this);

private _getPlayersResult = call ([FUNC(dynamicPatrolAreaGetPlayers), FUNC(dynamicPatrolGetPlayers)] select (isNull _logic));
_getPlayersResult params ["_players", "_allPlayersAreValid"];

if (_players isEqualTo []) exitWith {
    INFO("5) Dynamic spawn failed players check");
    _iterationDebugData set ["exitCode", 1];
};

if !(_allPlayersAreValid) then {
    // If there are no valid players, allow unconscious/inconspicuous but increase distances
    TRACE_1("5) Dynamic spawn found only invalid players",_players);
    _distance = _distance * 1.5;
    _waypointDistance = _waypointDistance * 2.5;
    _vehicleWaypointDistance = _vehicleWaypointDistance * 2.5;
};

private _player = selectRandom _players;
private _spawnChance = 100;
private _random = random 100;
private _includeAreas = GVAR(dynamicPatrolIncludeAreas) select {[_player, _x#0, _x#1] call EFUNC(common,objectInArea)};
if (_includeAreas isNotEqualTo []) then {
    _spawnChance = (((_includeAreas#0)#2) min 100) max 0;
};
TRACE_4("5) Dynamic spawn chance values",_player,_spawnChance,_random,_includeAreas);

if (_random > _spawnChance) exitWith {
    TRACE_2("5) Dynamic spawn failed spawn chance check",_random,_spawnChance);
    _iterationDebugData set ["exitCode", 1];
};

private _useVehicle = [_vehicleProbability > random 1, false] select (_vehiclePool isEqualTo []);
private _spawnDistance = _distance;
if (_useVehicle) then {
    _spawnDistance = _distance * _vehicleDistanceCoef;
};
TRACE_4("5) Dynamic spawn distance",_vehicleProbability,_vehiclePool,_useVehicle,_spawnDistance);

if !([_values, _logic, _area, _players] call _condition) exitWith {
    DEBUG("Condition not satisfied");
    _iterationDebugData set ["exitCode", 1];
};

#ifdef DEBUG_MODE_ANALYSIS
{deleteMarker _x} forEach GVAR(dynamicPatrolDebugMarkers);
#endif

private _positionArray = [getPosATL _player, _spawnDistance / 15, _spawnDistance * 1.25, _spawnDistance * 0.75, 10] call EFUNC(common,getSafePositionGrid);
TRACE_1("5) Dynamic spawn resolved positions",_positionArray);
_positionArray = _positionArray select {([ASLtoAGL _x, _spawnDistance * 0.7] call FUNC(getNearPlayers)) isEqualTo []};

#ifdef DEBUG_MODE_ANALYSIS
{
    _marker = createMarker [str random 999999, _x]; _marker setMarkerShape "ICON"; _marker setMarkerType "hd_dot"; _marker setMarkerColor "ColorGreen";
    GVAR(dynamicPatrolDebugMarkers) pushBack _marker;
} forEach _positionArray;
#endif

TRACE_1("5) Dynamic spawn resolved positions outside range of all players",_positionArray);
if (_positionArray isEqualTo []) exitWith {
    // Retry
    INFO("5) Dynamic spawn failed to find positions");
    [{call FUNC(dynamicPatrolSpawn)}, [_values, _logic, _area, _retries + 1], DYNAMIC_PATROL_RETRY_DELAY + random DYNAMIC_PATROL_RETRY_DELAY] call CBA_fnc_waitAndExecute;
};

private _position = selectRandom _positionArray;

#ifdef DEBUG_MODE_ANALYSIS
_marker = createMarker [str random 999999, _position]; _marker setMarkerShape "ICON"; _marker setMarkerType "hd_objective"; _marker setMarkerColor "ColorWhite";
GVAR(dynamicPatrolDebugMarkers) pushBack _marker;
#endif

_players = [_player, 100] call FUNC(getNearPlayers);
TRACE_2("5) Dynamic spawn position and players near player",_position,_players);

private _playersNearToPosition = [ASLtoAGL _position, 100] call FUNC(getNearPlayers);
if (_playersNearToPosition isNotEqualTo []) exitWith {
    TRACE_1("5) Dynamic spawn failed proximity check",_playersNearToPosition);
    _iterationDebugData set ["exitCode", 1];
};

private _playersWithPositionVisibility = [call FUNC(getPlayers), {([objNull, "VIEW", objNull] checkVisibility [[_position#0, _position#1, (_position#2) + 1.5], eyePos _x]) > 0}] call EFUNC(common,arrayAny);
if (_playersWithPositionVisibility) exitWith {
    TRACE_1("5) Dynamic spawn failed visibility check",_playersWithPositionVisibility);
    _iterationDebugData set ["exitCode", 1];
};

#ifdef DEBUG_MODE_ANALYSIS
_iterationDebugData set ["exitCode", 0];
_iterationDebugData set ["positions", _positionArray];
_iterationDebugData set ["position", _position];
_iterationDebugData set ["players", _players apply {getPosASL _x}];
_iterationDebugData set ["player", _player];
_iterationDebugData set ["playersNearToPosition", _playersNearToPosition apply {getPosASL _x}];

_debugData set [_iteration, _iterationDebugData];
GVAR(dynamicPatrolDebugMap) set [_id, _debugData];
#else

_position = ASLtoAGL _position;

if (_useVehicle) then {
    TRACE_1("5) Dynamic spawn use vehicle",_useVehicle);
    private _road = [_position] call EFUNC(common,findNearRoad);
    if (!isNull _road) then {
        _position = getPosATL _road;
    };
    TRACE_2("5) Dynamic spawn found road",_road,_position);

    [_position, _side, _unitPool, _vehiclePool, {-1}, FUNC(dynamicPatrolCallbackVehicle), [_logic, _player, _position, _spawnDistance, _vehicleWaypointDistance]] call EFUNC(common,spawnGroupVehicle);
} else {
    INFO("5) Dynamic spawn use infantry");
    private _count = round (random [_minUnits, round (_maxUnits / 1.5) max _minUnits, _maxUnits + 1]);
    TRACE_1("5) Dynamic spawn unit count",_count);

    [_position, _count, _side, _unitPool, FUNC(dynamicPatrolCallbackInfantry), [_logic, _player, _position, _spawnDistance, _waypointDistance, _combatMode, _patrolSpeed]] call EFUNC(common,spawnGroupInfantry);
};
#endif
