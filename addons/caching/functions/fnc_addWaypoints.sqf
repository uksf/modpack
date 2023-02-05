#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
       Adds waypoints to the group
       [[wpB, wpF, wpP, wpS, wpT, wpCM], [wpB, wpF, wpP, wpS, wpT, wpCM]]

    Parameters:
        0: group <OBJECT>
        1: waypointsArray <ARRAY>

    Return value:
        Nothing
*/

params ["_group", "_waypointsArray"];
{
    _x params ["_behaviour", "_formation", "_pos", "_speed", "_type", "_combatMode"];
    [_group, _pos, 0, _type, _behaviour, _combatMode, _speed, _formation] call cba_fnc_addWaypoint;
} forEach _waypointsArray;


