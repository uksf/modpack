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

if ((!GVAR(dynamicPatrolEnabled) && !GVAR(dynamicPatrolAreasEnabled)) || {_retries > MAX_RETRIES}) exitWith {
    TRACE_3("5) Dynamic spawn failed enabled or retries check",GVAR(dynamicPatrolEnabled),GVAR(dynamicPatrolAreasEnabled),_retries);
    TRACE_2("5) ...",!GVAR(dynamicPatrolEnabled) && !GVAR(dynamicPatrolAreasEnabled),_retries > MAX_RETRIES);
};

TRACE_1("5) Dynamic spawn data",_this);

// Player can't be in an air vehicle
// AND IF area logic does not exist THEN Player can't be in range of respawn positions
// AND Player can't be in excluded areas
// AND IF area logic is given THEN Player must be in area
// AND IF area logic does not exist and include areas exist THEN Player must be in an include area

private _allPlayers = call CBA_fnc_players;
private _players = _allPlayers select {
    private _player = _x;
    !((vehicle _player) isKindOf "Air")
    && {isNull _logic || {[EGVAR(common,respawnPositions), {(getMarkerPos _x) distance2D _player <= GVAR(dynamicPatrolSafeZoneDistance)}] call EFUNC(common,arrayNone)}}
    && {[GVAR(dynamicPatrolExcludeAreas), {[_player, _x#0, _x#1] call EFUNC(common,objectInArea)}] call EFUNC(common,arrayNone)}
    && {isNull _logic || {[_player, _logic, _area] call EFUNC(common,objectInArea)}}
    && {!(isNull _logic) || {GVAR(dynamicPatrolIncludeAreas) isEqualTo [] || {[GVAR(dynamicPatrolIncludeAreas), {[_player, _x#0, _x#1] call EFUNC(common,objectInArea)}] call EFUNC(common,arrayAny)}}}
};
TRACE_1("5) Dynamic spawn resolved players",_players);
if (_players isEqualTo []) exitWith {
    INFO("5) Dynamic spawn failed players check");
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
};

private _useVehicle = [_vehicleProbability > random 1, false] select (_vehiclePool isEqualTo []);
private _spawnDistance = _distance;
if (_useVehicle) then {
    _spawnDistance = _distance * _vehicleDistanceCoef;
};
TRACE_4("5) Dynamic spawn distance",_vehicleProbability,_vehiclePool,_useVehicle,_spawnDistance);

if !([_values, _logic, _area, _players] call _condition) exitWith {
    DEBUG("Condition not satisfied");
};

private _positionArray = [getPosATL _player, _spawnDistance / 15, _spawnDistance * 1.25, _spawnDistance * 0.75, 10] call EFUNC(common,getSafePositionGrid);
TRACE_1("5) Dynamic spawn resolved positions",_positionArray);
_positionArray = _positionArray select {([_x, _spawnDistance * 0.7] call EFUNC(common,getNearPlayers)) isEqualTo []};
TRACE_1("5) Dynamic spawn resolved positions outside range of all players",_positionArray);
if (_positionArray isEqualTo []) exitWith {
    // Retry
    INFO("5) Dynamic spawn failed to find positions");
    [{call FUNC(dynamicPatrolSpawn)}, [_values, _logic, _area, _retries + 1], 5 + random 5] call CBA_fnc_waitAndExecute;
};

private _position = selectRandom _positionArray;
_players = [getPosATL _player, 100] call EFUNC(common,getNearPlayers);
TRACE_2("5) Dynamic spawn position and players near player",_position,_players);

private _playersNearToPosition = [_position, 100] call EFUNC(common,getNearPlayers);
private _playersWithPositionVisibility = {([objNull, "VIEW", objNull] checkVisibility [[_position#0, _position#1, (_position#2) + 1.5], eyePos _x]) > 0} count _players;
if (_playersNearToPosition isEqualTo [] && {_playersWithPositionVisibility isEqualTo 0}) then {
    _position = ASLtoAGL _position;

    if (_useVehicle) then {
        TRACE_1("5) Dynamic spawn use vehicle",_useVehicle);
        private _road = [_position] call EFUNC(common,findNearRoad);
        if (!isNull _road) then {
            _position = getPosATL _road;
        };
        TRACE_2("5) Dynamic spawn found road",_road,_position);

        [_position, 1, 1, _side, _unitPool, _vehiclePool, {-1}, {
            params ["_logic", "_player", "_position", "_spawnDistance", "_vehicleWaypointDistance", "_group"];
            TRACE_1("7) Dynamic spawn vehicle callback data",_this);

            GVAR(dynamicPatrolGroups) pushBack _group;
            publicVariable QGVAR(dynamicPatrolGroups);
            if !(isNull _logic) then {
                private _areaGroups = _logic getVariable [QGVAR(groups), []];
                _areaGroups pushBack _group;
                _logic setVariable [QGVAR(groups), _areaGroups, true];
            };
            TRACE_2("7) Dynamic spawn vehicle callback groups",GVAR(dynamicPatrolGroups),_logic getVariable [QGVAR(groups), []]);

            private _waypointPosition = _player getPos [_vehicleWaypointDistance, random 360];
            if (surfaceIsWater _waypointPosition) then {
                _waypointPosition = getPos _player;
            };
            TRACE_1("7) Dynamic spawn vehicle waypoint position",_waypointPosition);

            private _waypoint = [_group, _waypointPosition, 0, "MOVE", "SAFE", "YELLOW", "NORMAL", "STAG COLUMN", "", [0,0,0], 100] call CBA_fnc_addWaypoint;
            _waypoint setWaypointStatements [
                "(behaviour this) isNotEqualTo ""COMBAT""",
                format ["[this, this, %1, 5, ""MOVE"", ""SAFE"", ""YELLOW"", ""NORMAL"", ""STAG COLUMN"", """", [5, 10, 15]] call CBA_fnc_taskPatrol;", _spawnDistance]
            ];

            INFO_1("Spawned vehicle patrol at %1",_position);
        }, [_logic, _player, _position, _spawnDistance, _vehicleWaypointDistance]] call EFUNC(common,spawnGroup);
    } else {
        INFO("5) Dynamic spawn use infantry");
        private _count = round (random [_minUnits, round (_maxUnits / 1.5) max _minUnits, _maxUnits + 1]);
        TRACE_1("5) Dynamic spawn unit count",_count);

        [_position, 0, _count, _side, _unitPool, _vehiclePool, {-1}, {
            params ["_logic", "_player", "_position", "_count", "_spawnDistance", "_waypointDistance", "_combatMode", "_patrolSpeed", "_group"];
            TRACE_1("7) Dynamic spawn unit callback data",_this);

            GVAR(dynamicPatrolGroups) pushBack _group;
            publicVariable QGVAR(dynamicPatrolGroups);
            if !(isNull _logic) then {
                private _areaGroups = _logic getVariable [QGVAR(groups), []];
                _areaGroups pushBack _group;
                _logic setVariable [QGVAR(groups), _areaGroups, true];
            };
            TRACE_2("7) Dynamic spawn unit callback groups",GVAR(dynamicPatrolGroups),_logic getVariable [QGVAR(groups), []]);

            private _waypointPosition = _player getPos [_waypointDistance, random 360];
            if (surfaceIsWater _waypointPosition) then {
                _waypointPosition = getPos _player;
            };
            TRACE_1("7) Dynamic spawn unit waypoint position",_waypointPosition);

            private _waypoint = [_group, _waypointPosition, 0, "MOVE", _combatMode, "YELLOW", _patrolSpeed, "STAG COLUMN", "", [0,0,0], 50] call CBA_fnc_addWaypoint;
            _waypoint setWaypointStatements [
                "(behaviour this) isNotEqualTo ""COMBAT""",
                format ["[this, this, %1, 5, ""MOVE"", ""%2"", ""YELLOW"", ""%3"", ""STAG COLUMN"", """", [0, 0, 0]] call CBA_fnc_taskPatrol;", _spawnDistance, _combatMode, _patrolSpeed]
            ];

            INFO_1("Spawned infantry patrol at %1",_position);
        }, [_logic, _player, _position, _count, _spawnDistance, _waypointDistance, _combatMode, _patrolSpeed]] call EFUNC(common,spawnGroup);
    };
} else {
    TRACE_2("5) Dynamic spawn failed proximity or visibility check",_playersNearToPosition,_playersWithPositionVisibility);
};
