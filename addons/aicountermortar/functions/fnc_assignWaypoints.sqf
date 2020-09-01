#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
    Assigns waypoints to response forces. Does seperate things for air and ground forces

    Parameters:
        0: ai group created <GROUP>
        1: friendly mortar position <POSITION>

    Return value:
        Nothing
*/

params ["_group","_bluforMortarPos"];


private _groupStartPos = getPos leader _group;
private _initialWPPos = _bluforMortarPos getPos [800, random 360];


if ((vehicle leader _group) isKindOf "Helicopter") then {
    private _helipad = "Land_HelipadEmpty_F" createVehicle _initialWPPos;
    [_group, _initialWPPos, 0, "TR UNLOAD"] call CBA_fnc_addWaypoint;
    [_group, _groupStartPos, 0, "MOVE", "AWARE","YELLOW","FULL","","[this] call uksf_aicountermortar_fnc_handleDelete;"] call CBA_fnc_addWaypoint;
} else {
    [_group, _initialWPPos, 0, "GETOUT", "AWARE", "YELLOW", "NORMAL", "WEDGE", "", [20,25,30]] call CBA_fnc_addWaypoint;
    [_group, _bluforMortarPos, 0, "SAD", "AWARE", "YELLOW", "NORMAL", "WEDGE", "[this] call uksf_aicountermortar_fnc_handleDelete;", [40,50,60]] call CBA_fnc_addWaypoint;
};
