#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Checks whether a new air threat mission can be spawned.
        Verifies that the system is initialised, spawn points exist,
        and the maximum concurrent mission limit has not been reached.

    Parameters:
        None

    Return Value:
        Can spawn <BOOL>

    Example:
        call uksf_airthreat_fnc_canSpawnMission
*/

if !(GVAR(controllerInitialised)) exitWith { false };
if (GVAR(spawnPoints) isEqualTo []) exitWith { false };
if (count GVAR(activeMissions) >= GVAR(maxConcurrentMissions)) exitWith { false };

true
