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

private _seadPos = getPos (selectRandom GVAR(enemyAirfields));
[_group,_seadPos,500,"SAD","AWARE"] call cba_fnc_addWaypoint;
vehicle (leader _group) flyInHeight 500;

[_group,getPos (selectRandom GVAR(airSpawnLocations)),1,"MOVE","AWARE","YELLOW","NORMAL","","[this] call uksf_aiairCommander_fnc_handleDelete;"] call cba_fnc_addWaypoint;

