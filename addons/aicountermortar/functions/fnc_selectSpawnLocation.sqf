#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        sets spawn position for hunter forces and calls their creation function

    Parameters:
        0: _bluforMortarPos <POSITION>
        1: _forceType <NUMBER>
        
    Return value:
        Nothing
*/

params ["_bluforMortarPos","_forceType"];

if (_forceType == 1) exitWith { // ground vehicle    
    private _spawnPosition = selectRandom GVAR(groundForceSpawns);
    [_spawnPosition,_bluforMortarPos] call FUNC(createGroundForce);
};

if (_forceType == 2) exitWith { // air
    private _spawnPosition = selectRandom GVAR(airForceSpawns);
    [_spawnPosition,_bluforMortarPos] call FUNC(createAirForce);
};
