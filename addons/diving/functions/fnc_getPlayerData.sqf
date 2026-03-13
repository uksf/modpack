#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Gets player data from hash map if it exists, or default not-diving state

    Parameter(s):
        0: Player UID <STRING>

    Return Value:
        Data <ARRAY>

    Example:
        [_uid] call uksf_diving_fnc_getPlayerData
*/
params ["_uid"];

GVAR(playerDataHash) getOrDefault [_uid, [false]]
