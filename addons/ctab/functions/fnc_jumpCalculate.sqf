#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Calculates the jump plan for the drop zone and updates the planner panel.
        The rates are measured in Arma for the steerable parachute: free fall reaches about 67 m/s, the canopy sinks at 3 m/s and flies at 4.4 m/s.
        The canopy drifts with the full wind. Free fall drifts with about a tenth of the wind.
        HALO: the jumper opens upwind of the drop zone by the canopy drift, so an unsteered canopy lands on it.
        HAHO: the jumper opens near the exit and flies the canopy on the chosen track, keeping a fifth of the glide range spare.

    Parameter(s):
        None

    Return Value:
        Nothing

    Example:
        call uksf_ctab_fnc_jumpCalculate
*/
GVAR(jumpPlan) = [];

if (GVAR(jumpZone) isEqualTo []) exitWith {
    [APP_CTRL(jumpInfo), ["Click the map to set the drop zone."]] call FUNC(setInfo);
};

private _ground = getTerrainHeightASL GVAR(jumpZone);
private _opening = _ground + GVAR(jumpOpening);
private _release = GVAR(jumpRelease) max (_opening + 100);
private _windVector = [wind select 0, wind select 1, 0];
private _windSpeed = vectorMagnitude _windVector;

private _fallHeight = _release - _opening;
private _fallTime = JUMP_FALL_START_TIME + (0 max (_fallHeight - JUMP_FALL_START_HEIGHT)) / JUMP_FALL_SPEED;
private _canopyTime = (_opening - _ground) / JUMP_CANOPY_SINK;
private _glide = _canopyTime * JUMP_CANOPY_SPEED;
private _zone = [GVAR(jumpZone) select 0, GVAR(jumpZone) select 1, 0];

private _track = if (GVAR(jumpHeading) < 0) then {
    [_windVector, [0, 1, 0]] select (_windSpeed < 0.5)
} else {
    [sin GVAR(jumpHeading), cos GVAR(jumpHeading), 0]
};
_track = vectorNormalized _track;

private _openPoint = if (GVAR(jumpMode) == "HALO") then {
    _zone vectorDiff (_windVector vectorMultiply _canopyTime)
} else {
    _zone vectorDiff (_windVector vectorMultiply _canopyTime) vectorDiff (_track vectorMultiply (_glide * JUMP_GLIDE_USED))
};
private _releasePoint = _openPoint vectorDiff (_windVector vectorMultiply (_fallTime * JUMP_FALL_WIND_SHARE));

GVAR(jumpPlan) = [_releasePoint, _openPoint, _glide];

private _lines = [
    format ["Drop zone: %1", [_zone] call ctab_core_fnc_gridPosition],
    format ["Release: %1, %2 m ASL", [_releasePoint] call ctab_core_fnc_gridPosition, round _release],
    format ["Open: %1 m above the drop zone", round GVAR(jumpOpening)],
    format ["Free fall: %1, canopy: %2", _fallTime call FUNC(formatDuration), _canopyTime call FUNC(formatDuration)],
    format ["Canopy glide in still air: %1", _glide call FUNC(formatDistance)],
    format ["Wind: %1 m/s from %2", _windSpeed toFixed 1, round ((((-(_windVector select 0)) atan2 (-(_windVector select 1))) + 360) mod 360)]
];
if (_release >= JUMP_OXYGEN_ALTITUDE) then {
    _lines pushBack format ["<t color='#ff8000'>Oxygen required from %1 m ASL</t>", JUMP_OXYGEN_ALTITUDE];
};
[APP_CTRL(jumpInfo), _lines] call FUNC(setInfo);
