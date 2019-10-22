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

if (!local _leader) exitWith {};

private _group = group _leader;
private _patrolPosition = _group getVariable [QGVAR(spawnPosition), ""];
_group setVariable [QGVAR(supportTasked), false, true];

if (_patrolPosition == "") then {
    _patrolPosition = getPos _leader;
};
[QGVAR(reTask), [_group, _patrolPosition]] call CBA_fnc_localEvent;
