#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Registers an air threat spawn point position.
        Aircraft will be created at these positions when missions spawn.
        Server only.

    Parameters:
        0: Arguments <ARRAY>
        1: Module logic <OBJECT>

    Return Value:
        Nothing

    Example:
        [_this, _logic] call uksf_airthreat_fnc_moduleSpawnPoint
*/

(_this select 1) params ["_logic"];

if !(local _logic) exitWith {};
if !(isServer) exitWith {};

GVAR(spawnPoints) pushBack (getPosASL _logic);

INFO_1("Registered air threat spawn point at %1",getPosASL _logic);
