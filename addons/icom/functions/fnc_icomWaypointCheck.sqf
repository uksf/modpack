#include "script_component.hpp"
/*
    Author:
        Westen

    Description:
        ICOM scan function - passing in a group and source object (e.g. player or laptop), determines if the group is moving to attack/intercept the position or is just nearby.
        If moving or SADing within 100m, will return Enemies incoming.
        Otherwise, enemies nearby.

    Parameters:
        0: group <GROUP>
        1: source <OBJECT>

    Return value:
        Nothing
*/

params ["_group", "_source"];

_waypointPosition = waypointPosition [_group, 1];

private _currentPos = position (leader _group);
private _distance = _waypointPosition distance position _source;
private _currentPosDistance = _currentPos distance _source;

if (_distance <= 100) exitWith {hint format["Scan Result: Communication suggests insurgents are heading our way."]};
if (_currentPosDistance < 400) exitWith {hint format["Scan Result: Communication suggests insurgents are nearby."]};
hint format ["Scan Result: No communication detected."];
