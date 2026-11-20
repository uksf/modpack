#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Simulates holding a decompression stop on the gas the diver breathes until the ceiling clears the next
        shallower stop, or STOP_SIM_LIMIT runs out. Returns the stop time shortened by DECO_DIMINISH, the tissue
        tensions at the end of the simulated stop, which the loop applies when the shortened stop completes,
        and whether the ceiling cleared the next stop.

    Parameter(s):
        0: Stop depth in metres <NUMBER>

    Return Value:
        [Stop time in seconds, Nitrogen tensions, Helium tensions, Cleared <BOOL>] <ARRAY>

    Example:
        [6] call uksf_diving_fnc_calculateStopTime
*/
params ["_stopDepth"];

private _ambientPressure = (_stopDepth / 10) + 1;
private _target = _stopDepth - STOP_INCREMENT;
private _n2 = +GVAR(saturationN2);
private _he = +GVAR(saturationHe);
private _elapsed = 0;
private _cleared = ([_n2, _he] call FUNC(calculateCeiling)) <= _target;

while {!_cleared && {_elapsed < STOP_SIM_LIMIT}} do {
    ([_n2, _he, GVAR(breathedN2), GVAR(breathedHe), _ambientPressure, STOP_SIM_STEP] call FUNC(updateTissues)) params ["_nextN2", "_nextHe"];
    _n2 = _nextN2;
    _he = _nextHe;
    _elapsed = _elapsed + STOP_SIM_STEP;
    _cleared = ([_n2, _he] call FUNC(calculateCeiling)) <= _target;
};

[(_elapsed max STOP_SIM_STEP) / DECO_DIMINISH, _n2, _he, _cleared]
