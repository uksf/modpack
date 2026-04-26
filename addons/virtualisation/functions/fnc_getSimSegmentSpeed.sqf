#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Resolves final segment speed (m/s) from base movement speed, waypoint
        speed mode and waypoint behaviour. Combat mode ignored (negligible effect).
        Applies the wiki rule that COMBAT behaviour ignores LIMITED speed mode.

    Parameter(s):
        0: Movement speed (composition base) <NUMBER>
        1: Waypoint speed mode <STRING> ("LIMITED" | "NORMAL" | "FULL")
        2: Waypoint behaviour <STRING> ("CARELESS" | "SAFE" | "AWARE" | "COMBAT" | "STEALTH")

    Return Value:
        Segment speed in m/s, clamped to [SPEED_FLOOR_MS, SPEED_CEIL_MS] <NUMBER>

    Example:
        [_movementSpeed, "NORMAL", "AWARE"] call uksf_virtualisation_fnc_getSimSegmentSpeed
*/
params ["_movementSpeed", "_waypointSpeed", "_waypointBehaviour"];

if (_waypointBehaviour == "COMBAT" && {_waypointSpeed == "LIMITED"}) then { _waypointSpeed = "NORMAL" };

private _speedFactor = switch (_waypointSpeed) do {
    case "LIMITED": { 0.5 };
    case "FULL": { 1.4 };
    default { 1.0 };
};

private _behaviourFactor = switch (_waypointBehaviour) do {
    case "CARELESS": { 1.0 };
    case "SAFE": { 1.1 };
    case "COMBAT": { 0.6 };
    case "STEALTH": { 0.4 };
    default { 1.0 };
};

(((_movementSpeed * _speedFactor) * _behaviourFactor) max SPEED_FLOOR_MS) min SPEED_CEIL_MS
