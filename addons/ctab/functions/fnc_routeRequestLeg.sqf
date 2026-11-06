#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Sets the path of one route leg.
        The leg is a straight line at once. With roads on, Arma's path finder then replaces it with a road path for a car.
        A path that arrives after the route has changed is ignored.

    Parameter(s):
        0: Leg index, the leg from waypoint index to waypoint index + 1 <NUMBER>

    Return Value:
        Nothing

    Example:
        [0] call uksf_ctab_fnc_routeRequestLeg
*/
params ["_index"];

private _from = GVAR(routeWaypoints) select _index;
private _to = GVAR(routeWaypoints) select (_index + 1);
GVAR(routeLegs) set [_index, [_from, _to]];
call FUNC(routeRefresh);

if (!GVAR(routeRoads)) exitWith {};

private _agent = calculatePath ["car", "safe", _from, _to];
_agent setVariable [QGVAR(routeLeg), [_index, _from, _to]];
_agent addEventHandler ["PathCalculated", {
    params ["_agent", "_path"];
    (_agent getVariable [QGVAR(routeLeg), []]) params [["_index", -1], "_from", "_to"];
    _agent setVariable [QGVAR(routeLeg), nil];

    private _leg = GVAR(routeLegs) param [_index, []];
    if (!GVAR(routeRoads) || {_leg isNotEqualTo [_from, _to]} || {count _path < 2}) exitWith {};

    GVAR(routeLegs) set [_index, [_from] + _path + [_to]];
    call FUNC(routeRefresh);
}];
