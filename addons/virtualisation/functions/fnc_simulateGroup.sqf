#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Advances a single virtualised group along its waypoints based on real
        elapsed time since its last sim tick. Handles MOVE (interpolate position),
        CYCLE (reset to first waypoint, refill remaining waypoint list), and
        non-MOVE/non-CYCLE waypoint types (halt sim — engine resolves on recreate).
        Mutates the data map entry in place. Returns the new position so the
        orchestrator can update groupPositionMap.

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
               "_simState", "_lastSimTime", "_fullWaypoints", "_movementSpeed"];
_simState params ["_nextIndex", "_simPosition", "_currentBehaviour", "_currentSpeedMode", "_currentSegmentSpeed"];

if (_nextIndex < 0 || _nextIndex >= count _fullWaypoints) exitWith { nil };

private _now = diag_tickTime;
private _delta = _now - _lastSimTime;
if (_delta < SIM_INTERVAL) exitWith { nil };

private _budget = _delta;
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

            private _segmentVector = _waypointPosition vectorDiff _simPosition;
            private _segmentDistance = vectorMagnitude _segmentVector;
            private _stepDistance = _currentSegmentSpeed * _budget;

            if (_stepDistance >= _segmentDistance) then {
                _budget = _budget - (_segmentDistance / _currentSegmentSpeed);
                _simPosition = +_waypointPosition;
                _currentBehaviour = _waypointBehaviour;
                _currentSpeedMode = _waypointSpeed;
                _nextIndex = _nextIndex + 1;
                if (count _waypointsRemaining > 0) then { _waypointsRemaining deleteAt 0 };

                if (_nextIndex < count _fullWaypoints) then {
                    private _nextWaypoint = _fullWaypoints select _nextIndex;
                    _nextWaypoint params ["", "", "_nextBehaviour", "", "_nextSpeed", ""];
                    if (_nextBehaviour == "UNCHANGED") then { _nextBehaviour = _currentBehaviour };
                    if (_nextSpeed == "UNCHANGED") then { _nextSpeed = _currentSpeedMode };
                    _currentSegmentSpeed = [_movementSpeed, _nextSpeed, _nextBehaviour] call FUNC(getSimSegmentSpeed);
                };
            } else {
                _simPosition = _simPosition vectorAdd ((vectorNormalized _segmentVector) vectorMultiply _stepDistance);
                _budget = 0;
            };
        };

        case "CYCLE": {
            _cycleSafetyCounter = _cycleSafetyCounter + 1;
            if (_cycleSafetyCounter > 2) exitWith { _budget = 0 };
            _nextIndex = 0;
            _waypointsRemaining = +_fullWaypoints;
            _currentSegmentSpeed = 0;
        };

        default {
            _budget = 0;
        };
    };
};

_simPosition = [_simPosition#0, _simPosition#1, 0];

_entry set [3, _waypointsRemaining];
_entry set [6, [_nextIndex, _simPosition, _currentBehaviour, _currentSpeedMode, _currentSegmentSpeed]];
_entry set [7, _now];

TRACE_2("sim advance",_id,_simPosition);

_simPosition
