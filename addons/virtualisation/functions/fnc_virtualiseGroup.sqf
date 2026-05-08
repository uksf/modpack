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

// Filtered waypoints drop the engine auto-stub at 0, so subtract one.
private _nextIndex = ((currentWaypoint _group) - 1) max 0;

// _pathLinear[i] = path points to reach user WP i. _pathCycleReturn = path
// for last-MOVE → first-MOVE; swapped into _pathLinear[firstMove] on CYCLE.
private _pathLinear = _fullWaypoints apply { [] };
private _pathCycleReturn = [];

private _simState = [_nextIndex, _position, _leaderBehaviour, "NORMAL", 0, 0];

GVAR(groupPositionMap) pushBack [_id, _position];
GVAR(groupDataMap) set [_id, [
    _side, _vehicleDetails, _unitDetails, _waypoints, _combatMode, _formationDirection,
    _simState, CBA_missionTime, _fullWaypoints, _movementSpeed, _originalLeaderPos,
    _pathLinear, _pathCycleReturn
]];

private _hasMovement = _fullWaypoints findIf {
    private _type = toUpper (_x#1);
    _type == "MOVE" || _type == "CYCLE"
};
if (_hasMovement != -1) then {
    private _phase = GVAR(simPhaseCounter) mod SIM_INTERVAL;
    if (_phase == GVAR(simCursor)) then {
        GVAR(simPhaseCounter) = GVAR(simPhaseCounter) + 1;
        _phase = GVAR(simPhaseCounter) mod SIM_INTERVAL;
    };
    GVAR(simPhaseCounter) = GVAR(simPhaseCounter) + 1;
    GVAR(simPhases) set [_id, _phase];
    GVAR(simulatedGroupIds) pushBack _id;
};

TRACE_3("virtualised group",_group,_id,_hasMovement);

if (_hasMovement != -1 && {_vehicleDetails isNotEqualTo []}) then {
    private _moveIndices = [];
    {
        if ((toUpper (_x#1)) == "MOVE") then { _moveIndices pushBack _forEachIndex };
    } forEach _fullWaypoints;

    private _vehicleType = (_vehicleDetails#0)#0;
    private _resolveBehaviour = {
        params ["_wpBehaviour"];
        if (_wpBehaviour == "UNCHANGED" || {_wpBehaviour == ""}) exitWith { _leaderBehaviour };
        _wpBehaviour
    };

    private _segments = [];

    if (_moveIndices isNotEqualTo []) then {
        private _firstMoveIdx = _moveIndices#0;
        private _firstMoveWp = _fullWaypoints#_firstMoveIdx;
        _segments pushBack [
            _position,
            +(_firstMoveWp#0),
            _vehicleType,
            [_firstMoveWp#2] call _resolveBehaviour,
            ["linear", _firstMoveIdx]
        ];
    };

    for "_i" from 0 to (count _moveIndices - 2) do {
        private _fromIdx = _moveIndices#_i;
        private _toIdx = _moveIndices#(_i + 1);
        private _toWp = _fullWaypoints#_toIdx;
        _segments pushBack [
            +(_fullWaypoints#_fromIdx#0),
            +(_toWp#0),
            _vehicleType,
            [_toWp#2] call _resolveBehaviour,
            ["linear", _toIdx]
        ];
    };

    private _cycleIndex = _fullWaypoints findIf { (toUpper (_x#1)) == "CYCLE" };
    if (_cycleIndex >= 0 && {count _moveIndices >= 2}) then {
        private _lastMoveIdx = _moveIndices#((count _moveIndices) - 1);
        private _firstMoveIdx = _moveIndices#0;
        if (_lastMoveIdx < _cycleIndex) then {
            private _firstMoveWp = _fullWaypoints#_firstMoveIdx;
            _segments pushBack [
                +(_fullWaypoints#_lastMoveIdx#0),
                +(_firstMoveWp#0),
                _vehicleType,
                [_firstMoveWp#2] call _resolveBehaviour,
                ["cycleReturn"]
            ];
        };
    };

    if (_segments isNotEqualTo []) then {
        [_id, _segments] call FUNC(expandVehiclePath);
    };
};

{deleteVehicle _x} forEach (units _group);
{deleteVehicle _x} forEach _vehicles;
[QGVAR(deleteGroup), _group, _group] call CBA_fnc_targetEvent;
