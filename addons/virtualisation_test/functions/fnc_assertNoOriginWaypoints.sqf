#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Scans virtualisation state for any waypoint position equal to [0,0,0].
        Checks fullWaypoints in groupDataMap and simState position. Returns a
        failure reason string, or "" if clean.

    Parameter(s):
        0: Group id <STRING>

    Return Value:
        Failure reason or empty string <STRING>

    Example:
        [_id] call uksf_virtualisation_test_fnc_assertNoOriginWaypoints
*/
params ["_id"];

private _entry = EGVAR(virtualisation,groupDataMap) get _id;
if (isNil "_entry") exitWith { format ["no entry for %1", _id] };

_entry params ["", "", "", "", "", "", "_simState", "", "_fullWaypoints"];

private _badWaypointIndex = _fullWaypoints findIf { (_x#0) isEqualTo [0,0,0] };
if (_badWaypointIndex >= 0) exitWith {
    format ["fullWaypoints[%1] is [0,0,0]", _badWaypointIndex]
};

private _simPosition = _simState#1;
if (_simPosition isEqualTo [0,0,0]) exitWith {
    "simState position is [0,0,0]"
};

""
