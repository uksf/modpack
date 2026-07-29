#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Advances a virtualised group along its waypoints based on elapsed
        time. MOVE walks _pathLinear sub-points then the user WP; CYCLE
        wraps to first MOVE and swaps _pathLinear[firstMove] to the
        cycle-return path; other types halt the sim. Mutates entry in
        place, returns the new position.

    Parameters:
        0: Virtualised group id <STRING>
        1: groupDataMap entry <ARRAY>

    Return Value:
        New position (PositionASL) <ARRAY> or nil if no advance happened

    Example:
        [_id, _entry] call uksf_virtualisation_fnc_simulateGroup
*/
params ["_id", "_entry"];

_entry params ["_side", "_vehicles", "_infantry", "_waypointsRemaining", "_combatMode", "_formationDirection",
               "_simState", "_lastSimTime", "_fullWaypoints", "_movementSpeed", "", "_pathLinear", "_pathCycleReturn"];
_simState params ["_nextIndex", "_simPosition", "_currentBehaviour", "_currentSpeedMode", "_currentSegmentSpeed",
                  "_pathPointIndex"];

if (_nextIndex < 0 || _nextIndex >= count _fullWaypoints) exitWith { nil };

private _now = CBA_missionTime;
private _budget = _now - _lastSimTime;
private _cycleSafetyCounter = 0;

while { _budget > 0 && _nextIndex >= 0 && _nextIndex < count _fullWaypoints } do {
    private _waypoint = _fullWaypoints select _nextIndex;
    _waypoint params ["_waypointPosition", "_waypointType", "_waypointBehaviour", "_waypointCombat", "_waypointSpeed", "_waypointFormation"];

    if (_waypointBehaviour == "UNCHANGED") then { _waypointBehaviour = _currentBehaviour };
    if (_waypointSpeed == "UNCHANGED") then { _waypointSpeed = _currentSpeedMode };

    switch (toUpper _waypointType) do {
        case "MOVE": {
            if (_currentSegmentSpeed <= 0) then {
                _currentSegmentSpeed = [_movementSpeed, _waypointSpeed, _waypointBehaviour] call FUNC(getSimSegmentSpeed);
            };

            private _pathPoints = _pathLinear#_nextIndex;
            private _onPath = _pathPointIndex < count _pathPoints;
            private _subTarget = if (_onPath) then { _pathPoints#_pathPointIndex } else { _waypointPosition };
            // Walk on the XY plane — path points carry terrain ASL Z while
            // _simPosition is AGL Z=0; using 3D distance burns most of the
            // step in the Z component and the post-flatten XY movement
            // collapses to a fraction of the budget.
            private _segmentVector = [(_subTarget#0) - (_simPosition#0), (_subTarget#1) - (_simPosition#1), 0];
            private _segmentDistance = vectorMagnitude _segmentVector;
            private _stepDistance = _currentSegmentSpeed * _budget;

            if (_stepDistance >= _segmentDistance) then {
                _budget = _budget - (_segmentDistance / _currentSegmentSpeed);
                _simPosition = +_subTarget;

                if (_onPath) then {
                    _pathPointIndex = _pathPointIndex + 1;
                } else {
                    _currentBehaviour = _waypointBehaviour;
                    _currentSpeedMode = _waypointSpeed;
                    _nextIndex = _nextIndex + 1;
                    _pathPointIndex = 0;
                    if (count _waypointsRemaining > 0) then { _waypointsRemaining deleteAt 0 };
                    _currentSegmentSpeed = 0;

                    if (_nextIndex < count _fullWaypoints) then {
                        private _nextWaypoint = _fullWaypoints select _nextIndex;
                        _nextWaypoint params ["", "", "_nextBehaviour", "", "_nextSpeed", ""];
                        if (_nextBehaviour == "UNCHANGED") then { _nextBehaviour = _currentBehaviour };
                        if (_nextSpeed == "UNCHANGED") then { _nextSpeed = _currentSpeedMode };
                        _currentSegmentSpeed = [_movementSpeed, _nextSpeed, _nextBehaviour] call FUNC(getSimSegmentSpeed);
                    };
                };
            } else {
                _simPosition = _simPosition vectorAdd ((vectorNormalized _segmentVector) vectorMultiply _stepDistance);
                _budget = 0;
            };
        };

        case "CYCLE": {
            _cycleSafetyCounter = _cycleSafetyCounter + 1;
            if (_cycleSafetyCounter > 2) exitWith { _budget = 0 };

            private _firstMoveIdx = _fullWaypoints findIf { (toUpper (_x#1)) == "MOVE" };
            if (_firstMoveIdx < 0) exitWith { _budget = 0 };

            if (_pathCycleReturn isNotEqualTo []) then {
                _pathLinear set [_firstMoveIdx, _pathCycleReturn];
            };

            _nextIndex = _firstMoveIdx;
            _waypointsRemaining = +_fullWaypoints;
            _currentSegmentSpeed = 0;
            _pathPointIndex = 0;
        };

        default {
            _budget = 0;
        };
    };
};

_simPosition = [_simPosition#0, _simPosition#1, 0];

_entry set [3, _waypointsRemaining];
_entry set [6, [_nextIndex, _simPosition, _currentBehaviour, _currentSpeedMode, _currentSegmentSpeed, _pathPointIndex]];
_entry set [7, _now];

TRACE_2("sim advance",_id,_simPosition);

_simPosition
