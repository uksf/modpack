#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Runs SEAD mission

    Parameters:
        0: Group <GROUP>

    Return value:
        Nothing
*/
params ["_group"];

private _seadPos = getPos (selectRandom GVAR(enemyAirfields));
[_group, _seadPos, 500, "SAD", "AWARE"] call CBA_fnc_addWaypoint;
(vehicle (leader _group)) flyInHeight 500;

[_group, getPos (selectRandom GVAR(planeSpawns)), 1, "MOVE", "AWARE", "YELLOW", "NORMAL", "", QUOTE([this] call FUNC(handleDelete))] call CBA_fnc_addWaypoint;

