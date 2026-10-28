#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Builds the Route app panel.
        A click on the map adds a waypoint. The panel shows the route length and the travel time on foot and by vehicle.
        With roads on, each leg follows the road network that Arma's path finder gives for a car.

    Parameter(s):
        0: cTab display <DISPLAY>
        1: App content group <CONTROL>
        2: Map control <CONTROL>

    Return Value:
        Nothing

    Example:
        [_display, _group, _map] call uksf_ctab_fnc_routeOpen
*/
params ["", "_group", "_map"];

[_group, "cTab_RscText", [0.04, 0.02, 0.92, 0.09], "Route"] call FUNC(createCtrl);
uiNamespace setVariable [QGVAR(routeInfo), [_group, [0.04, 0.12, 0.92, 0.5]] call FUNC(createInfo)];

[_group, [0.04, 0.64, 0.92, 0.09], [["Straight legs", false], ["Follow roads", true]], GVAR(routeRoads), {
    params ["_roads"];
    GVAR(routeRoads) = _roads;
    {
        [_forEachIndex] call FUNC(routeRequestLeg);
    } forEach GVAR(routeLegs);
}] call FUNC(createCombo);

[_group, [0.04, 0.76, 0.44, 0.1], "Undo", {
    if (GVAR(routeWaypoints) isEqualTo []) exitWith {};
    GVAR(routeWaypoints) deleteAt (count GVAR(routeWaypoints) - 1);
    if (GVAR(routeLegs) isNotEqualTo []) then {
        GVAR(routeLegs) deleteAt (count GVAR(routeLegs) - 1);
    };
    call FUNC(routeRefresh);
}] call FUNC(createButton);

[_group, [0.52, 0.76, 0.44, 0.1], "Clear", {
    GVAR(routeWaypoints) = [];
    GVAR(routeLegs) = [];
    call FUNC(routeRefresh);
}] call FUNC(createButton);

[_map, {
    params ["_position"];
    _position set [2, 0];
    GVAR(routeWaypoints) pushBack _position;
    if (count GVAR(routeWaypoints) > 1) then {
        GVAR(routeLegs) pushBack [];
        [count GVAR(routeLegs) - 1] call FUNC(routeRequestLeg);
    };
    call FUNC(routeRefresh);
}] call FUNC(addMapClickHandler);

call FUNC(routeRefresh);
