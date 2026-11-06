#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs on the server when a machine disconnects. Sends every escort that machine was running to the drone's new owner once the crew group has moved.

    Parameter(s):
        PlayerDisconnected mission event arguments; only 4: owner ID of the machine that left <NUMBER>

    Return Value:
        Nothing

    Example:
        addMissionEventHandler ["PlayerDisconnected", {_this call uksf_ctab_fnc_droneOwnerLeft}]
*/
params ["", "", "", "", "_owner"];

private _drones = GVAR(escorts) select {_x select 1 == _owner} apply {_x select 0};
if (_drones isEqualTo []) exitWith {};

[{
    {
        [_x] call FUNC(droneRoute);
    } forEach _this;
}, _drones, DRONE_REROUTE_DELAY] call CBA_fnc_waitAndExecute;
