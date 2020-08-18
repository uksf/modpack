#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Delete the AI that are finished with, usually called from last waypoint. 
        Currently only used for infantry and ground vehicles

    Parameters:
        0: _leader <OBJECT>
        
    Return value:
        Nothing
*/

params ["_leader"];

GVAR(responseGroups) deleteAt (GVAR(responseGroups) find (group _leader));

private _groupUnitCount = count (units group _leader);
GVAR(currentUnitCount) = GVAR(currentUnitCount) - _groupUnitCount;

if ((vehicle _leader) isKindOf "MAN") exitWith {
    {deleteVehicle _x} forEach units (group _leader);
};

deleteVehicle (vehicle _leader);
{deleteVehicle _x} forEach units (group _leader);

GVAR(numberOfStayBehindGroups) = 1;
GVAR(tier1ResponseDeployed) = 0;
GVAR(tier2ResponseDeployed) = 0;
GVAR(readyAtStagingArea) = 0;