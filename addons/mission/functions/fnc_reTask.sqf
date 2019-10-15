#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
       Retasks group of given leader back to their existing patrol.

    Parameters:
        0: Unit <OBJECT>

    Return value:
        Nothing
*/

params ["_leader"];

if (!isServer) exitWith {};

private _patrolPosition = (group _leader) getVariable [QGVAR(spawnPosition), ""];
(group _leader) setVariable [QGVAR(tasked), false, true];

if (_patrolPosition != "") then {
    [QGVAR(reTask), [group _leader, _patrolPosition], groupOwner (group _leader)] call CBA_fnc_targetEvent;
};
