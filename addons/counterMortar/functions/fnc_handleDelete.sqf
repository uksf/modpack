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


if (vehicle _leader isKindOf "MAN") exitWith {
    {deleteVehicle _x} forEach units (group _leader);
};

deleteVehicle (vehicle _leader);
{deleteVehicle _x} forEach units (group _leader);