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

private _airspaceCentrePos = getPos (selectRandom GVAR(airspaceCentre));
[_group,_airspaceCentrePos,500,"SAD","AWARE"] call cba_fnc_addWaypoint;

private _airSpawn = getPos (selectRandom GVAR(planeSpawns));
[_group,_airSpawn,50,"MOVE","AWARE","YELLOW","NORMAL","","[this] call uksf_aiairCommander_fnc_handleDelete;"] call cba_fnc_addWaypoint;

if (vehicle (leader _group) isKindOf "helicopter") then {
    vehicle (leader _group) flyInHeight 300;
} else {
    vehicle (leader _group) flyInHeight 500;
};
