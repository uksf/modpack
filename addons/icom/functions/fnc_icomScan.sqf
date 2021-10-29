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
    if (_nearestAI isEqualTo []) exitWith {hint "Scan Result: No communication detected."}; // exit if no units found

    _nearestAI = _nearestAI select {side _x == EAST};
    if (_nearestAI isEqualTo []) exitWith {hint "Scan Result: No communication detected."}; // exit if EAST units not found.

    private _randomAI = selectRandom _nearestAI;

    [group _randomAI, _target] call FUNC(icomWaypointCheck);

}, [_target], 25] call cba_fnc_waitAndExecute;

