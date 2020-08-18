#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Runs a Combat Air Patrol 

    Parameters:
        0: _group <GROUP>
        
    Return value:
        Nothing
*/

params ["_group"];

private _airspaceCentrePos = selectRandom GVAR(airspaceCentre);
private _wp = _group addWaypoint [getPos _airspaceCentrePos,750];
_wp setWaypointType "SAD"; 
_wp setWaypointCombatMode "RED";
_group setCurrentWaypoint [_group, 1];

private _airSpawn = getPos (selectRandom GVAR(airSpawns));
[_group,_airSpawn,50,"MOVE","AWARE","YELLOW","NORMAL","","[this] call uksf_airCommander_fnc_handleDelete;"] call cba_fnc_addWaypoint;

if (vehicle (leader _group) isKindOf "helicopter") then {
    vehicle (leader _group) flyInHeight 300;
} else {
    vehicle (leader _group) flyInHeight 500;
};