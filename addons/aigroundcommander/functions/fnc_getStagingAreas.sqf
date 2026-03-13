#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Gets nearest staging location to given spawn position module

    Parameters:
        0: Spawn position module <OBJECT>

    Return value:
        Staging area positions <ARRAY>

    Example:
        [_spawnPosition] call uksf_aigroundcommander_fnc_getStagingAreas
*/
params ["_spawnPosition"];

if (GVAR(stagingAreas) isEqualTo []) exitWith {
    []
};

private _stagingAreas = GVAR(stagingAreas) apply {[_x distance2D _spawnPosition, _x]};
if (_stagingAreas isEqualTo []) exitWith {
    []
};

_stagingAreas sort true;
_stagingAreas apply {getPos (_x#1)}
