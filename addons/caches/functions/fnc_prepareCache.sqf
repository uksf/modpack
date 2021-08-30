#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Prepares caches by adding numbers of items from lists in preInit.

    Parameters:
        0: Cache <OBJECT>

    Return value:
        Nothing.
*/
params ["_cache", "_contentTypes"];

if (!isServer) exitWith {};

clearItemCargoGlobal _cache;

for "_i" from 1 to 15 do {_cache addItemCargoGlobal [selectRandom _contentTypes, 1]};


