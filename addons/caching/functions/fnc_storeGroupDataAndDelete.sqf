#include "script_component.hpp"
/*
    Author:
        Bridg

    Description:
        Gets group details and stores them.
        Currently doing this to a variable, can change this later to a DB or name space etc.

    Parameters:
        None.

    Return value:
        Nothing.
*/

params ["_group"];

TRACE_1("6) gathered info : group :", _group);
// assign Id for finding / deleting
private _uniqueGroupId = "uid_" + (str getPos leader _group);
TRACE_1("6) gathered info : uid :",_uniqueGroupId);

// leader pos (for measuring distance)
private _leaderPos = getPos (leader _group);
TRACE_1("6) gathered info : leader pos :",_leaderPos);

// add key pair to array [uid, pos]
GVAR(cachedGroupsPositions) pushBack [_uniqueGroupId, _leaderPos];

// side
private _side = side _group;
TRACE_1("6) gathered info : side :", _side);

// get waypoints
private _waypointsArray = [_group] call FUNC(getGroupWaypoints);
TRACE_1("6) gathered info : waypoints :", _waypointsArray);

// get combatmode
private _combatMode = combatMode _group;
TRACE_1("6) gathered info : combat mode :", _combatMode);

// get inf / vehicle details
if ((vehicle leader _group) isKindOf "LandVehicle") then { // need a better way to do this
    private _unitDetailsArray = [_group] call FUNC(getVehicleUnitDetails);
    // update hash map
    GVAR(cachedGroupsData) set [_uniqueGroupId, [_side, _unitDetailsArray, _waypointsArray, _combatMode, SAVED_TYPE_VEHICLE]];
} else {
    private _unitDetailsArray = [_group] call FUNC(getInfantryUnitDetails);
    // update hash map
    GVAR(cachedGroupsData) set [_uniqueGroupId, [_side, _unitDetailsArray, _waypointsArray, _combatMode, SAVED_TYPE_INFANTRY]];
};

// delete
deleteVehicle (vehicle leader _group);
{
    deleteVehicle _x;
} forEach units _group;
deleteGroup _group;


