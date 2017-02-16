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
params ["_leader"];

if (!isServer && isMultiplayer) exitWith {};

_patrolArea = (group _leader) getVariable ["PatrolMarker", ""];
(group _leader) setVariable ["Tasked", false, true];

if (_patrolArea isEqualTo "") then {
    [[group _leader], {[_this select 0, getPos (_this select 0)] call CBA_fnc_taskPatrol;}] remoteExecCall ["bis_fnc_call", groupOwner (group _leader)];
} else {
    [[group _leader, _patrolArea], {[_this select 0, _this select 1] call CBA_fnc_taskPatrol;}] remoteExecCall ["bis_fnc_call", groupOwner (group _leader)];
};     