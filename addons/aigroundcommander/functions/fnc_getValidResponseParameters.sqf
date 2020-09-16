#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Validates and gets spawn positions, staging areas, and players available for a response cycle

    Parameters:
        0: Spawn logics <ARRAY>

    Return value:
        False if no spawns <BOOLEAN>
        OR
        Array of valid spawn positions <ARRAY>
            0: Spawn positions <ARRAY>
                0: Spawn position <ARRAY>
                1: Staging areas <ARRAY>
                    0: Staging area <ARRAY>
                    1: Players <ARRAY>
                        0: Player position <ARRAY>
*/
params ["_spawns"];

if (_spawns isEqualTo []) exitWith {
    false
};

[_spawns, true] call CBA_fnc_shuffle;
private _validSpawns = _spawns select {alive _x};
if (_validSpawns isEqualTo []) exitWith {
    []
};

_validSpawns = _validSpawns apply {[getPos _x, [_x] call FUNC(getStagingAreas)]};
_validSpawns = _validSpawns select {!(_x#1 isEqualTo [])};
if (_validSpawns isEqualTo []) exitWith {
    []
};

_validSpawns = _validSpawns apply {[_x#0, _x#1 apply {[_x, [_x] call FUNC(getPlayers)]}]};
_validSpawns = _validSpawns select {!((_x#1 select {!(_x#1 isEqualTo [])}) isEqualTo [])};
if (_validSpawns isEqualTo []) exitWith {
    []
};

_validSpawns
