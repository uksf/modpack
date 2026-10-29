#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Returns the AI group that flies or drives a drone: the driver's group, or the gunner's group when the drone has no driver.

    Parameter(s):
        0: Drone <OBJECT>

    Return Value:
        Crew group, or grpNull <GROUP>

    Example:
        _drone call uksf_ctab_fnc_droneGroup
*/
params ["_drone"];

private _group = group driver _drone;
if (isNull _group) then {
    _group = group gunner _drone;
};
_group
