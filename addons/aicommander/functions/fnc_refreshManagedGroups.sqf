#include "script_component.hpp"
/*
    Author:
        Codex

    Description:
        Remove dead/invalid managed groups from commander tracking.

    Parameters:
        0: Commander module <OBJECT>

    Return Value:
        Managed group entries <ARRAY>
*/

params [["_commander", objNull, [objNull]]];

if (isNull _commander) exitWith {[]};

private _managedGroups = _commander getVariable [QGVAR(managedGroups), []];
private _aliveManaged = _managedGroups select {
    private _group = _x getOrDefault ["group", grpNull];
    !isNull _group && {alive (leader _group)}
};

_commander setVariable [QGVAR(managedGroups), _aliveManaged];
_aliveManaged

