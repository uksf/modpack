#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Gets group details and stores them

    Parameters:
        0: Group to virtualise <GROUP>

    Return value:
        Nothing
*/
params ["_group"];

private _side = side _group;
private _leader = leader _group;
private _position = getPos _leader;
private _combatMode = combatMode _group;
private _formationDirection = formationDirection _leader;

private _vehicles = [_group] call FUNC(getGroupVehicles);
private _vehicleDetails = [_vehicles] call FUNC(getVehicleDetails);
private _unitDetails = [_group, _vehicles] call FUNC(getInfantryDetails);
private _waypoints = [_group] call FUNC(getGroupWaypoints);

private _id = format ["%1_v%2_u%3_%4%5%6", _side, count _vehicleDetails, count _unitDetails, _position#0, _position#1, _position#2];
GVAR(groupPositionMap) pushBack [_id, _position];
GVAR(groupDataMap) set [_id, [_side, _vehicleDetails, _unitDetails, _waypoints, _combatMode, _formationDirection]];
TRACE_2("virtualised group",_group,_id);

{deleteVehicle _x} forEach (units _group);
{deleteVehicle _x} forEach _vehicles;
[QGVAR(deleteGroup), _group, _group] call CBA_fnc_targetEvent;
