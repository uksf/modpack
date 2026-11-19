#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Simulates holding a decompression stop on the current gas until the ceiling clears the next shallower stop.
        Returns the stop time shortened by DECO_DIMINISH and the tissue tensions at the end of the full stop,
        which the loop applies when the shortened stop completes.

    Parameter(s):
        0: Stop depth in metres <NUMBER>

    Return Value:
        [Stop time in seconds, Nitrogen tensions, Helium tensions] <ARRAY>

    Example:
        [6] call uksf_diving_fnc_calculateStopTime
*/
params ["_stopDepth"];

private _ambientPressure = (_stopDepth / 10) + 1;
private _target = _stopDepth - STOP_INCREMENT;
private _n2 = +GVAR(saturationN2);
private _he = +GVAR(saturationHe);
private _elapsed = 0;

while {_elapsed < STOP_SIM_LIMIT && {([_n2, _he] call FUNC(calculateCeiling)) > _target}} do {
    ([_n2, _he, GVAR(currentPercentN2), GVAR(currentPercentHe), _ambientPressure, STOP_SIM_STEP] call FUNC(updateTissues)) params ["_nextN2", "_nextHe"];
    _n2 = _nextN2;
    _he = _nextHe;
    _elapsed = _elapsed + STOP_SIM_STEP;
};

[(_elapsed max STOP_SIM_STEP) / DECO_DIMINISH, _n2, _he]
