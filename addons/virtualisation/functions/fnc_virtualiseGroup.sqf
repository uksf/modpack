#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Gets group details and stores them.
        Currently doing this to a variable, can change this later to a DB or name space etc.

    Parameters:
        0: Group to virtualise <GROUP>

    Return value:
        Nothing
*/
params ["_group"];

private _leader = leader _group;
private _id = call CBA_fnc_createUUID;
private _position = getPos _leader;
GVAR(virtualisedGroupsPositionMap) pushBack [_id, _position];

private _side = side _group;
private _combatMode = combatMode _group;
private _formationDirection = formationDirection _leader;
private _waypointsArray = [_group] call FUNC(getGroupWaypoints);

private _type = SAVED_TYPE_INFANTRY;
private _unitDetails = [];
if ((vehicle _leader) isKindOf "LandVehicle") then { // need a better way to do this
    _unitDetails = [_group] call FUNC(getVehicleUnitDetails);
    _type = SAVED_TYPE_VEHICLE;
} else {
    _unitDetails = [_group] call FUNC(getInfantryUnitDetails);
};
GVAR(virtualisedGroups) set [_id, [_type, _side, _unitDetails, _waypointsArray, _combatMode, _formationDirection]];

{deleteVehicle _x} forEach units _group;
deleteVehicle (vehicle _leader);
[QGVAR(deleteGroup), [_group], _group] call CBA_fnc_targetEvent;
