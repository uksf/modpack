#include "script_component.hpp"
/*
    Author:
        Tim Beswick

    Description:
        Calculates tissue saturation for a single gas in a single compartment
        using the Buhlmann/Schreiner equation (incremental per-tick form).

    Parameter(s):
        0: Gas percentage <NUMBER>
        1: Compartment index <NUMBER> (0=fast, 1=medium, 2=slow)
        2: Current ambient pressure <NUMBER>
        3: Ambient pressure delta <NUMBER> (change per second, positive = descending)
        4: Previous saturation value <NUMBER>

    Return Value:
        New saturation value <NUMBER>

    Example:
        [0.78, 0, 3.5, _delta, _previousSat] call uksf_diving_fnc_calculateSaturation
*/
params ["_gasPercent", "_compartmentIndex", "_ambientPressure", "_ambientPressureDelta", "_previousSaturation"];

if (_gasPercent <= 0) exitWith { 0 };

private _coefficient = GVAR(saturationCoefficients) select _compartmentIndex;
private _inspiredPressure = _gasPercent * (_ambientPressure - 0.0567);
private _pressureRate = _ambientPressureDelta * _gasPercent;
private _decayFactor = exp (-_coefficient / 60);

GVAR(tissueSaturationMultiplier) * (
    _inspiredPressure + (_pressureRate / _coefficient) - (_inspiredPressure - _previousSaturation + (_pressureRate / _coefficient)) * _decayFactor
)
