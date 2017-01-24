/*
    Author:
        Tim Beswick

    Description:
        Moves drone to crosshair. Performs strike if strike true.

    Parameter(s):
        0: UAV <OBJECT>
        1: Strike mode <BOOL>

    Return Value:
        Nothing
*/
#include "script_component.hpp"

params ["_uav", "_strike"];

_group = group _uav;
_screenPosition = screenToWorld [0.5,0.5];
_position = [_screenPosition select 0, _screenPosition select 1, (_uav getVariable QGVAR(targetHeightASL))];
_waypoint = ((waypoints _group) select (count (waypoints _group)) - 1);
if (count (waypoints _group) <= 1) then {
    _waypoint = _group addWaypoint [_position, 0];
} else {
    _waypoint setWaypointPosition [_position, 0];
};
_waypoint setWaypointType "MOVE";
_group setCurrentWaypoint _waypoint;

if (_strike) then {
    _uav setVariable [QGVAR(diveMode), true, true];
    _uav setVariable [QGVAR(observationMode), false, true];
} else {
    _uav setVariable [QGVAR(diveMode), false, true];
    _uav setVariable [QGVAR(observationMode), false, true];
};
