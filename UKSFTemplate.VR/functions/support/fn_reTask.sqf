/*
    Author:
        Julian Alwandy & Tim Beswick

    Description:
       Retasks group of given leader back to their existing patrol.

    Parameters:
        0: Unit <OBJECT>

    Return value:
        Nothing
*/
#include "script_component.hpp"

params ["_leader"];

if (!isServer) exitWith {};

private _patrolPosition = (group _leader) getVariable [QGVAR(spawnPosition), ""];
(group _leader) setVariable [QGVAR(tasked), false, true];

if (_patrolPosition != "") then {
    [[group _leader, _patrolPosition], {[_this select 0, _this select 1] call CBA_fnc_taskPatrol;}] remoteExecCall ["bis_fnc_call", groupOwner (group _leader)];
};     
