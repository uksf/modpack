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

// assign Id for finding / deleting
private _uniqueGroupId = "uid_" + (str getPos leader _group);

// leader pos (for measuring distance)
private _leaderPos = getPos (leader _group);

// add key pair to array [uid, pos]
GVAR(cachedGroupsPositions) pushBack [_uniqueGroupId, _leaderPos];

// side
private _side = side _group;

// get unit details
private _unitDetailsArray = [_group] call FUNC(getInfantryUnitDetails);
// if ((vehicle leader _group) == leader _group) then {
//     private _unitDetailsArray = [_group] call FUNC(getInfantryUnitDetails);
//     _unitDetailsArray
// } else {
//     private _unitDetailsArray = [_group] call FUNC(getVehicleUnitDetails);
//     _unitDetailsArray
// };

// get waypoints
private _waypointsArray = [_group] call FUNC(getGroupWaypoints);

// get combatmode
private _combatMode = combatMode _group;

GVAR(cachedGroupsData) set [_uniqueGroupId, [_side, _unitDetailsArray, _waypointsArray, _combatMode]];

deleteVehicle (vehicle leader _group);
{
    deleteVehicle _x;
} forEach units _group;
deleteGroup _group;
