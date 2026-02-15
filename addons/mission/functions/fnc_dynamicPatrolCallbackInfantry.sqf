#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Callback for an infantry group spawned by dynamic patrol

    Parameters:
        0: Logic <OBJECT>
        1: Player <OBJECT>
        2: Spawn position <ARRAY>
        3: Spawn distance <SCALAR>
        4: Waypoint distance <SCALAR>
        5: Combat mode <STRING>
        6: Patrol speed <STRING>
        7: Spawned group <GROUP>

    Return value:
        Nothing
*/
params ["_logic", "_player", "_position", "_spawnDistance", "_waypointDistance", "_combatMode", "_patrolSpeed", "_group"];
TRACE_1("7) Dynamic spawn unit callback data",_this);

GVAR(dynamicPatrolGroups) pushBack _group;
publicVariable QGVAR(dynamicPatrolGroups);
if !(isNull _logic) then {
    private _areaGroups = _logic getVariable [QGVAR(groups), []];
    _areaGroups pushBack _group;
    _logic setVariable [QGVAR(groups), _areaGroups, true];
};
TRACE_3("7) Dynamic spawn unit callback groups",GVAR(dynamicPatrolGroups),_logic getVariable [QGVAR(groups),[]]);

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
