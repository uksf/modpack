#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Synchronously spawns a deterministic AI group + waypoints for a named
        scenario, then virtualises it. Returns the synthesised group id used
        to look up state in uksf_virtualisation_groupDataMap.

    Scenarios:
        basic_move                 3 MOVE waypoints, real positions
        move_then_cycle            2 MOVE + 1 CYCLE
        static_no_move             single HOLD waypoint (should NOT be sim eligible)
        no_real_waypoints          only engine auto-stub
        vehicle_road_path_basic    wheeled vehicle, 2 MOVE WPs ~600m apart
        vehicle_road_path_cycle    wheeled vehicle, 2 MOVE + CYCLE

    Parameter(s):
        0: Scenario name <STRING>

    Return Value:
        [groupId, group] — both populated <ARRAY>

    Example:
        ['basic_move'] call uksf_virtualisation_test_fnc_spawnScenario
*/
params ["_scenarioName"];

private _scenarioOffsets = createHashMapFromArray [
    ["basic_move",                [0, 0]],
    ["move_then_cycle",           [1000, 0]],
    ["static_no_move",            [2000, 0]],
    ["no_real_waypoints",         [3000, 0]],
    ["vehicle_road_path_basic",   [0, 0]],
    ["vehicle_road_path_cycle",   [300, 0]]
];
private _offset = _scenarioOffsets getOrDefault [_scenarioName, [0, 0]];

// Vehicle scenarios need a road-having base on the live terrain. On VR
// nearestRoad returns objNull and we fall through to TEST_BASE_POS.
// Anchor near Pyrgos on Altis (mainland, dense road network).
private _isVehicleScenario = _scenarioName in ["vehicle_road_path_basic", "vehicle_road_path_cycle"];
private _baseDefault = if (_isVehicleScenario) then {
    private _anchor = [16000, 12500, 0];
    private _road = [_anchor, 200, []] call BIS_fnc_nearestRoad;
    if (isNil "_road" || {isNull _road}) then { _anchor } else { getPosATL _road }
} else {
    TEST_BASE_POS
};
private _base = [_baseDefault#0 + _offset#0, _baseDefault#1 + _offset#1, 0];

private _group = createGroup [east, true];
_group setBehaviour "SAFE";
_group setVariable [QEGVAR(virtualisation,excluded), false];

private _unit = _group createUnit [TEST_UNIT_CLASS, _base, [], 0, "NONE"];
_unit setPosATL _base;

if (_scenarioName == "vehicle_road_path_basic" || _scenarioName == "vehicle_road_path_cycle") then {
    private _vehicle = createVehicle ["B_MRAP_01_F", _base, [], 0, "NONE"];
    _vehicle setPosATL _base;
    _unit moveInDriver _vehicle;
    _group addVehicle _vehicle;
};

// Engine creates a stub waypoint at index 0; production code drops index 0,
// so we leave it in place and add real waypoints at indices >= 1.

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
    case "no_real_waypoints": {
        // No explicit waypoints — only the engine auto-stub at index 0
        // exists. Filter must drop it; group must not be simulated.
    };
    case "vehicle_road_path_basic": {
        [[_base#0 + 600, _base#1, 0], "MOVE"] call _addWp;
        [[_base#0 + 1200, _base#1 + 400, 0], "MOVE"] call _addWp;
    };
    case "vehicle_road_path_cycle": {
        [[_base#0 + 600, _base#1, 0], "MOVE"] call _addWp;
        [[_base#0 + 1200, _base#1 + 400, 0], "MOVE"] call _addWp;
        [[_base#0 + 50, _base#1 + 50, 0], "CYCLE"] call _addWp;
    };
    default {
        ERROR_1("Unknown scenario %1",_scenarioName);
    };
};

private _idsBefore = +EGVAR(virtualisation,groupPositionMap) apply {_x#0};

// Force unscheduled context for virtualiseGroup; calculatePath agents fired
// in expandVehiclePath die between commands if a scheduled yield happens
// before EH registration. Production triggers virtualiseGroup from a PFH
// (unscheduled), so directCall here matches that environment. We also
// capture the initial fullWaypoints count inside the unscheduled block,
// before any PathCalculated EH can fire and splice intermediate points.
private _initialCount = -1;
[{
    params ["_group", "_idsBefore"];
    [_group] call EFUNC(virtualisation,virtualiseGroup);
    private _newIds = (EGVAR(virtualisation,groupPositionMap) apply {_x#0}) select {!(_x in _idsBefore)};
    if (_newIds isNotEqualTo []) then {
        private _id = _newIds#0;
        private _entry = EGVAR(virtualisation,groupDataMap) get _id;
        if (!isNil "_entry") then {
            uksf_virtualisation_test_lastSpawnId = _id;
            uksf_virtualisation_test_lastSpawnInitialCount = count (_entry#8);
        };
    } else {
        uksf_virtualisation_test_lastSpawnId = "";
        uksf_virtualisation_test_lastSpawnInitialCount = -1;
    };
}, [_group, _idsBefore]] call CBA_fnc_directCall;

private _groupId = uksf_virtualisation_test_lastSpawnId;

[_groupId, _group, uksf_virtualisation_test_lastSpawnInitialCount]
