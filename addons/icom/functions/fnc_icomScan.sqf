#include "script_component.hpp"
/*
    Author:
        Westen

    Description:
        ICOM scan - performs nearby scan for enemy radio chatter.
        Uses the waypoint

    Parameters:
        0: target <OBJECT>

    Return value:
        Nothing
*/

params ["_target"];

hint "Scanning for communications...";
playSound QGVAR(tuneRadio);

GVAR(scanInProgress) = true;

[{
    params ["_target"];

    GVAR(scanInProgress) = false;

    private _nearestAI = nearestObjects [_target, ["CAManBase"], 400];
    if(count _nearestAI == 0) exitWith {hint format ["Scan Result: No communication detected."]}; // exit if no units found

    private _nearestAI = _nearestAI select {side _x == EAST};
    if(count _nearestAI == 0) exitWith {hint format ["Scan Result: No communication detected."]}; // exit if EAST units not found.

    private _groupLeaders = _nearestAI select {_x == leader (group _x)};
    private _selectedGroupLeader = selectRandom _groupLeaders;

    [group _selectedGroupLeader, _target] call FUNC(icomWaypointCheck);

}, [_target], 25] call cba_fnc_waitAndExecute;

