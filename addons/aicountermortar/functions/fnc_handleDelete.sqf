#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Delete the AI and vehicles that have finished their task
        Also resets the in progress state to false

    Parameters:
        0: Group leader <OBJECT>

    Return value:
        Nothing
*/
params ["_leader"];

if !(isServer) exitWith {};

// TODO: Change this to use a common component for spawned AI deletion

(_leader getVariable [QEGVAR(common,assignedVehicle), objNull]) call CBA_fnc_deleteEntity;
(group _leader) call CBA_fnc_deleteEntity;

// MPHit is a risky method as it could never fire so the in progress sate would never reset, this has been added to supplement it for now.
// This guarantees that the state will reset after the in progress group have finished their task if they aren't killed
// There are still edge cases where the state may never be reset
[{GVAR(counterInProgress) = false}, [], 900] call CBA_fnc_waitAndExecute; // Reset in progress state after 15 minutes
