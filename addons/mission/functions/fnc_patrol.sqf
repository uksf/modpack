#include "script_component.hpp"
/*
    Author:
        Nicholas Clark (SENSEI), Tim Beswick

    Description:
        Runs patrol handling. Spawns groups of units and vehicles from a unit pool

    Parameters:
        None

    Return value:
        Nothing
*/
#define TIMEOUT 35

if (!GVAR(patrolEnabled)) exitWith {};

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

if (count GVAR(patrolGroups) <= ceil GVAR(patrolGroupLimit)) then {
    private _players = call CBA_fnc_players select {
        private _player = _x;
        (EGVAR(common,respawnPositions) findIf {
            (getMarkerPos _x) distance2D _player <= GVAR(patrolSafeZoneDistance)
        }) == -1 &&
        {GVAR(patrolBlacklistAreas) findIf {
            private _area = _x getVariable ["objectarea", []];
            _area params ["_a", "_b", "_angle", "_isRectangle"];
            _player inArea [_x, _a, _b, _angle, _isRectangle]
        } == -1} &&
        {!((vehicle _player) isKindOf "Air")}
    };
    if (_players isEqualTo []) exitWith {};

    private _player = selectRandom _players;
    private _positionArray = [getPosATL _player, 100, GVAR(patrolDistance) * 1.25, GVAR(patrolDistance) * 0.75, 10] call EFUNC(common,getSafePositionGrid);
    if (_positionArray isEqualTo []) exitWith {};

    private _position = selectRandom _positionArray;
    _players = [getPosATL _player, 100] call EFUNC(common,getNearPlayers);

    if ([_position, 100] call EFUNC(common,getNearPlayers) isEqualTo [] && {{([objNull, "VIEW", objNull] checkVisibility [[_position#0, _position#1, (_position#2) + 1.5], eyePos _x]) > 0} count _players isEqualTo 0}) then {
        _position = ASLtoAGL _position;

        if (GVAR(patrolVehicleProbability) > random 1) then {
            [_position, 1, 1, GVAR(patrolSide), {
                params ["_player", "_position", "_group"];

                GVAR(patrolGroups) pushBack _group;

                private _waypointPosition = _player getPos [200, random 360];
                if (surfaceIsWater _waypointPosition) then {
                    _waypointPosition = getPos _player;
                };

                private _waypoint = _group addWaypoint [_waypointPosition, 0];
                _waypoint setWaypointCompletionRadius 200;
                _waypoint setWaypointBehaviour "SAFE";
                _waypoint setWaypointFormation "STAG COLUMN";
                _waypoint setWaypointSpeed "NORMAL";
                _waypoint setWaypointStatements [
                    "!(behaviour this isEqualTo ""COMBAT"")",
                    format ["[this, this, %1, 5, ""MOVE"", ""SAFE"", ""YELLOW"", ""NORMAL"", ""STAG COLUMN"", """", [5, 10, 15]] call CBA_fnc_taskPatrol;", GVAR(patrolDistance)]
                ];

                INFO_1("Spawned vehicle patrol at %1",_position);
            }, [_player, _position]] call FUNC(spawnPatrolGroup);
        } else {
            private _count = round (random [GVAR(patrolMinUnits), round (GVAR(patrolMaxUnits) / 1.5) max GVAR(patrolMinUnits), GVAR(patrolMaxUnits) + 1]);
            [_position, 0, _count, GVAR(patrolSide), {
                params ["_player", "_position", "_count", "_group"];

                GVAR(patrolGroups) pushBack _group;

                private _waypointPosition = _player getPos [100, random 360];
                if (surfaceIsWater _waypointPosition) then {
                    _waypointPosition = getPos _player;
                };

                private _waypoint = _group addWaypoint [_waypointPosition, 0];
                _waypoint setWaypointCompletionRadius 100;
                _waypoint setWaypointBehaviour GVAR(patrolCombatMode);
                _waypoint setWaypointFormation "STAG COLUMN";
                _waypoint setWaypointSpeed GVAR(patrolSpeed);
                _waypoint setWaypointStatements [
                    "!(behaviour this isEqualTo ""COMBAT"")",
                    format ["[this, this, %1, 5, ""MOVE"", ""%2"", ""YELLOW"", ""%3"", ""STAG COLUMN"", """", [0, 0, 0]] call CBA_fnc_taskPatrol;", GVAR(patrolDistance), GVAR(patrolCombatMode), GVAR(patrolSpeed)]
                ];

                INFO_1("Spawned infantry patrol at %1",_position);
            }, [_player, _position, _count]] call FUNC(spawnPatrolGroup);
        };
    };
};
