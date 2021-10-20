#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Callback for a vehicle group spawned by dynamic patrol

    Parameters:
        0: Logic <OBJECT>
        1: Player <OBJECT>
        2: Spawn position <ARRAY>
        3: Spawn distance <SCALAR>
        4: Waypoint distance <SCALAR>
        5: Spawned group <GROUP>

    Return value:
        Nothing
*/
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
