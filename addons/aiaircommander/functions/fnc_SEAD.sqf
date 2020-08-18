#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Runs SEAD mission

    Parameters:
        0: _group <GROUP>
        
    Return value:
        Nothing
*/

params ["_group"];

private _seadPos = selectRandom GVAR(enemyAirfields);
private _wp = _group addWaypoint [getPos _seadPos,500];
_wp setWaypointType "SAD"; 
_wp setWaypointCombatMode "RED";
_group setCurrentWaypoint [_group, 1];
vehicle (leader _group) flyInHeight 500;

private _wp1 = _group addWaypoint [getPos (selectRandom GVAR(airSpawns)),0];
_wp1 setWaypointType "MOVE"; 
_wp1 setWaypointCombatMode "YELLOW";
_wp1 setWaypointStatements ["true", "[this] call uksf_airCommander_fnc_handleDelete;"];
