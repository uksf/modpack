/*
    Author:
        Tim Beswick

    Description:
        Initialises persistence event handlers on client

    Parameter(s):
        None

    Return Value:
        None
*/
#include "script_component.hpp"

TRACE_1("Server init",GVAR(enabled));
if (!GVAR(enabled)) exitWith {};

GVAR(hashPersistentVehicles) = [[], true] call CBA_fnc_hashCreate;
GVAR(hashFirstKilled) = [[], true] call CBA_fnc_hashCreate;
GVAR(hashFirstRespawn) = [[], true] call CBA_fnc_hashCreate;

["All", "init", {_this call FUNC(checkVehicleForPersistence)}, true, nil, true] call CBA_fnc_addClassEventHandler;

addMissionEventHandler ["PlayerConnected", {_this call FUNC(playerConnected)}];
addMissionEventHandler ["EntityRespawned", {_this call FUNC(entityRespawned)}];
addMissionEventHandler ["EntityKilled", {_this call FUNC(entityKilled)}];
addMissionEventHandler ["HandleDisconnect", {_this call FUNC(handleDisconnect)}];
addMissionEventHandler ["PlayerDisconnected", {_this call FUNC(playerDisconnected)}];

[QGVAR(shutdown), {_this call FUNC(shutdown)}] call CBA_fnc_addEventHandler;
[QGVAR(markVehicleAsPersistent), {_this call FUNC(markVehicleAsPersistent)}] call CBA_fnc_addEventHandler;

GVAR(dataNamespace) setVariable [QGVAR(world), worldName];
profileNamespace setVariable [GVAR(key), [GVAR(dataNamespace)] call CBA_fnc_serializeNamespace];
