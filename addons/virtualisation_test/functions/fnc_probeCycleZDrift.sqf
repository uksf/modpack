#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Probes whether addWaypoint radius alone causes CYCLE Z drift.
        Result was negative — the real cause is feeding ASL into a CYCLE
        WP that expects AGL. Kept as a regression check that radius
        itself doesn't drift Z.

    Parameter(s):
        0: Sample count <NUMBER> (Optional, default 10)

    Return Value:
        [pass, reason, stats] <ARRAY>

    Example:
        [10] call uksf_virtualisation_test_fnc_probeCycleZDrift
*/
#define ANCHOR_POS [16000, 12500, 0]
#define DRIFT_THRESHOLD 0.05

params [["_sampleCount", 10]];

private _sample = {
    params ["_radius"];
    private _group = createGroup [east, true];
    _group createUnit ["B_Soldier_F", ANCHOR_POS, [], 0, "NONE"];
    private _wp = _group addWaypoint [ANCHOR_POS, _radius];
    _wp setWaypointType "CYCLE";
    private _agl = waypointPosition _wp;
    deleteGroup _group;
    _agl#2
};

private _zeroRadiusSamples = [];
private _patrolRadiusSamples = [];

for "_i" from 1 to _sampleCount do {
    _zeroRadiusSamples pushBack ([0] call _sample);
    _patrolRadiusSamples pushBack ([100] call _sample);
};

private _absMax = {
    params ["_samples"];
    private _max = 0;
    { if (abs _x > _max) then { _max = abs _x } } forEach _samples;
    _max
};

private _zeroMax = [_zeroRadiusSamples] call _absMax;
private _patrolMax = [_patrolRadiusSamples] call _absMax;

private _stats = createHashMapFromArray [
    ["zero_radius_samples", _zeroRadiusSamples],
    ["zero_radius_max_abs_z", _zeroMax],
    ["patrol_radius_samples", _patrolRadiusSamples],
    ["patrol_radius_max_abs_z", _patrolMax]
];

if (_zeroMax > DRIFT_THRESHOLD) exitWith {
    [false, format ["radius=0 already drifted Z up to %1m, suspect engine snap not the radius", _zeroMax], _stats]
};

if (_patrolMax <= DRIFT_THRESHOLD) exitWith {
    [false, format ["radius=100 stayed within %1m — bug not reproduced (try a different anchor with steeper terrain)", DRIFT_THRESHOLD], _stats]
};

[true, format ["confirmed: radius=100 drifted Z up to %1m, radius=0 stayed within %2m", _patrolMax, _zeroMax], _stats]
