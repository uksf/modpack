#include "script_component.hpp"
/*
    Author:
        Bridg, Tim Beswick

    Description:
        Snapshots a group, deletes its in-world entities, and registers it as
        virtualised. Captures additional state needed by the waypoint simulation
        (full waypoint list, original leader position, composition base speed)
        and adds the id to simulatedGroupIds if the group has any MOVE or CYCLE
        waypoints to simulate.

    Parameters:
        0: Group to virtualise <GROUP>

    Return value:
        Nothing

    Example:
        [_group] call uksf_virtualisation_fnc_virtualiseGroup
*/
params ["_group"];

private _side = side _group;
private _leader = leader _group;
private _position = getPos _leader;
private _originalLeaderPos = getPosASL _leader;
private _combatMode = combatMode _group;
private _formationDirection = formationDirection _leader;
private _leaderBehaviour = behaviour _leader;

private _vehicles = [_group] call FUNC(getGroupVehicles);
private _vehicleDetails = [_vehicles] call FUNC(getVehicleDetails);
private _unitDetails = [_group, _vehicles] call FUNC(getInfantryDetails);
private _waypoints = [_group] call FUNC(getGroupWaypoints);
private _fullWaypoints = [_group] call FUNC(getFullGroupWaypoints);
private _movementSpeed = [_side, _vehicleDetails, _unitDetails] call FUNC(getSimMovementSpeed);

private _id = format ["%1_v%2_u%3_%4%5%6", _side, count _vehicleDetails, count _unitDetails, _position#0, _position#1, _position#2];

private _simState = [currentWaypoint _group, _position, _leaderBehaviour, "NORMAL", 0];

GVAR(groupPositionMap) pushBack [_id, _position];
GVAR(groupDataMap) set [_id, [
    _side, _vehicleDetails, _unitDetails, _waypoints, _combatMode, _formationDirection,
    _simState, diag_tickTime, _fullWaypoints, _movementSpeed, _originalLeaderPos
]];

private _hasMovement = _fullWaypoints findIf {
    private _type = toUpper (_x#1);
    _type == "MOVE" || _type == "CYCLE"
};
if (_hasMovement != -1) then {
    GVAR(simulatedGroupIds) pushBack _id;
};

TRACE_3("virtualised group",_group,_id,_hasMovement);

{deleteVehicle _x} forEach (units _group);
{deleteVehicle _x} forEach _vehicles;
[QGVAR(deleteGroup), _group, _group] call CBA_fnc_targetEvent;
