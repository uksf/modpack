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

private _waypointPosition = waypointPosition [_group, 1];
private _currentPos = getPosATL (leader _group);

if (_waypointPosition distance _source <= 100) exitWith {hint "Scan Result: Communication suggests insurgents are heading our way."};
if (_currentPos distance _source < 400) exitWith {hint "Scan Result: Communication suggests insurgents are nearby."};
hint "Scan Result: No communication detected.";
