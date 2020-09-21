#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Assigns waypoints to response forces.
        Does seperate things for air and ground forces

    Parameters:
        0: Group <GROUP>
        1: Mortar position <ARRAY>

    Return value:
        Nothing
*/
params ["_group", "_mortarPosition"];

private _leader = leader _group;
private _groupPosition = getPos _leader;
private _waypointPosition = _mortarPosition getPos [800, random 360];

if ((vehicle _leader) isKindOf "Helicopter") then {
    private _helipad = "Land_HelipadEmpty_F" createVehicle _waypointPosition; // TODO: Needs safety checking. What if this ends up in a forest or out to sea?
    [_group, _waypointPosition, 0, "TR UNLOAD"] call CBA_fnc_addWaypoint;
    [_group, _groupPosition, 0, "MOVE", "AWARE", "YELLOW", "FULL", "", QUOTE([this] call FUNC(handleDelete))] call CBA_fnc_addWaypoint;
    _helipad
} else {
    [_group, _waypointPosition, 0, "GETOUT", "AWARE", "YELLOW", "NORMAL", "WEDGE", "", [20, 25, 30]] call CBA_fnc_addWaypoint;
    [_group, _mortarPosition, 0, "SAD", "AWARE", "YELLOW", "NORMAL", "WEDGE", QUOTE([this] call FUNC(handleDelete)), [40, 50, 60]] call CBA_fnc_addWaypoint;
};
