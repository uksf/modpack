/*
    Author:
        CBA, Tim Beswick

    Description:
        Task a group to randomly patrol a parsed radius and location.
        Same as https://github.com/CBATeam/CBA_A3/blob/master/addons/ai/fnc_taskPatrol.sqf but delete waypoints does not remove index 0 waypoint.

    Parameters:
        https://github.com/CBATeam/CBA_A3/blob/master/addons/ai/fnc_taskPatrol.sqf#L7
*/
#include "script_component.hpp"

params [
    ["_group", grpNull, [grpNull, objNull]],
    ["_position", [], [[], objNull, grpNull, locationNull], [2, 3]],
    ["_radius", 100, [0]],
    ["_count", 3, [0]]
];

_group = _group call CBA_fnc_getGroup;
if !(local _group) exitWith {};

_position = [_position,_group] select (_position isEqualTo []);
_position = _position call CBA_fnc_getPos;

{deleteWaypoint [_group, 1]; false} count (waypoints _group);

_this =+ _this;
_this set [2, 0];
if (count _this > 3) then {
    _this deleteAt 3;
};

private _step = 360 / _count;
private _offset = random _step;
for "_i" from 1 to _count do {
    private _rad = _radius * random [0.1, 0.75, 1];
    private _theta = (_i % 2) * 180 + sin (deg (_step * _i)) * _offset + _step * _i;

    _this set [1, _position getPos [_rad, _theta]];
    call CBA_fnc_addWaypoint;
};

_this set [1, _position];
_this set [2, _radius];
_this set [3, "CYCLE"];
call CBA_fnc_addWaypoint;
