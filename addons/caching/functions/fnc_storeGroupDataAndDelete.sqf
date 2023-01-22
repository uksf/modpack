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
diag_log format ["### Caching ID ###: %1",_uniqueGroupId];

// leader pos (for measuring distance)
private _leaderPos = getPos (leader _group);

// add key pair to array [uid, pos]
GVAR(cachedGroupsPositions) pushBack [_uniqueGroupId, _leaderPos];

// side
private _side = side _group;

// get unit details
private _unitDetailsArray = [_group] call FUNC(getUnitDetails);

// get waypoints
private _waypointsArray = [_group] call FUNC(getGroupWaypoints);

// get combatmode
private _combatMode = combatMode _group;

// TO DO: Handle disabled ai features

GVAR(cachedGroupsData) set [_uniqueGroupId, [_side, _unitDetailsArray, _waypointsArray, _combatMode]];

{
    deleteVehicle _x;
} forEach units _group;
deleteGroup _group;
