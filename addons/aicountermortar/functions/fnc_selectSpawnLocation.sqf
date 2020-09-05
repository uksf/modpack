#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Sets spawn position for hunter forces and calls their creation function

    Parameters:
        0: Mortar position <ARRAY>
        1: Force type <SCALAR>

    Return value:
        Nothing
*/
params ["_mortarPosition", "_forceType"];

if (_forceType == 1) exitWith { // ground vehicle
    private _spawnPosition = selectRandom GVAR(groundSpawns);
    [getPos _spawnPosition, _mortarPosition] call FUNC(createGroundForce);
};

if (_forceType == 2) exitWith { // air
    private _spawnPosition = selectRandom GVAR(airSpawns);
    [getPos _spawnPosition, _mortarPosition] call FUNC(createAirForce);
};
