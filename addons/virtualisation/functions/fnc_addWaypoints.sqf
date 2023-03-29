#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
       Adds waypoints to the group

    Parameters:
        0: Group <GROUP>
        1: Waypoints info <ARRAY>

    Return value:
        Nothing
*/
params ["_group", "_waypointsArray"];

{
    _x params ["_position", "_type", "_behaviour", "_combatMode", "_speed", "_formation"];
    [_group, _position, 0, _type, _behaviour, _combatMode, _speed, _formation] call CBA_fnc_addWaypoint;
} forEach _waypointsArray;
