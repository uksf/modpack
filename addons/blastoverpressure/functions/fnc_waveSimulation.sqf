#include "script_component.hpp"
/*
    Author:
        Beswick.T

    Description:
        Initialises the ray-marched pressure wave simulation.
        Spawns ray particles in a sphere pattern from the detonation point.

    Parameter(s):
        0: Detonation position ASL <ARRAY>
        1: Ammo class name <STRING>
        2: indirectHit <NUMBER>
        3: indirectHitRange <NUMBER>
        4: Effective range <NUMBER>
        5: Source unit <OBJECT>

    Return Value:
        None
*/
params ["_positionASL", "_ammo", "_indirectHit", "_indirectHitRange", "_effectiveRange", "_source"];

#define RAY_COUNT 64
#define WAVE_SPEED 340
#define BOUNCE_ENERGY_FACTOR 0.5
#define MAX_BOUNCES 3
#define HIT_PROXIMITY 1.5

// Generate ray directions in a sphere using golden spiral distribution
private _rays = [];
private _goldenRatio = (1 + sqrt 5) / 2;

for "_i" from 0 to (RAY_COUNT - 1) do {
    private _theta = acos (1 - 2 * (_i + 0.5) / RAY_COUNT);
    private _phi = 360 * _i / _goldenRatio;

    private _direction = [
        sin _theta * cos _phi,
        sin _theta * sin _phi,
        cos _theta
    ];

    // Each ray: [currentPositionASL, direction, energy, bounceCount, distanceTravelled]
    _rays pushBack [_positionASL, _direction, 1.0, 0, 0];
};

// Track which units have already been hit (avoid duplicate damage)
private _hitUnits = createHashMap;

private _waveState = [
    _positionASL, _rays, _indirectHit, _effectiveRange,
    _source, _hitUnits, CBA_missionTime
];

[FUNC(waveProcessRays), 0, _waveState] call CBA_fnc_addPerFrameHandler;

#ifdef DEBUG_MODE_FULL
    diag_log text format ["[%1] Wave simulation started: %2 rays, range=%3", ADDON, RAY_COUNT, _effectiveRange];
#endif
