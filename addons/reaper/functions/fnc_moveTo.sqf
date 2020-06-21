#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Moves drone to crosshair with type.

    Parameter(s):
        0: UAV <OBJECT>
        1: Mode <SCALAR>

    Return Value:
        Nothing
*/
params ["_uav", "_type"];

private _group = group _uav;
private _screenPosition = screenToWorld [0.5, 0.5];
private _position = [_screenPosition#0, _screenPosition#1, (_uav getVariable QGVAR(targetHeightASL))];
private _waypoint = ((waypoints _group) select (count (waypoints _group)) - 1);

if (count (waypoints _group) <= 1) then {
    _waypoint = _group addWaypoint [_position, 0];
} else {
    _waypoint setWaypointPosition [_position, 0];
};
_waypoint setWaypointType "MOVE";
_group setCurrentWaypoint _waypoint;

switch (_type) do {
    case 0: {
        _uav setVariable [QGVAR(diveMode), false, true];
        _uav setVariable [QGVAR(observationMode), false, true];
    };
    case 1: {
        _uav setVariable [QGVAR(diveMode), false, true];
        _uav setVariable [QGVAR(observationMode), true, true];
        _waypoint setWaypointType 'LOITER';
        _waypoint setWaypointLoiterRadius 1500;
    };
    case 2: {
        _uav setVariable [QGVAR(diveMode), true, true];
        _uav setVariable [QGVAR(observationMode), false, true];
    };
};
