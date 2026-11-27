#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Calculates inert gas tension for a single gas in a single compartment
        using the Haldane equation over the elapsed interval at the current ambient pressure

    Parameter(s):
        0: Inspired gas fraction <NUMBER>
        1: Compartment rate constant per minute <NUMBER>
        2: Ambient pressure in bar <NUMBER>
        3: Previous tension in bar <NUMBER>
        4: Elapsed time in seconds <NUMBER>

    Return Value:
        New tension in bar <NUMBER>

    Example:
        [0.79, (ln 2) / 5, 3.9, 0.745, 1] call uksf_diving_fnc_calculateSaturation
*/
params ["_gasFraction", "_rateConstant", "_ambientPressure", "_previousTension", "_dt"];

private _inspiredPressure = _gasFraction * (_ambientPressure - WATER_VAPOUR_PRESSURE);
_inspiredPressure + (_previousTension - _inspiredPressure) * exp (-_rateConstant * _dt / 60)
