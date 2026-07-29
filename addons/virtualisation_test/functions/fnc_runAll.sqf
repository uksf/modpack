#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Runs all virtualisation test scenarios sequentially. Returns a hashmap
        with results array and pass/fail summary, suitable for posting back
        from the dev test server.

    Parameter(s):
        None

    Return Value:
        Hashmap with keys: scenarios, passed, failed, total <HASHMAP>

    Example:
        [] call uksf_virtualisation_test_fnc_runAll
*/

private _scenarios = [
    "basic_move",
    "move_then_cycle",
    "static_no_move",
    "no_real_waypoints",
    "vehicle_road_path_basic",
    "vehicle_road_path_cycle"
];

private _results = _scenarios apply {
    [_x] call FUNC(runScenario)
};

private _passed = { _x#1 } count _results;
private _failed = (count _results) - _passed;

createHashMapFromArray [
    ["scenarios", _results],
    ["passed", _passed],
    ["failed", _failed],
    ["total", count _results]
]
