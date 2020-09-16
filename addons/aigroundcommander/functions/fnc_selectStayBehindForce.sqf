#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Selects which group wil stay behind

    Parameters:
        0: Group <GROUP>

    Return value:
        Nothing
*/
params ["_group"];

if !(local _group) exitWith {};

private _leader = leader _group;
if !(GVAR(stayBehindGroupSelected)) exitWith {
    private _stayBehindGroup = selectRandom GVAR(transportGroups);
    if (isNull _stayBehindGroup) exitWith {};

    GVAR(stayBehindGroupSelected) = true;
    [_group, (getPos _leader), 300, 7, "MOVE", "SAFE"] call CBA_fnc_taskPatrol;
    _group leaveVehicle (_group getVariable [QEGVAR(common,assignedVehicle), objNull]);
};

[_group, (getPos (assignedVehicle _leader)), 0, "GETIN", "AWARE", "YELLOW", "NORMAL"] call CBA_fnc_addWaypoint;
[_group, (_group getVariable [QGVAR(spawnPosition), getPos _leader]), 50, "MOVE", "AWARE", "YELLOW", "FULL", "FILE", QUOTE((group this) setVariable [ARR_2(QQGVAR(hasFinishedTask),true)])] call CBA_fnc_addWaypoint;
