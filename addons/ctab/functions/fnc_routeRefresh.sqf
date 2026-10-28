#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Updates the Route app panel with the route length and travel times.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_ctab_fnc_routeRefresh
*/
private _length = 0;
{
    private _leg = _x;
    for "_i" from 1 to (count _leg - 1) do {
        _length = _length + ((_leg select (_i - 1)) distance2D (_leg select _i));
    };
} forEach GVAR(routeLegs);

private _lines = [format ["Waypoints: %1", count GVAR(routeWaypoints)]];
if (GVAR(routeWaypoints) isEqualTo []) then {
    _lines pushBack "Click the map to add a waypoint.";
} else {
    _lines pushBack format ["From you: %1", (cTab_player distance2D (GVAR(routeWaypoints) select 0)) call FUNC(formatDistance)];
    _lines pushBack format ["Length: %1", _length call FUNC(formatDistance)];
    _lines pushBack format ["On foot: %1", (_length / SPEED_FOOT) call FUNC(formatDuration)];
    _lines pushBack format ["Vehicle: %1", (_length / SPEED_VEHICLE) call FUNC(formatDuration)];
};

[APP_CTRL(routeInfo), _lines] call FUNC(setInfo);
