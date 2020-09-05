#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Create APC with only crew, no dismounts

    Parameters:
        0: Spawn position module <OBJECT>
        1: Callback once spawning complete <CODE> (Optional)
        2: Callback arguments <ARRAY> (Optional)

    Return value:
        Nothing
*/
params ["_spawnPosition", ["_callback", {}, [{}]], ["_callbackArgs", [], [[]]]];

if !(alive _spawnPosition) exitWith {};

[_spawnPosition getPos [20, random 360], 1, 0, EAST, EGVAR(gear,gearCrew), EGVAR(gear,gearAPC), {
    params ["_vehicle", "_turrets"];

    (_vehicle emptyPositions "driver") + count _turrets
}, {
    params ["_callback", "_callbackArgs", "_group"];

    _callbackArgs pushBack _group;
    _callbackArgs call _callback;
}, [_callback, _callbackArgs]] call EFUNC(common,spawnGroup);
