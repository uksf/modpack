#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Gets nearest staging location to given spawn position module

    Parameters:
        0: Spawn position module <OBJECT>

    Return value:
        Nothing
*/
params ["_spawnPosition"];

private _stagingAreas = GVAR(stagingAreas) apply {[_x distance2D _spawnPosition, _x]};
_stagingAreas sort true;
_stagingAreas#0#1
