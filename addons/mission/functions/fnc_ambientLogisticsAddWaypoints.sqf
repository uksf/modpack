#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
       Adds waypoints to ambient logistic vehicles

    Parameters:
        0: _group <GROUP>
        1: _vehicle <OBJECT>
        2: _callbackArgs <ARRAY>

    Return value:
        Nothing
*/
params ["_group", "_vehicle", "_callbackArgs"];

_callbackArgs params ["_targetPos", "_logiSpawnPos"];

private _targetPos = selectRandom _destinations;
[_group, _targetPos, 10, "MOVE", "SAFE"] call CBA_fnc_addWaypoint;
[_group, _logiSpawnPos, 10, "MOVE", "SAFE", "", "", "", "{deleteVehicle _x} forEach crew (vehicle this) + [(vehicle this)];"] call CBA_fnc_addWaypoint;
