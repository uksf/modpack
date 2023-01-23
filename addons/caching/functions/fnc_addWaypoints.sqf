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
    [_group, _x#3, 0, _x#5, _x#1, _x#6, _x#4, _x#2] call cba_fnc_addWaypoint;
} forEach _waypointsArray;


