#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Draws the planned route on a cTab map: each leg as a line and each waypoint as a numbered dot.

    Parameter(s):
        0: Map control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_map] call uksf_ctab_fnc_routeDraw
*/
params ["_map"];

{
    private _leg = _x;
    for "_i" from 1 to (count _leg - 1) do {
        _map drawLine [_leg select (_i - 1), _leg select _i, COLOUR_ROUTE];
    };
} forEach GVAR(routeLegs);

{
    _map drawIcon [ICON_DOT, COLOUR_ROUTE, _x, 20, 20, 0, str (_forEachIndex + 1), 2, 0.05, "RobotoCondensedBold", "right"];
} forEach GVAR(routeWaypoints);
