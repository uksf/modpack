#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Runs a Combat Air Patrol

    Parameters:
        0: Group <GROUP>

    Return value:
        Nothing
*/
params ["_group"];

private _airspaceCentrePos = getPos (selectRandom GVAR(airspaceCentre));
[_group, _airspaceCentrePos, 500, "SAD", "AWARE"] call CBA_fnc_addWaypoint;

private _airSpawn = getPos (selectRandom GVAR(planeSpawns));
[_group, _airSpawn, 50, "MOVE", "AWARE", "YELLOW", "NORMAL", "", QUOTE([this] call FUNC(handleDelete))] call CBA_fnc_addWaypoint;

private _vehicle = vehicle (leader _group);
_vehicle flyInHeight ([500, 300] select (_vehicle isKindOf "Helicopter"));
