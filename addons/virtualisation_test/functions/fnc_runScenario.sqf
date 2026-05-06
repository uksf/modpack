#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs a single named scenario end-to-end: spawn, virtualise, assert
        registration matches expectation, tick sim, assert position progress
        and no [0,0,0] artefacts.

    Parameter(s):
        0: Scenario name <STRING>

    Return Value:
        [name, pass, reason] <ARRAY>

    Example:
        ['basic_move'] call uksf_virtualisation_test_fnc_runScenario
*/
params ["_name"];

private _spec = createHashMapFromArray [
    ["basic_move",        [true, 3]],
    ["move_then_cycle",   [true, 3]],
    ["static_no_move",    [false, 1]],
    ["with_origin_stub",  [true, 3]],
    ["cycle_origin",      [true, 2]]
];

private _fail = { params ["_n", "_reason"]; [_n, false, _reason] };

if (!(_name in _spec)) exitWith { [_name, "unknown scenario"] call _fail };

(_spec get _name) params ["_expectSimulated", "_expectFullWaypoints"];

([_name] call FUNC(spawnScenario)) params ["_id", "_group"];

if (_id isEqualTo "") exitWith {
    [_name, "no group id assigned (group not registered as virtualised)"] call _fail
};

private _entry = EGVAR(virtualisation,groupDataMap) get _id;
if (isNil "_entry") exitWith { [_name, "no groupDataMap entry"] call _fail };

private _fullWaypoints = _entry#8;
if (count _fullWaypoints != _expectFullWaypoints) exitWith {
    [_name, format ["fullWaypoints count %1, expected %2", count _fullWaypoints, _expectFullWaypoints]] call _fail
};

private _isSimulated = (EGVAR(virtualisation,simulatedGroupIds) findIf {_x == _id}) >= 0;
if (_isSimulated isNotEqualTo _expectSimulated) exitWith {
    [_name, format ["simulated=%1, expected %2", _isSimulated, _expectSimulated]] call _fail
};

private _originReason = [_id] call FUNC(assertNoOriginWaypoints);
if (_originReason isNotEqualTo "") exitWith { [_name, _originReason] call _fail };

if (!_isSimulated) exitWith { [_name, true, ""] };

private _startPosition = +(_entry#6#1);
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
