#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Draws drone tasks: a line from each drone to its task point,
        the task point with the task name, and the circle a drone flies round that point when it circles it.
        In the Drones app it draws the listed drones, the selected drone brighter, and a map point that is set but not sent as a cross.
        On the small display it draws every drone cTab tracks.

    Parameter(s):
        0: Map control <CONTROL>
        1: Small display <BOOL> (default: false)

    Return Value:
        Nothing

    Example:
        [_map] call uksf_ctab_fnc_droneDraw
*/
params ["_map", ["_mini", false]];

if (!_mini && {GVAR(currentApp) != "drones"}) exitWith {};

private _drones = GVAR(drones);
private _selected = objNull;
if (_mini) then {
    _drones = missionNamespace getVariable ["cTabUAVlist", []];
} else {
    _selected = _drones param [lbCurSel APP_CTRL(droneList), objNull];
};
{
    if (!alive _x) then { continue };
    (_x getVariable [QGVAR(droneTask), []]) params [["_task", ""], ["_point", []]];
    if (_task == "" || {_point isEqualTo []}) then { continue };

    private _colour = [COLOUR_DRONE_OTHER, COLOUR_DRONE] select (_x == _selected);
    private _position = getPosASLVisual _x;
    _map drawLine [_position, _point, _colour];
    _map drawIcon [ICON_DOT, _colour, _point, 20, 20, 0, toUpper _task, 1, 0.04, "RobotoCondensedBold", "right"];
    if (_x isKindOf "Plane" || {_x isKindOf "Air" && {!(_task in ["hold", "return"])}}) then {
        _map drawEllipse [_point, DRONE_LOITER_RADIUS, DRONE_LOITER_RADIUS, 0, _colour, ""];
    };
} forEach _drones;

if (!_mini && {GVAR(dronePoint) isNotEqualTo []}) then {
    _map drawIcon [ICON_POINT, COLOUR_DRONE, GVAR(dronePoint), 24, 24, 0, "", 0, 0.04, "RobotoCondensed", "right"];
};
