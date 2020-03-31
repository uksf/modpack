#include "script_component.hpp"
/*
    Author:
        Nicholas Clark (SENSEI), Tim Beswick

    Description:
        Runs patrol handling. Spawns groups of units and vehicles from a unit pool

    Parameters:
        0: Retries (Optional) <SCALAR>

    Return value:
        Nothing
*/
#define TIMEOUT 35
#define MAX_RETRIES 4

params [["_retries", 0]];

if (!GVAR(patrolEnabled) || {_retries > MAX_RETRIES}) exitWith {};

private _groupsToDelete = GVAR(patrolGroups) select {
    isNull _x ||
    {!([getPosATL (leader _x), GVAR(patrolDistance) * 2] call EFUNC(common,anyNearPlayers)) &&
    !(behaviour (leader _x) isEqualTo "COMBAT")}
};

{
    GVAR(patrolGroups) deleteAt (GVAR(patrolGroups) find _x);
    ((leader _x) getVariable [QGVAR(assignedVehicle), objNull]) call CBA_fnc_deleteEntity;
    _x call CBA_fnc_deleteEntity;
} forEach _groupsToDelete;

// Player can't be in range of respawn positions
// AND Player can't be in an air vehicle
// AND (
    // Player can't be in blacklisted locations
    // AND IF whitelisted locations exist Player must be in whitelisted locations
// )
if (count GVAR(patrolGroups) <= ceil GVAR(patrolGroupLimit)) then {
    private _players = call CBA_fnc_players select {
        private _player = _x;
        (EGVAR(common,respawnPositions) findIf {
            (getMarkerPos _x) distance2D _player <= GVAR(patrolSafeZoneDistance)
        }) == -1 &&
        {!((vehicle _player) isKindOf "Air")} && {
            GVAR(patrolBlacklistAreas) findIf {
                private _area = _x getVariable ["objectarea", []];
                _area params ["_a", "_b", "_angle", "_isRectangle"];
                _player inArea [_x, _a, _b, _angle, _isRectangle]
            } == -1
        } && {
            GVAR(patrolWhitelistAreas) isEqualTo [] || {
                GVAR(patrolWhitelistAreas) findIf {
                    private _area = _x getVariable ["objectarea", []];
                    _area params ["_a", "_b", "_angle", "_isRectangle"];
                    _player inArea [_x, _a, _b, _angle, _isRectangle]
                } != -1
            }
        }
    };
    if (_players isEqualTo []) exitWith {};

    private _useVehicle = GVAR(patrolVehicleProbability) > random 1;
    private _spawnDistance = GVAR(patrolDistance);
    if (_useVehicle) then {
        _spawnDistance = GVAR(patrolDistance) * GVAR(patrolVehicleDistanceCoef);
    };

    private _player = selectRandom _players;
    private _positionArray = [getPosATL _player, 100, _spawnDistance * 1.25, _spawnDistance * 0.75, 10] call EFUNC(common,getSafePositionGrid);
    if (_positionArray isEqualTo []) exitWith {
        // Retry
        [{call FUNC(patrol)}, [_retries + 1], GVAR(patrolCooldown) / 4] call CBA_fnc_waitAndExecute;
    };

    private _position = selectRandom _positionArray;
    _players = [getPosATL _player, 100] call EFUNC(common,getNearPlayers);

    if ([_position, 100] call EFUNC(common,getNearPlayers) isEqualTo [] && {{([objNull, "VIEW", objNull] checkVisibility [[_position#0, _position#1, (_position#2) + 1.5], eyePos _x]) > 0} count _players isEqualTo 0}) then {
        _position = ASLtoAGL _position;

        if (_useVehicle) then {
            private _road = [_position] call EFUNC(common,findNearRoad);
            if (!isNull _road) then {
                _position = getPosATL _road;
            };

            [_position, 1, 1, GVAR(patrolSide), {
                params ["_player", "_position", "_spawnDistance", "_group"];

                GVAR(patrolGroups) pushBack _group;

                private _waypointPosition = _player getPos [200, random 360];
                if (surfaceIsWater _waypointPosition) then {
                    _waypointPosition = getPos _player;
                };

                private _waypoint = [_group, _waypointPosition, 0, "MOVE", "SAFE", "YELLOW", "NORMAL", "STAG COLUMN", "", [0,0,0], 100] call CBA_fnc_addWaypoint;
                _waypoint setWaypointStatements [
                    "!(behaviour this isEqualTo ""COMBAT"")",
                    format ["[this, this, %1, 5, ""MOVE"", ""SAFE"", ""YELLOW"", ""NORMAL"", ""STAG COLUMN"", """", [5, 10, 15]] call CBA_fnc_taskPatrol;", _spawnDistance]
                ];

                INFO_1("Spawned vehicle patrol at %1",_position);
            }, [_player, _position, _spawnDistance]] call FUNC(spawnPatrolGroup);
        } else {
            private _count = round (random [GVAR(patrolMinUnits), round (GVAR(patrolMaxUnits) / 1.5) max GVAR(patrolMinUnits), GVAR(patrolMaxUnits) + 1]);
            [_position, 0, _count, GVAR(patrolSide), {
                params ["_player", "_position", "_count", "_spawnDistance", "_group"];

                GVAR(patrolGroups) pushBack _group;

                private _waypointPosition = _player getPos [100, random 360];
                if (surfaceIsWater _waypointPosition) then {
                    _waypointPosition = getPos _player;
                };

                private _waypoint = [_group, _waypointPosition, 0, "MOVE", GVAR(patrolCombatMode), "YELLOW", GVAR(patrolSpeed), "STAG COLUMN", "", [0,0,0], 50] call CBA_fnc_addWaypoint;
                _waypoint setWaypointStatements [
                    "!(behaviour this isEqualTo ""COMBAT"")",
                    format ["[this, this, %1, 5, ""MOVE"", ""%2"", ""YELLOW"", ""%3"", ""STAG COLUMN"", """", [0, 0, 0]] call CBA_fnc_taskPatrol;", _spawnDistance, GVAR(patrolCombatMode), GVAR(patrolSpeed)]
                ];

                INFO_1("Spawned infantry patrol at %1",_position);
            }, [_player, _position, _count, _spawnDistance]] call FUNC(spawnPatrolGroup);
        };
    };
};
