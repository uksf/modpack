#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
       Retasks group of given leader back to their start position.

    Parameters:
        0: Unit <OBJECT>

    Return value:
        Nothing
*/
params ["_leader"];

if (!local _leader) exitWith {};

private _group = group _leader;
private _startPosition = _group getVariable [QGVAR(qrfGroupStartPos), [0,0,0]];
_group setVariable [QGVAR(supportTasked), false, true];

[_group, _startPosition, 0, "MOVE", "AWARE", "YELLOW", "NORMAL", "WEDGE"] call CBA_fnc_addWaypoint;

// [QGVAR(reTask), [_group, _patrolPosition]] call CBA_fnc_localEvent;
