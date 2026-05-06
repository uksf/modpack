#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Synchronously spawns a deterministic AI group + waypoints for a named
        scenario, then virtualises it. Returns the synthesised group id used
        to look up state in uksf_virtualisation_groupDataMap.

    Scenarios:
        basic_move          3 MOVE waypoints, real positions
        move_then_cycle     2 MOVE + 1 CYCLE at non-origin pos
        static_no_move      single HOLD waypoint (should NOT be sim eligible)
        with_origin_stub    auto-stub WP0 [0,0,0] + 3 MOVE — stub must filter
        cycle_origin        2 MOVE + 1 CYCLE at [0,0,0] — bad CYCLE must filter

    Parameter(s):
        0: Scenario name <STRING>

    Return Value:
        [groupId, group] — both populated <ARRAY>

    Example:
        ['basic_move'] call uksf_virtualisation_test_fnc_spawnScenario
*/
params ["_scenarioName"];

private _scenarioOffsets = createHashMapFromArray [
    ["basic_move",       [0, 0]],
    ["move_then_cycle",  [1000, 0]],
    ["static_no_move",   [2000, 0]],
    ["with_origin_stub", [3000, 0]],
    ["cycle_origin",     [4000, 0]]
];
private _offset = _scenarioOffsets getOrDefault [_scenarioName, [0, 0]];

private _baseDefault = TEST_BASE_POS;
private _base = [_baseDefault#0 + _offset#0, _baseDefault#1 + _offset#1, 0];

private _group = createGroup [east, true];
_group setBehaviour "SAFE";
_group setVariable [QEGVAR(virtualisation,excluded), false];

private _unit = _group createUnit [TEST_UNIT_CLASS, _base, [], 0, "NONE"];
_unit setPosATL _base;

// Clear any engine-created implicit waypoints so scenarios start with a clean slate.
while { waypoints _group isNotEqualTo [] } do {
    deleteWaypoint ((waypoints _group)#0);
};

private _addWp = {
    params ["_position", "_type"];
    private _waypoint = _group addWaypoint [_position, 0];
    _waypoint setWaypointType _type;
    _waypoint setWaypointSpeed "NORMAL";
    _waypoint setWaypointBehaviour "SAFE";
    _waypoint
};

switch (_scenarioName) do {
    case "basic_move": {
        [[_base#0 + 100, _base#1, 0], "MOVE"] call _addWp;
        [[_base#0 + 200, _base#1 + 100, 0], "MOVE"] call _addWp;
        [[_base#0 + 300, _base#1 + 200, 0], "MOVE"] call _addWp;
    };
    case "move_then_cycle": {
        [[_base#0 + 100, _base#1, 0], "MOVE"] call _addWp;
        [[_base#0 + 200, _base#1 + 100, 0], "MOVE"] call _addWp;
        [[_base#0 + 50, _base#1 + 50, 0], "CYCLE"] call _addWp;
    };
    case "static_no_move": {
        [_base, "HOLD"] call _addWp;
    };
    case "with_origin_stub": {
        // Explicit [0,0,0] WP0 (simulating a waypoint whose attached object
        // was deleted, leaving the engine to report position [0,0,0]).
        private _stub = _group addWaypoint [[0,0,0], 0];
        _stub setWaypointType "MOVE";
        [[_base#0 + 100, _base#1, 0], "MOVE"] call _addWp;
        [[_base#0 + 200, _base#1 + 100, 0], "MOVE"] call _addWp;
        [[_base#0 + 300, _base#1 + 200, 0], "MOVE"] call _addWp;
    };
    case "cycle_origin": {
        [[_base#0 + 100, _base#1, 0], "MOVE"] call _addWp;
        [[_base#0 + 200, _base#1 + 100, 0], "MOVE"] call _addWp;
        // CYCLE waypoint added with explicit [0,0,0] — must be filtered.
        private _badCycle = _group addWaypoint [[0,0,0], 0];
        _badCycle setWaypointType "CYCLE";
    };
    default {
        ERROR_1("Unknown scenario %1",_scenarioName);
    };
};

private _idsBefore = +EGVAR(virtualisation,groupPositionMap) apply {_x#0};
[_group] call EFUNC(virtualisation,virtualiseGroup);
private _idsAfter = EGVAR(virtualisation,groupPositionMap) apply {_x#0};
private _newIds = _idsAfter select {!(_x in _idsBefore)};

private _groupId = if (_newIds isNotEqualTo []) then { _newIds#0 } else { "" };

[_groupId, _group]
