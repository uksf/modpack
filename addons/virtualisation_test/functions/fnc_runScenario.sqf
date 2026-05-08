#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs a single named scenario end-to-end: spawn, virtualise, assert
        registration matches expectation, tick sim, assert position progress
        and no [0,0,0] artefacts. For vehicle road-path scenarios, waits up
        to PATH_TIMEOUT seconds for async path expansion events and verifies
        expected expansion count + CYCLE position repurposing.

        Must run in scheduled context (uses waitUntil for vehicle scenarios).

    Parameter(s):
        0: Scenario name <STRING>

    Return Value:
        [name, pass, reason] <ARRAY>

    Example:
        ['basic_move'] call uksf_virtualisation_test_fnc_runScenario
*/
#define PATH_TIMEOUT 10

params ["_name"];

// [expectSimulated, expectInitialFullWaypointsCount, isVehicleScenario, expectedExpansionEvents]
private _spec = createHashMapFromArray [
    ["basic_move",                [true,  3, false, 0]],
    ["move_then_cycle",           [true,  3, false, 0]],
    ["static_no_move",            [false, 1, false, 0]],
    ["no_real_waypoints",         [false, 0, false, 0]],
    ["vehicle_road_path_basic",   [true,  2, true,  1]],
    ["vehicle_road_path_cycle",   [true,  3, true,  2]]
];

private _fail = { params ["_n", "_reason"]; [_n, false, _reason] };

if (!(_name in _spec)) exitWith { [_name, "unknown scenario"] call _fail };

(_spec get _name) params ["_expectSimulated", "_expectFullWaypoints", "_isVehicleScenario", "_expectedEvents"];

GVAR(pathEventsByGroup) = createHashMap;

([_name] call FUNC(spawnScenario)) params ["_id", "_group", "_initialFullWaypointsCount"];

if (_id isEqualTo "") exitWith {
    [_name, "no group id assigned (group not registered as virtualised)"] call _fail
};

if (_initialFullWaypointsCount != _expectFullWaypoints) exitWith {
    [_name, format ["initial fullWaypoints count %1, expected %2", _initialFullWaypointsCount, _expectFullWaypoints]] call _fail
};

private _entry = EGVAR(virtualisation,groupDataMap) get _id;
if (isNil "_entry") exitWith { [_name, "no groupDataMap entry"] call _fail };

private _fullWaypoints = _entry#8;

private _isSimulated = (EGVAR(virtualisation,simulatedGroupIds) findIf {_x == _id}) >= 0;
if (_isSimulated isNotEqualTo _expectSimulated) exitWith {
    [_name, format ["simulated=%1, expected %2", _isSimulated, _expectSimulated]] call _fail
};

private _originReason = [_id] call FUNC(assertNoOriginWaypoints);
if (_originReason isNotEqualTo "") exitWith { [_name, _originReason] call _fail };

if (_isVehicleScenario) then {
    private _firstWpPos = +(_fullWaypoints#0#0);

    if (_name == "vehicle_road_path_cycle") then {
        private _cycleIndex = _fullWaypoints findIf { (toUpper (_x#1)) == "CYCLE" };
        if (_cycleIndex < 0) then {
            [_name, "no CYCLE entry found"] call _fail
        };
        private _cyclePos = _fullWaypoints#_cycleIndex#0;
        if (_cyclePos isNotEqualTo _firstWpPos) then {
            [_name, format ["CYCLE position %1 not repurposed to first WP %2", _cyclePos, _firstWpPos]] call _fail
        };
    };

    private _deadline = CBA_missionTime + PATH_TIMEOUT;
    waitUntil {
        private _events = GVAR(pathEventsByGroup) getOrDefault [_id, []];
        (count _events >= _expectedEvents) || (CBA_missionTime > _deadline)
    };

    private _events = GVAR(pathEventsByGroup) getOrDefault [_id, []];
    if (count _events < _expectedEvents) exitWith {
        [_name, format ["only %1 path events received within %2s, expected %3 — events: %4", count _events, PATH_TIMEOUT, _expectedEvents, _events]] call _fail
    };
    if (count _events != _expectedEvents) exitWith {
        [_name, format ["got %1 events, expected exactly %2 — events: %3", count _events, _expectedEvents, _events]] call _fail
    };
};

if (!_isSimulated) exitWith { [_name, true, ""] };

private _entryPostExpansion = EGVAR(virtualisation,groupDataMap) get _id;
if (isNil "_entryPostExpansion") exitWith { [_name, "groupDataMap entry vanished post-expansion"] call _fail };

private _startPosition = +(_entryPostExpansion#6#1);
[_id, 5] call FUNC(tickSim);

private _entryAfter = EGVAR(virtualisation,groupDataMap) get _id;
private _endPosition = _entryAfter#6#1;

if (_endPosition isEqualTo [0,0,0]) exitWith {
    [_name, "post-sim simState position is [0,0,0]"] call _fail
};

private _originReasonPostSim = [_id] call FUNC(assertNoOriginWaypoints);
if (_originReasonPostSim isNotEqualTo "") exitWith {
    [_name, format ["post-sim: %1", _originReasonPostSim]] call _fail
};

if (_startPosition isEqualTo _endPosition) exitWith {
    [_name, format ["sim did not advance position from %1", _startPosition]] call _fail
};

[_name, true, ""]
