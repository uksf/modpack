#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Draws the drones listed in the Drones app while the app is open: a line from each drone to its task point,
        the task point with the task name, and the circle a drone flies round that point when it circles it.
        The selected drone is drawn brighter. A map point that is set but not sent is drawn as a cross.

    Parameter(s):
        0: Map control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_map] call uksf_ctab_fnc_droneDraw
*/
params ["_map"];

if (GVAR(currentApp) != "drones") exitWith {};

private _selected = GVAR(drones) param [lbCurSel APP_CTRL(droneList), objNull];
{
    if (!alive _x) then { continue };
    (_x getVariable [QGVAR(droneTask), []]) params [["_task", ""], ["_point", []]];
    if (_task == "" || {_point isEqualTo []}) then { continue };

    private _colour = [COLOUR_DRONE_OTHER, COLOUR_DRONE] select (_x == _selected);
    private _position = getPosASLVisual _x;
    if (_task == "escort") then { _point = getPosASLVisual ((_x getVariable QGVAR(droneTask)) param [2, _x]) };
    _map drawLine [_position, _point, _colour];
    _map drawIcon [ICON_DOT, _colour, _point, 20, 20, 0, toUpper _task, 1, 0.04, "RobotoCondensedBold", "right"];
    if (_x isKindOf "Plane" || {_x isKindOf "Air" && {!(_task in ["hold", "return"])}}) then {
        _map drawEllipse [_point, DRONE_LOITER_RADIUS, DRONE_LOITER_RADIUS, 0, _colour, ""];
    };
} forEach GVAR(drones);

if (GVAR(dronePoint) isNotEqualTo []) then {
    _map drawIcon [ICON_POINT, COLOUR_DRONE, GVAR(dronePoint), 24, 24, 0, "", 0, 0.04, "RobotoCondensed", "right"];
};
