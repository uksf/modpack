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

_waypointsArray deleteAt 0; // work around for AI going backwards to their start point, may need to handle better

{
    [_group, _x#2, 0, _x#4, _x#0, _x#5, _x#3, _x#1] call cba_fnc_addWaypoint;
} forEach _waypointsArray;


